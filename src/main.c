#include "../include/test_mem.h"

/* Sistema Operacional utilizado: Linux Ubuntu 18.04
   Compilador: GCC 
   Editor: Emacs (o programa não está atrlado a uma IDE específica

   Como compilar:
   No terminal, dentro da pasta src deste projeto digite "make", o
   programa irá compilar e então execute digitando ./main */

int main() {
  printf("Executando testes iniciais:\n");
  run_tests();

  printf("\n---------------------------------\n");
  printf("Executando testes especificados\n");
  run_esp_tests();
}
