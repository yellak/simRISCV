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

  /* Testando para o primeiro byte */
  result = getField(tword, 0, 0xFF);
  if(result != 0xFE) {
    errors++;
  }

  /* para o último byte */
  result = getField(tword, 24, 0xFF);
  if(result != 0x12) {
    errors++;
  }

  /* para o nibble A */
  result = getField(tword, 8, 0xF);
  if(result != 0xA) {
    errors++;
  }

  /* para o nibble 7 */
  result = getField(tword, 16, 0xF);
  if(result != 0x7) {
    errors++;
  }

  return errors;
}

int test_lbu() {
  int32_t mem[4];
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  int errors = 0;
  uint32_t result;

  /* byte 0x23 */
  result = lbu(mem, 13);
  if(result != 0x23) {
    errors++;
  }

  /* byte 0xCA */
  result = lbu(mem, 15);
  if(result != 0xCA) {
    errors++;
  }

  /* byte 0x54 */
  result = lbu(mem, 6);
  if(result != 0x54) {
    errors++;
  }

  /* byte 0xEF */
  result = lbu(mem, 1);
  if(result != 0xEF) {
    errors++;
  }

  return errors;
}

int test_lhu() {
  int32_t mem[4];
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  int errors = 0;
  uint32_t result;

  /* meia-palavra 0x247F */
  result = lhu(mem, 9);
  if(result != 0x247F) {
    errors++;
  }

  /* meia-palavra 0x7654 */
  result = lhu(mem, 6);
  if(result != 0x7654) {
    errors++;
  }

  /* meia-palavra 0xCAFE */
  result = lhu(mem, 15);
  if(result != 0xCAFE) {
    errors++;
  }

  /* meia-palavra 0xEF98 */
  result = lhu(mem, 0);
  if(result != 0xEF98) {
    errors++;
  }

  return errors;
}


void run_tests() {
  int errors;

  /* fazendo os testes para a função lw() */
  errors = test_lw();
  if(errors > 0) {
    printf("lw():        ->  %d erros\n", errors);
  }
  else {
    printf("lw()         -> passou nos testes\n");
  }

  /* fazendo para a função getField */
  errors = test_getField();
  if(errors > 0) {
    printf("getField():  -> %d erros\n", errors);
  }
  else {
    printf("getField()   -> passou nos testes\n");
  }

  errors = test_lbu();
  if(errors > 0) {
    printf("lbu()        -> %d erros\n", errors);
  }
  else {
    printf("lbu()        -> passou nos testes\n");
  }

  errors = test_lhu();
  if(errors > 0) {
    printf("lhu()        -> %d erros\n", errors);
  }
  else {
    printf("lhu()        -> passou nos testes\n");
  }
}
