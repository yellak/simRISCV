#include "../include/memoria.h"

int32_t lw(uint32_t* address, int32_t kte) {
    return address[kte/4];
}

int32_t getField(int32_t word, int bit, int mask) {
  return (word << bit) & mask;
}
