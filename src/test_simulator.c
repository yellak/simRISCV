#include "../include/test_simulator.h"

int test_read_mem() {
  int errors = 0;
  read_mem(mem, "tests/test1_text.bin");

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

void run_simulator_tests() {
  int errors;
  errors = test_read_mem();
  if(errors > 0) {
    printf("read_mem()   -> %d erros\n", errors);
  }
  else {
    printf("read_mem()   -> passou nos testes\n");
  }
}
