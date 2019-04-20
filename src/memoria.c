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
  int8_t temp2 = (int8_t)temp;
  return (int32_t)temp2;
}
