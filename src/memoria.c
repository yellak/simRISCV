#include "../include/memoria.h"

int32_t lw(int32_t* address, int32_t kte) {
  return address[kte/4];
}

int32_t getField(int32_t word, int bit, int mask) {
  int temp = word >> bit;
  return temp & mask;
}

int32_t lbu(int32_t* address, int32_t kte) {
  int32_t temp = address[kte >> 2];
  int pos_byte = kte % 4;
  return (temp >> (8*pos_byte)) & 0xFF;
}

int32_t lhu(int32_t* address, int32_t kte) {
  int32_t temp = address[kte >> 2];
  int pos_bype = (kte % 4)/2;
  return (temp >> (16*pos_bype)) & 0xFFFF;
}

int32_t lb(int32_t* address, int32_t kte) {
  int32_t temp = address[kte >> 2];
  int pos_byte = kte % 4;
  temp = (temp >> (8*pos_byte)) & 0xFF;
  int8_t temp2 = (int8_t)temp;
  return (int32_t)temp2;
}

int32_t lh(int32_t* address, int32_t kte) {
  int32_t temp = address[kte >> 2];
  int pos_bype = (kte % 4)/2;
  temp = (temp >> (16*pos_bype)) & 0xFFFF;
  int16_t temp2 = (int16_t)temp;
  return (int32_t)temp2;
}

void sw(int32_t* address, int32_t kte, int32_t dado) {
  address[kte >> 2] = dado;
}

void sb(int32_t* address, int32_t kte, int8_t dado) {
  int32_t mask = 0x000000FF;
  int pos = kte / 4;
  int shift = 8*(kte % 4);
  mask = ~(mask << shift);
  address[pos] &= mask;
  int32_t dado2 = 0;
  dado2 += (uint8_t)dado;
  dado2 = dado2 << shift;
  address[pos] |= dado2;
}

void sh(int32_t* address, int32_t kte, int16_t dado) {
  int32_t mask = 0x0000FFFF;
  int pos = kte / 4;
  int shift = 16*((kte % 4) / 2);
  mask = ~(mask << shift);
  address[pos] &= mask;
  int32_t dado2 = 0;
  dado2 += (uint16_t)dado;
  dado2 = dado2 << shift;
  address[pos] |= dado2;
}

void dump_mem(int32_t* address, uint32_t wsize) {
  int i;
  for(i = 0; i < wsize; i++) {
    printf("mem[%d] = %X\n", i, address[i]);
  }
}
