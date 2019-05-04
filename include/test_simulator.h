#ifndef TEST_SIMULATOR_H
#define TEST_SIMULATOR_H

#include "simulator.h"

int32_t mem[4096]; // memoria de teste
extern char test1[];

int test_read_mem();

int test_fetch();

int test_decode();

void run_simulator_tests();

#endif
