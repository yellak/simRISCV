#include "../include/simulator.h"

/* Sistema Operacional utilizado: Linux Ubuntu 18.04
   Compilador: GCC 
   Editor: Emacs (o programa não está atrelado a uma IDE específica

   Como compilar:
   No terminal, dentro da pasta src deste projeto digite "make all", o
   programa irá compilar e então execute digitando ./main */

int main() {
  /* Altere qual programa será executado por aqui */
  /* databin - caminho até o arquivo binário com os dados .data */
  /* testbin - caminho até o arquivo binário com os dados .text */
  char databin[] = "progs/BJ_data.bin";
  char textbin[] = "progs/BJ.bin";

  char option;
  init_simulator();
  read_mem(data_mem, databin);
  read_mem(memory, textbin);
  load_data();

  printf("Iniciando o programa...\n");
  while(END != 1) {
    printf("\n----------------------------------------\n");
    printf("Escolha uma:\n");
    printf("s-step\n");
    printf("r-run\n");
    printf("m-mostrar registros\n");
    scanf("\n%c", &option);
    switch(option) {
    case 's':
      step();
      break;

    case 'r':
      printf("\n----------------------------------------\n");
      run();
      break;

    case 'm':
      dump_reg('h');
      break;
    } /* switch(option) */
  }

  printf("\n");
}
