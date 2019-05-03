#include "../include/simulator.h"

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
