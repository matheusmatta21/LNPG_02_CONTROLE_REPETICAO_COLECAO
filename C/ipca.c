#include <stdio.h>

int main(void) {
  int valor_mes;
  int valor_ano;
  double valor_ipca;
  int contador_input = 0;
  int array_mes[100] = {};
  int array_ano[100] = {};
  double array_valor_ipca[100] = {};
  double length_ipca = sizeof(array_valor_ipca) / sizeof(array_valor_ipca[0]);
  double length_mes = sizeof(array_mes) / sizeof(array_mes[0]);
  double length_ano = sizeof(array_ano) / sizeof(array_ano[0]);
  int index_mes_maior;
  int index_mes_menor;
  int index_ano_maior;
  int index_ano_menor;
  double maior_ipca = 0;
  double menor_ipca = 9999999999;
  double soma = 0;
  double media = 0;

  while (1) {
    printf("Digite o mês (sem o 0 inicial), ano e o valor do IPCA separados "
           "por espaço (-1 por espaço para parar): \n");
    scanf("%i"
          "%i"
          "%lf",
          &valor_mes, &valor_ano, &valor_ipca);
    if (valor_mes == -1 || valor_ano == -1 || valor_ipca == -1) {
      break;
    }
    array_ano[contador_input] += valor_ano;
    array_mes[contador_input] += valor_mes;
    array_valor_ipca[contador_input] += valor_ipca;
    for (int i = 0; i < length_ipca; i++) {
      if (array_valor_ipca[i] == 0) {
        continue;
      }
    }
    contador_input++;
  }
  for (int i = 0; i < length_ipca; i++) {
    if (array_valor_ipca[i] == 0) {
      continue;
    } else {
      if (maior_ipca < array_valor_ipca[i]) {
        maior_ipca = array_valor_ipca[i];
        index_mes_maior = i;
        index_ano_maior = i;
      }
      if (menor_ipca > array_valor_ipca[i]) {
        menor_ipca = array_valor_ipca[i];
        index_mes_menor = i;
        index_ano_menor = i;
      }
    }
  }

  for (int i = 0; i < length_ipca; i++) {
    if (array_valor_ipca[i] == 0) {
      continue;
    }
    soma += array_valor_ipca[i];
  }
  media = soma / contador_input;

  printf("O menor valor de IPCA foi de %.2lf, correspondente ao mês %i do ano "
         "%i\n",
         menor_ipca, array_mes[index_mes_menor], array_ano[index_ano_menor]);
  printf("O maior valor de IPCA foi de %.2lf, correspondente ao mês %i do ano "
         "%i\n",
         maior_ipca, array_mes[index_mes_maior], array_ano[index_ano_maior]);
  printf("A média dos valores de IPCA foi de %.2lf\n", media);

  return 0;
}
