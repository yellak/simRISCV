#ifndef MEMMORIA_H
#define MEMMORIA_H

#include <stdint.h>
#include <stdio.h>

/* Argumentos:
   address -> endereço da memória
   kte     -> offset para a palavra desejada */
int32_t lw(int32_t* address, int32_t kte);

/* Argumentos:
   word    -> palavra de dados
   bit     -> posição inicial do pedaço a ser retirado
   mask    -> indica o tamanho do pedaço a ser retirado */
int32_t getField(int32_t word, int bit, int mask);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset do byte */
int32_t lbu(int32_t* address, int32_t kte);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset do byte */
int32_t lb(int32_t* address, int32_t kte);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset do primeiro byte da meia-palavra */
int32_t lhu(int32_t* address, int32_t kte);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset do primeiro byte da meia-palavra */
int32_t lh(int32_t* address, int32_t kte);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset de byte onde colocar a palavra
   dado    -> valor a ser armazenado na memória */
void sw(int32_t* address, int32_t kte, int32_t dado);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset de byte onde colocar o byte
   dado    -> valor a ser armazenado na memória */
void sb(int32_t* address, int32_t kte, int8_t dado);

/* Argumentos:
   address -> endereço da memória
   kte     -> offset de byte onde colocar a meia palavra
   dado    -> valor a ser armazenado na memória */
void sh(int32_t* address, int32_t kte, int16_t dado);


#endif
