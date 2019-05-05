#include "../include/simulator.h"

void init_simulator() {
  int i;

  for(i = 0; i < 4096; i++) {
    memory[i] = 0;
  }

  pc = 0x00000000;
  ri = 0x00000000;

  for(i = 0; i < 32; i++) {
    breg[i] = 0;
  }
  
  breg[sp] = 0x00003FFC;
  breg[gp] = 0x00001800;
}

void read_mem(int32_t* mem, char filename[]) {
  FILE *fp = fopen(filename, "rb");
  if(fp == NULL) {
    printf("Problema ao ler arquivo binário\n");
  }

  int i = 0;
  int32_t instruction;

  while(!feof(fp)) {
    fread(&instruction, sizeof(int32_t), 1, fp);
    mem[i] = instruction;
    i++;
  }

  fclose(fp);
}

void load_data() {
  int i;

  for(i = 0; i <= (DATA_END - DATA_INIT + 1); i++) {
    memory[(i + DATA_INIT) >> 2] = data_mem[i >> 2];
  }
}

void fetch() {
  ri = memory[pc >> 2];
  pc += 4;
}


void decode() {
  int32_t temp; /* valor temporário para imediatos */

  /* extraindo o opcode */
  opcode = getField(ri, 0, 0x7F);

  /* extraindo rs1 */
  rs1 = getField(ri, 15, 0x1F);

  /* extraindo rs2 e shamt*/
  rs2 = getField(ri, 20, 0x1F);
  shamt = rs2;

  /* extraindo rd */
  rd = getField(ri, 7, 0x1F);

  /* extraindo funct3 */
  funct3 = getField(ri, 12, 0x7);

  /* extraindo funct7 */
  funct7 = getField(ri, 25, 0x7F);

  /* extraindo imm12_i */
  imm12_i = getField(ri, 20, 0xFFF);
  if(imm12_i & 0x800) {
    imm12_i += 0xFFFFF000;
  }

  /* extraindo imm12_s */
  imm12_s = getField(ri, 7, 0x1F); /* bits 7-11 de ri */
  temp = getField(ri, 25, 0x7F);   /* bits 25-31 de ri */
  imm12_s = setField(imm12_s, 5, 0x7F, temp);
  if(imm12_s & 0x800) {
    imm12_s += 0xFFFFF000;
  }

  /* extraindo imm13 */
  imm13 = 0;
  temp = getField(ri, 8, 0xF); /* bits 1-4 do imediato */
  imm13 = setField(imm13, 1, 0xF, temp);
  temp = getField(ri, 25, 0x3F); /* bits 5-10 do imediato */
  imm13 = setField(imm13, 5, 0x3F, temp);
  temp = getField(ri, 7, 1); /* bit 11 do imediato */
  imm13 = setField(imm13, 11, 1, temp);
  temp = getField(ri, 31, 1); /* bit 12 do imediato */
  imm13 = setField(imm13, 12, 1, temp);
  if(imm13 & 0x1000) {
    imm13 += 0xFFFFE000;
  }

  /* extraindo imm21 */
  imm21 = 0;
  temp = getField(ri, 21, 0x3FF); /* bits 1-10 do imediato */
  imm21 = setField(imm21, 1, 0x3FF, temp);
  temp = getField(ri, 20, 1); /* bit 11 do imediato */
  imm21 = setField(imm21, 11, 1, temp);
  temp = getField(ri, 12, 0xFF); /* bits 12-19 do imediato */
  imm21 = setField(imm21, 12, 0xFF, temp);
  temp = getField(ri, 31, 1); /* bit 20 do imediato */
  imm21 = setField(imm21, 20, 1, temp);
  if(imm21 & 0x100000) {
    imm21 += 0xFFE00000;
  }

  /* extraindo imm20_u */
  imm20_u = 0;
  temp = getField(ri, 12, 0xFFFFF);
  imm20_u = setField(imm20_u, 12, 0xFFFFF, temp);
}

void execute() {
  int32_t pca = pc - 4;
  switch(opcode) {
  case LUI: /* 20 bits mais significativos */
    breg[rd] = imm20_u;
    break;

  case JAL: /* jump e salva o pc */
    breg[rd] = pc;
    pc = pca + imm21;
    break;

  case BType: /* branches */
    switch(funct3) {
    case BEQ3:
      if(breg[rs1] == breg[rs2]) {
	pc = pca + imm13;
      } /* if */
      break;
    } /* switch(funct3) */
    break;

  case ILType: /* load */
    switch(funct3) {
    case LB3: /* carregar byte com sinal */
      breg[rd] = lb(memory, breg[rs1] + imm12_i);
      break;
    }
    break;

  case StoreType:
    switch(funct3) {
    case SB3:
      sb(memory, breg[rs1] + imm12_s, breg[rs2]);
      break;
    }
    break;

  case ILAType:
    switch(funct3) {
    case ADDI3:
      breg[rd] = breg[rs1] + imm12_i;
      break;
    }
    break;

  case RegType:
    switch(funct3) {
    case ADDSUB3:
      switch(funct7) {
      case ADD7:
	breg[rd] = breg[rs1] + breg[rs2];
	break;
      } /* switch(funct7) */
      break;
    }	/* switch(funct3) */
    break;
  } /* switch(opcode) */
}
