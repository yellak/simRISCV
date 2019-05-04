#ifndef TEST_SIMULATOR_H
#define TEST_SIMULATOR_H

#include "simulator.h"

int32_t mem[4096]; // memoria de teste
extern char test1[];
extern char test_lui[];
extern char test_jal[];
extern char test_beq[];
extern char test_lb_txt[];
extern char test_lb_dt[];
extern char test_sb_txt[];
extern char test_addi_txt[];

int test_read_mem();

int test_fetch();

int test_decode();

int test_exe_lui();

int test_exe_jal();

int test_exe_beq();

int test_exe_lb();

int test_exe_sb();

int test_exe_addi();

void run_simulator_tests();

#endif
