# Simulador RISCV
Este projeto é um simulador do funcionamento de processadores RISCV.

## Execução
Para compilar vá até a pasta principal e execute **make all** ou só **make main** para gerar somente o executável _main_. Execute o programa pincipal com **./main** e os testes com **./run_tests**.

Para alterar quais arquivos serão executados por **./main** vá até o arquivo _main.c_ e altere as linhas 15 e 16 com os caminhos até os arquivos que deseja executar.

### Observação
Existem dois tipos de arquivos binários relevantes, um _data_ e um _text_, o _data_ contém as informações para alocação de espaço na memória RAM e o arquivo _text_ contém as instruções que serão executadas. Os dois podem ser gerados a partir de um código assembly utilizando uma ferramenta apropriada, eu utilizei o [RARS](https://github.com/TheThirdOne/rars) (não há garantias de que outra ferramenta pode funcionar).
