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

int test_lb() {
  int32_t mem[4];
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  int errors = 0;
  int32_t result;

  /* byte 0xEF */
  result = lb(mem, 1);
  if(result != 0xFFFFFFEF) {
    errors++;
  }

  /* byte 0x54 */
  result = lb(mem, 6);
  if(result != 0x54) {
    errors++;
  }

  /* byte 0xFD */
  result = lb(mem, 10);
  if(result != 0xFFFFFFFD) {
    errors++;
  }

  /* byte 0xCA */
  result = lb(mem, 15);
  if(result != 0xFFFFFFCA) {
    errors++;
  }

  return errors;
}

int test_lh() {
  int32_t mem[4];
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  int errors = 0;
  int32_t result;

  /* meia-palavra 0xCEFD */
  result = lh(mem, 11);
  if(result != 0xFFFFCEFD) {
    errors++;
  }

  /* meia-palavra 0xEF98 */
  result = lh(mem, 1);
  if(result != 0xFFFFEF98) {
    errors++;
  }

  /* meia-palavra 0x2312 */
  result = lh(mem, 13);
  if(result != 0x2312) {
    errors++;
  }

  /* meia-palavra 0x7654 */
  result = lh(mem, 6);
  if(result != 0x7654) {
    errors++;
  }

  /* meia-palavra 0xABCD */
  result = lh(mem, 2);
  if(result != 0xFFFFABCD) {
    errors++;
  }

  return errors;
}

int test_sw() {
  int32_t mem[4];
  int errors = 0;

  mem[0] = 0x00000000;
  mem[1] = 0x00000000;
  mem[2] = 0x00000000;
  mem[3] = 0x00000000;

  sw(mem, 3, 0xABCDEF98);
  if(mem[0] != 0xABCDEF98) {
    errors++;
  }

  sw(mem, 12, 0xCCAAFFEE);
  if(mem[3] != 0xCCAAFFEE) {
    errors++;
  }

  sw(mem, 8, 0xFACA);
  if(mem[2] != 0xFACA) {
    errors++;
  }

  sw(mem, 4, 0xECA);
  if(mem[1] != 0xECA) {
    errors++;
  }

  return errors;
}

int test_sb() {
  int32_t mem[4];
  int errors = 0;
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  /* guardando no byte 0xCD */
  sb(mem, 2, 0x23);
  if(mem[0] != 0xAB23EF98) {
    errors++;
  }

  /* guardando no byte 0xCA */
  sb(mem, 15, 0xFE);
  if(mem[3] != 0xFEFE2312) {
    errors++;
  }

  /* guardando no byte 0x7F */
  sb(mem, 8, 0x07);
  if(mem[2] != 0xCEFD2407) {
    errors++;
  }

  /* guardando no byte 0x76 */
  sb(mem, 7, 0xFE);
  if(mem[1] != 0xFE543210) {
    errors++;
  }

  /* guardando no byte 0xFD */
  sb(mem, 10, 0xAA);
  if(mem[2] != 0xCEAA2407) {
    errors++;
  }

  return errors;
}

int test_sh() {
  int32_t mem[4];
  int errors = 0;
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  /* guardando no lugar de 0xABCD */
  sh(mem, 3, 0xCCCC);
  if(mem[0] != 0xCCCCEF98) {
    errors++;
  }

  /* guardando no lugar de 0x3210 */
  sh(mem, 4, 0xCACA);
  if(mem[1] != 0x7654CACA) {
    errors++;
  }

  /* guardando no lugar de 0xCAFE */
  sh(mem, 14, 0x2222);
  if(mem[3] != 0x22222312) {
    errors++;
  }

  /* guardando no lugar de 0xCEFD */
  sh(mem, 11, 0xABAB);
  if(mem[2] != 0xABAB247F) {
    errors++;
  }

  /* guardando no lugar de 0x247F */
  sh(mem, 8, 0xDDDD);
  if(mem[2] != 0xABABDDDD) {
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
  
  /* testes para a função lbu() */
  errors = test_lbu();
  if(errors > 0) {
    printf("lbu()        -> %d erros\n", errors);
  }
  else {
    printf("lbu()        -> passou nos testes\n");
  }

  /* testes para a função lhu() */
  errors = test_lhu();
  if(errors > 0) {
    printf("lhu()        -> %d erros\n", errors);
  }
  else {
    printf("lhu()        -> passou nos testes\n");
  }

  /* testes da função lb() */
  errors = test_lb();
  if(errors > 0) {
    printf("lb()         -> %d erros\n", errors);
  }
  else {
    printf("lb()         -> passou nos testes\n");
  }

  /* testes da função lh() */
  errors = test_lh();
  if(errors > 0) {
    printf("lh()         -> %d erros\n", errors);
  }
  else {
    printf("lh()         -> passou nos testes\n");
  }

  /* testes para a função sw() */
  errors = test_sw();
  if(errors > 0) {
    printf("sw()         -> %d erros\n", errors);
  }
  else {
    printf("sw()         -> passou nos testes\n");
  }

  /* testes para a função sb() */
  errors = test_sb();
  if(errors > 0) {
    printf("sb()         -> %d erros\n", errors);
  }
  else {
    printf("sb()         -> passou nos testes\n");
  }

  /* testes para a função sh() */
  errors = test_sh();
  if(errors > 0) {
    printf("sh()         -> %d erros\n", errors);
  }
  else {
    printf("sh()         -> passou nos testes\n");
  }
}

void run_esp_tests() {
  int32_t mem[4];
  mem[0] = 0xABCDEF98; /*  0 */
  mem[1] = 0x76543210; /*  4 */
  mem[2] = 0xCEFD247F; /*  8 */
  mem[3] = 0xCAFE2312; /* 12 */

  dump_mem(mem, 4);
}
