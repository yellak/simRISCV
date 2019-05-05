#include "../include/simulator.h"

/* Sistema Operacional utilizado: Linux Ubuntu 18.04
   Compilador: GCC 
   Editor: Emacs (o programa não está atrlado a uma IDE específica

   Como compilar:
   No terminal, dentro da pasta src deste projeto digite "make", o
   programa irá compilar e então execute digitando ./main */

int main() {
  char option;
  init_simulator();
  read_mem(data_mem, "progs/BJ_data.bin");
  read_mem(memory, "progs/BJ.bin");
  load_data();

  printf("Iniciando o programa...\n");
  while(END != 1) {
    printf("\n--------------------\n");
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
      run();
      break;

    case 'm':
      dump_reg('h');
      break;
    } /* switch(option) */
  }

  printf("\n");
}
