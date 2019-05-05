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
extern char test_add_txt[];
extern char test_auipc_txt[];
extern char test_jalr_txt[];
extern char test_slti_txt[];
extern char test_sltiu_txt[];
extern char test_slli_txt[];
extern char test_srli_txt[];
extern char test_srai_txt[];
extern char test_ecall_1_txt[];
extern char test_ecall_4_txt[];
extern char test_ecall_4_dt[];

int test_read_mem();

int test_fetch();

int test_decode();

int test_exe_lui();

int test_exe_jal();

int test_exe_beq();

int test_exe_lb();

int test_exe_sb();

int test_exe_addi();

int test_exe_add();

int test_exe_auipc();

int test_exe_jalr();

int test_exe_slti();

int test_exe_sltiu();

int test_exe_slli();

int test_exe_srli();

int test_exe_srai();

void test_exe_ecall_1();

void test_exe_ecall_4();

void run_simulator_tests();

#endif
