#include "../include/test_simulator.h"

char test1[] = "tests/test1_text.bin";

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

/* 
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|20|19|18|17|16|15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |1 |0 |0 |0 |1 |
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+

*/
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
}
