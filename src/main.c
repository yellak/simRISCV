#include "../include/simulator.h"

/* Sistema Operacional utilizado: Linux Ubuntu 18.04
   Compilador: GCC 
   Editor: Emacs (o programa não está atrlado a uma IDE específica

   Como compilar:
   No terminal, dentro da pasta src deste projeto digite "make", o
   programa irá compilar e então execute digitando ./main */

int main() {
  init_simulator();
  read_mem(data_mem, "progs/BJ_data.bin");
  read_mem(memory, "progs/BJ.bin");
  load_data();
  run();
  printf("\n");
}
