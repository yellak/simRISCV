#include "../include/memoria.h"

int32_t lw(uint32_t* address, int32_t kte) {
  return address[kte/4];
}

int32_t getField(int32_t word, int bit, int mask) {
  int temp = word >> bit;
  return temp & mask;
}

int32_t lbu(uint32_t* address, int32_t kte) {
  int32_t temp = address[kte >> 2];
  int pos_byte = kte % 4;
  return (temp >> (8*pos_byte)) & 0xFF;
}
