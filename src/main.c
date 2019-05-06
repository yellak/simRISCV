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
  int start, end;
  init_simulator();
  read_mem(data_mem, databin); /* lendo .data */
  read_mem(memory, textbin);   /* lendo .text */
  load_data();

  printf("Iniciando o programa...\n");
  while(END != 1) {
    printf("\n----------------------------------------\n");
    printf("s - step\n");
    printf("r - run\n");
    printf("l - listar registros\n");
    printf("m - mostrar memória\n");
    printf("q - sair\n");
    printf("Escolha uma:\n");
    scanf("\n%c", &option);

    switch(option) {
    case 's': /* step */
      step();
      break;

    case 'r': /* rodar programa todo */
      printf("\n----------------------------------------\n");
      run();
      break;

    case 'l': /* listar registradores */
      dump_reg('h');
      break;

    case 'q': /* sair do programa */
      END = 1;
      break;

    case 'm': /* mostrar memória */
      printf("Escolha os endereços inicial e final (decimal):\n");
      printf("Inicial: ");
      scanf("%d", &start);
      printf("Final: ");
      scanf("%d", &end);
      printf("\nMemória de %d a %d (endereço de byte):\n\n", start, end);
      dump_mem(start, end, 'h');
      break;
    } /* switch(option) */
  }

  printf("\n");
}
