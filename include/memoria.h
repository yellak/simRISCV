#ifndef MEMMORIA_H
#define MEMMORIA_H

#include <stdint.h>
#include <stdio.h>

int32_t lw(uint32_t* address, int32_t kte);

int32_t getField(int32_t word, int bit, int mask);

#endif
