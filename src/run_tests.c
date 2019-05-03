#include "../include/run_tests.h"

int main() {
  printf("Testes das funções de acesso a memória:\n");
  run_tests();

  printf("\nTestes das funções do simulador:\n");
  run_simulator_tests();
}
