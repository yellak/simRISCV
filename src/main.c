#include "../include/test_mem.h"

int main() {
  printf("Executando testes iniciais:\n");
  run_tests();

  printf("\n---------------------------------\n");
  printf("Executando testes especificados\n");
  run_esp_tests();
}
