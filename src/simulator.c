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
}
