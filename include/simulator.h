#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "memoria.h"

#define MEM_SIZE 4096

int32_t memory[MEM_SIZE]; /* memória disponível para o programa */
int32_t pc; /* program counter */
int32_t ri; /* registrador de instrucoes */
int32_t breg[32]; /* banco de registradores */

/* Campos de uma instrução */
int32_t opcode;
int32_t rs1; /* primeiro registrador fonte */
int32_t rs2; /* segundo regitrador fonte */
int32_t rd;  /* registrado de destino */
int32_t shamt; /* deslocamento em instruções shift e rotate */
int32_t funct3; /* auxiliar de 3 bits */
int32_t funct7; /* auxiliar de 7 bits */
int32_t imm12_i; /* 12 bits, imediato tipo I */
int32_t imm12_s; /* 12 bits, imediato tipo S */
int32_t imm13; /* 13, tipo SB, bit 0 é 0 */
int32_t imm20_u; /* 20 MSBs, 31 a 12 */
int32_t imm21; /* 21 bits para saltos relativos, bit 0 é 0 */

enum Registers {
		zero = 0, ra, sp, gp, tp, t0, t1, t2, s0, s1,
		a0, a1, a2, a3, a4, a5, a6, a7,
		s2, s3, s4, s5, s6, s7, s8, s9, s10, s11,
		t3, t4, t5, t6
};

/* Inicializa os valores de algumas variáveis e limpa a memória
   e o banco de registradores */
void init_simulator();

/* Ler arquivo binário e guarda na memória
   Argumentos:
   mem         -> memória total
   filename    -> caminho até o arquivo a ser lido */
void read_mem(int32_t* mem, char filename[]);

/* Carrega a instrução atual no registro ri e atualiza pc */
void fetch();

/* Decodifica a instrução guardada em ri para os valores dos campos
   listados acima */
void decode();

#endif
