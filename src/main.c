#include "../include/test_mem.h"
#include "../include/simulator.h"

/* Sistema Operacional utilizado: Linux Ubuntu 18.04
   Compilador: GCC 
   Editor: Emacs (o programa não está atrlado a uma IDE específica

   Como compilar:
   No terminal, dentro da pasta src deste projeto digite "make", o
   programa irá compilar e então execute digitando ./main */

int main() {
  int32_t mem[100];
  read_mem(mem, "tests/test1_text.bin");
  dump_mem(mem, 5);
}
