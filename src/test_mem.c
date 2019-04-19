#include "../include/test_mem.h"

int test_lw() {
  int errors = 0;
  int32_t mem[4]; /* memória de teste */
  int32_t t0, kte; /* registrador e offset respectivamente */

  /* Configurando a memória */
  mem[0] = 0xCAFE03C0;
  mem[1] = 0xF3F2F1F0;
  mem[2] = 0xC3C2C1C0;
  mem[3] = 0xA3A2A1A0;

  /* primeiro elemento da memória */
  kte = 0;
  t0 = lw(mem, kte);
  if(t0 != mem[0]) {
    errors++;
  }

  /* segundo elemento */
  kte = 4;
  t0 = lw(mem, kte);
  if(t0 != mem[1]) {
    errors++;
  }

  /* último elemento */
  kte = 12;
  t0 = lw(mem, kte);
  if(t0 != mem[3]) {
    errors++;
  }

  /* valor impar */
  kte = 9;
  t0 = lw(mem, kte);
  if(t0 != mem[2]) {
    errors++;
  }
  
  return errors;
}

int test_getField() {
  int32_t tword = 0x1267CAFE;
  int errors = 0;
  int result;

  result = getField(tword, 0, 0xFF);
  if(result != 0xFE) {
    errors++;
  }

  return errors;
}


void run_tests() {
  int errors;

  /* fazendo os testes para a função lw() */
  errors = test_lw();
  if(errors > 0) {
    printf("Erros em lw(): %d\n", errors);
  }
  else {
    printf("lw() passou nos testes\n");
  }

  /* fazendo para a função getField */
  errors = test_getField();
  if(errors > 0) {
    printf("Erros em getField(): %d\n", errors);
  }
  else {
    printf("getField() passou nos testes\n");
  }
}
