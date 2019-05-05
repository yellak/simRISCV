#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "memoria.h"

#define MEM_SIZE 4096
#define DATA_INIT 0x2000
#define DATA_END 0x204C

int32_t memory[MEM_SIZE]; /* memória disponível para o programa */
int32_t data_mem[DATA_END - DATA_INIT + 1];
int32_t pc; /* program counter */
int32_t ri; /* registrador de instrucoes */
int32_t breg[32]; /* banco de registradores */
int END;

/* Campos de uma instrução */
int32_t opcode;
int32_t rs1; /* primeiro registrador fonte */
int32_t rs2; /* segundo regitrador fonte */
int32_t rd;  /* registrador de destino */
int32_t shamt; /* deslocamento em instruções shift e rotate */
int32_t funct3; /* auxiliar de 3 bits */
int32_t funct7; /* auxiliar de 7 bits */
int32_t imm12_i; /* 12 bits, imediato tipo I */
int32_t imm12_s; /* 12 bits, imediato tipo S */
int32_t imm13; /* 13, tipo SB, bit 0 é 0 */
int32_t imm20_u; /* 20 MSBs, 31 a 12 */
int32_t imm21; /* 21 bits para saltos relativos, bit 0 é 0 */

/* registradores na ordem correta */
enum Registers
  {
   zero = 0, ra, sp, gp, tp, t0, t1, t2, s0, s1,
   a0, a1, a2, a3, a4, a5, a6, a7,
   s2, s3, s4, s5, s6, s7, s8, s9, s10, s11,
   t3, t4, t5, t6
  };

enum OPCODES
  {
   LUI = 0x37, AUIPC = 0x17, /* atribui 20 bits mais significativos */
   ILType = 0x03,		/* Load type */
   BType = 0x63,		/* branch condicional */
   JAL = 0x6F, JALR = 0x67,	/* jumps, JAL formato UJ e JALR formato I */
   StoreType = 0x23,		/* store */
   ILAType = 0x13,		/* logico-aritmeticas com imediato */
   RegType = 0x33,		/* operações LA com registradores */
   ECALL = 0x73,		/* chamada de sistema - formato I */
  };

/* Campo auxiliar de 3 bits */
enum FUNCT3
  {
   BEQ3=0, BNE3=01, BLT3=04, BGE3=05, BLTU3=0x06, BGEU3=07, /* branches */
   LB3=0, LH3=01, LW3=02, LBU3=04, LHU3=05,		    /* loads */
   SB3=0, SH3=01, SW3=02,				    /* stores */
   ADDSUB3=0, SLL3=01, SLT3=02, SLTU3=03,		    /* LA com */
   XOR3=04, SR3=05, OR3=06, AND3=07,			    /* registradores */
   ADDI3=0, ORI3=06, SLTI3=02, XORI3=04, ANDI3=07,	    /* LA com */
   SLTIU3=03, SLLI3=01, SRI3=05				    /* imediatos */
  };

/* campo auxiliar de 7 bits para as instrucoes SRLI/SRAI, ADD/SUB, SRL/SRA */
enum FUNCT7
  {	     
   ADD7=0, SUB7=0x20, SRA7=0x20, SRL7=0, SRLI7=0x00, SRAI7=0x20
  };

/* Inicializa os valores de algumas variáveis e limpa a memória
   e o banco de registradores */
void init_simulator();

/* Ler arquivo binário e guarda na memória
   Argumentos:
   mem         -> memória total
   filename    -> caminho até o arquivo a ser lido */
void read_mem(int32_t* mem, char filename[]);

/* Carrega a memória de dados */
void load_data();

/* Carrega a instrução atual no registro ri e atualiza pc */
void fetch();

/* Decodifica a instrução guardada em ri para os valores dos campos
   listados acima */
void decode();

/* Executa uma instrução lida pela função fetch() e decodificada por decode() */
void execute();

#endif
