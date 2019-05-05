#include "../include/test_simulator.h"

/* declarações de de testes */
char test1[] = "tests/test1_text.bin";
char test_lui[] = "tests/tst_lui_text.bin";
char test_jal[] = "tests/tst_jal_text.bin";
char test_beq[] = "tests/tst_beq_text.bin";
char test_lb_txt[] = "tests/tst_lb_text.bin";
char test_lb_dt[] = "tests/tst_lb_data.bin";
char test_sb_txt[] = "tests/tst_sb_text.bin";
char test_addi_txt[] = "tests/tst_addi_text.bin";
char test_add_txt[] = "tests/tst_add_text.bin";
char test_auipc_txt[] = "tests/tst_auipc_text.bin";
char test_jalr_txt[] = "tests/tst_jalr_text.bin";
char test_slti_txt[] = "tests/tst_slti_text.bin";
char test_sltiu_txt[] = "tests/tst_sltiu_text.bin";
char test_slli_txt[] = "tests/tst_slli_text.bin";
char test_srli_txt[] = "tests/tst_srli_text.bin";
char test_srai_txt[] = "tests/tst_srai_text.bin";

int test_read_mem() {
  int errors = 0;
  read_mem(mem, test1);

  if(mem[0] != 0x600513) {
    errors++;
  }
  if(mem[1] != 0x100893) {
    errors++;
  }
  if(mem[2] != 0x73) {
    errors++;
  }
  if(mem[3] != 0xA00893) {
    errors++;
  }
  if(mem[4] != 0x73) {
    errors++;
  }

  return errors;
}

int test_fetch() {
  int errors = 0;
  init_simulator();
  read_mem(memory, test1);

  fetch();
  if(ri != 0x600513 || pc != 4) {
    errors++;
  }

  fetch();
  if(ri != 0x100893 || pc != 8) {
    errors++;
  }

  fetch();
  if(ri != 0x73 || pc != 12) {
    errors++;
  }

  fetch();
  if(ri != 0xA00893 || pc != 16) {
    errors++;
  }

  fetch();
  if(ri != 0x73 || pc != 20) {
    errors++;
  }

  return errors;
}

int test_decode() {
  init_simulator();
  read_mem(memory, test1);
  int errors = 0;

  /* primeira instrução */
  fetch();
  decode();
  if(opcode != 0x13) {
    errors++;
  }
  if(rs1 != 0) {
    errors++;
  }
  if(rs2 != 6) {
    errors++;
  }
  if(rd != 10) {
    errors++;
  }
  if(funct3 != 0) {
    errors++;
  }
  if(funct7 != 0) {
    errors++;
  }
  if(imm12_i != 6) {
    errors++;
  }
  if(imm12_s != 10) {
    errors++;
  }
  if(imm13 != 10) {
    errors++;
  }
  if(imm21 != 6) {
    errors++;
  }
  if(imm20_u != 0x600000) {
    errors++;
  }

  /* segunda */
  fetch();
  decode();
  if(opcode != 0x13) {
    errors++;
  }
  if(rs1 != 0) {
    errors++;
  }
  if(rs2 != 1) {
    errors++;
  }
  if(rd != 0x11) {
    errors++;
  }
  if(funct3 != 0) {
    errors++;
  }
  if(funct7 != 0) {
    errors++;
  }
  if(imm12_i != 1) {
    errors++;
  }
  if(imm12_s != 0x11) {
    errors++;
  }
  if(imm13 != 0x810) {
    errors++;
  }
  if(imm21 != 0x800) {
    errors++;
  }
  if(imm20_u != 0x100000) {
    errors++;
  }

  /* terceira */
  fetch();
  decode();
  if(opcode != 0x73) {
    errors++;
  }
  if(rs1 != 0) {
    errors++;
  }
  if(rs2 != 0) {
    errors++;
  }
  if(rd != 0) {
    errors++;
  }
  if(funct3 != 0) {
    errors++;
  }
  if(funct7 != 0) {
    errors++;
  }
  if(imm12_i != 0) {
    errors++;
  }
  if(imm12_s != 0) {
    errors++;
  }
  if(imm13 != 0) {
    errors++;
  }
  if(imm21 != 0) {
    errors++;
  }
  if(imm20_u != 00) {
    errors++;
  }

  /* quarta */
  fetch();
  decode();
  if(opcode != 0x13) {
    errors++;
  }
  if(rs1 != 0) {
    errors++;
  }
  if(rs2 != 10) {
    errors++;
  }
  if(rd != 0x11) {
    errors++;
  }
  if(funct3 != 0) {
    errors++;
  }
  if(funct7 != 0) {
    errors++;
  }
  if(imm12_i != 0xA) {
    errors++;
  }
  if(imm12_s != 0x11) {
    errors++;
  }
  if(imm13 != 0x810) {
    errors++;
  }
  if(imm21 != 10) {
    errors++;
  }
  if(imm20_u != 0xA00000) {
    errors++;
  }

  /* quinta */
  fetch();
  decode();
  if(opcode != 0x73) {
    errors++;
  }
  if(rs1 != 0) {
    errors++;
  }
  if(rs2 != 0) {
    errors++;
  }
  if(rd != 0) {
    errors++;
  }
  if(funct3 != 0) {
    errors++;
  }
  if(funct7 != 0) {
    errors++;
  }
  if(imm12_i != 0) {
    errors++;
  }
  if(imm12_s != 0) {
    errors++;
  }
  if(imm13 != 0) {
    errors++;
  }
  if(imm21 != 0) {
    errors++;
  }
  if(imm20_u != 0) {
    errors++;
  }

  return errors;
}

int test_exe_lui() {
  init_simulator();
  read_mem(memory, test_lui);
  int errors = 0;

  fetch();
  decode();
  execute();
  if(breg[t0] != 0xABCD000) {
    errors++;
  }

  return errors;
}

int test_exe_jal() {
  init_simulator();
  read_mem(memory, test_jal);
  int errors = 0;

  fetch();
  fetch();
  fetch();
  decode();
  execute();
  if(pc != 4) {
    errors++;
  }
  if(breg[t1] != 0xC) {
    errors++;
  }

  return errors;
}

int test_exe_beq() {
  init_simulator();
  read_mem(memory, test_beq);
  int errors = 0;

  fetch();
  fetch();
  decode();
  execute();
  if(pc != 0) {
    errors++;
  }

  return errors;
}

int test_exe_lb() {
  init_simulator();
  read_mem(data_mem, test_lb_dt);
  read_mem(memory, test_lb_txt);
  load_data();
  int errors = 0;

  fetch();
  fetch();
  fetch();
  decode();
  breg[t0] = 0x2000;
  execute();
  if(breg[t1] != 0xFFFFFFA0) {
    errors++;
  }

  return errors;
}

int test_exe_sb() {
  init_simulator();
  read_mem(memory, test_sb_txt);
  int errors = 0;

  fetch();
  fetch();
  fetch();
  fetch();
  decode();
  breg[t0] = 0x2001;
  breg[t1] = 0xEF;
  execute();
  if(memory[0x2000 >> 2] != 0xEF) {
    errors++;
  }

  return errors;
}

int test_exe_addi() {
  init_simulator();
  read_mem(memory, test_addi_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  breg[t0] = 5;
  execute();
  if(breg[t1] != 3) {
    errors++;
  }

  return errors;
}

int test_exe_add() {
  init_simulator();
  read_mem(memory, test_add_txt);
  int errors = 0;

  fetch();
  fetch();
  fetch();
  decode();
  breg[t0] = -4;
  breg[t1] = 9;
  execute();
  if(breg[t2] != 5) {
    errors++;
  }

  return errors;
}

int test_exe_auipc() {
  init_simulator();
  read_mem(memory, test_auipc_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  execute();
  if(breg[t1] != 0xABC004) {
    errors++;
  }

  return errors;
}

int test_exe_jalr() {
  init_simulator();
  read_mem(memory, test_jalr_txt);
  int errors = 0;

  /* operação auipc */
  fetch();
  decode();
  execute();
  /* operação jalr */
  fetch();
  decode();
  execute();
  if(breg[ra] != 8 || pc != 8) {
    errors++;
  }
  /* operação nop */
  fetch();
  /* operação jalr */
  fetch();
  decode();
  execute();
  if(pc != 8) {
    errors++;
  }

 return errors;
}

int test_exe_slti() {
  init_simulator();
  read_mem(memory, test_slti_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  breg[t0] = 5;
  execute();
  if(breg[t1] != 1) {
    errors++;
  }

  return errors;
}

int test_exe_sltiu() {
  init_simulator();
  read_mem(memory, test_sltiu_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  breg[t0] = 5;
  execute();
  if(breg[t1] != 1) {
    errors++;
  }

  return errors;
}

int test_exe_slli() {
  init_simulator();
  read_mem(memory, test_slli_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  breg[t0] = 0xF;
  execute();
  if(breg[t1] != 0xF0) {
    errors++;
  }

  return errors;
}

int test_exe_srli() {
  init_simulator();
  read_mem(memory, test_srli_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  breg[t0] = -1;
  execute();
  if(breg[t1] != 0x0FFFFFFF) {
    errors++;
  }

  return errors;
}

int test_exe_srai() {
  init_simulator();
  read_mem(memory, test_srai_txt);
  int errors = 0;

  fetch();
  fetch();
  decode();
  breg[t0] = -1;
  execute();
  if(breg[t1] != -1) {
    errors++;
  }

  return errors;
}

void run_simulator_tests() {
  int errors;
  errors = test_read_mem();
  if(errors > 0) {
    printf("read_mem()   -> %d erros\n", errors);
  }
  else {
    printf("read_mem()   -> passou nos testes\n");
  }

  errors = test_fetch();
  if(errors > 0) {
    printf("fetch()      -> %d erros\n", errors);
  }
  else {
    printf("fetch()      -> passou nos testes\n");
  }

  errors = test_decode();
  if(errors > 0) {
    printf("decode()     -> %d erros\n", errors);
  }
  else {
    printf("decode()     -> passou nos testes\n");
  }

  errors = test_exe_lui();
  if(errors > 0) {
    printf("exe_lui()    -> %d erros\n", errors);
  }
  else {
    printf("exe_lui()    -> passou nos testes\n");
  }

  errors = test_exe_jal();
  if(errors > 0) {
    printf("exe_jal()    -> %d erros\n", errors);
  }
  else {
    printf("exe_jal()    -> passou nos testes\n");
  }

  errors = test_exe_beq();
  if(errors > 0) {
    printf("exe_beq()    -> %d erros\n", errors);
  }
  else {
    printf("exe_beq()    -> passou nos testes\n");
  }

  errors = test_exe_lb();
  if(errors > 0) {
    printf("exe_lb()     -> %d erros\n", errors);
  }
  else {
    printf("exe_lb()     -> passou nos testes\n");
  }

  errors = test_exe_sb();
  if(errors > 0) {
    printf("exe_sb()     -> %d erros\n", errors);
  }
  else {
    printf("exe_sb()     -> passou nos testes\n");
  }

  errors = test_exe_addi();
  if(errors > 0) {
    printf("exe_addi()   -> %d erros\n", errors);
  }
  else {
    printf("exe_addi()   -> passou nos testes\n");
  }

  errors = test_exe_add();
  if(errors > 0) {
    printf("exe_add()    -> %d erros\n", errors);
  }
  else {
    printf("exe_add()    -> passou nos testes\n");
  }

  errors = test_exe_auipc();
  if(errors > 0) {
    printf("exe_auipc()  -> %d erros\n", errors);
  }
  else {
    printf("exe_auipc()  -> passou nos testes\n");
  }

  errors = test_exe_jalr();
  if(errors > 0) {
    printf("exe_jalr()   -> %d erros\n", errors);
  }
  else {
    printf("exe_jalr()   -> passou nos testes\n");
  }

  errors = test_exe_slti();
  if(errors > 0) {
    printf("exe_slti()   -> %d erros\n", errors);
  }
  else {
    printf("exe_slti()   -> passou nos testes\n");
  }

  errors = test_exe_sltiu();
  if(errors > 0) {
    printf("exe_sltiu()  -> %d erros\n", errors);
  }
  else {
    printf("exe_sltiu()  -> passou nos testes\n");
  }

  errors = test_exe_slli();
  if(errors > 0) {
    printf("exe_slli()   -> %d erros\n", errors);
  }
  else {
    printf("exe_slli()   -> passou nos testes\n");
  }

  errors = test_exe_srli();
  if(errors > 0) {
    printf("exe_srli()   -> %d erros\n", errors);
  }
  else {
    printf("exe_srli()   -> passou nos testes\n");
  }

  errors = test_exe_srai();
  if(errors > 0) {
    printf("exe_srai()   -> %d erros\n", errors);
  }
  else {
    printf("exe_srai()   -> passou nos testes\n");
  }
}
