#include <stdio.h>
#include <math.h>

int main(void)
{
  double termos_serie_pi;
  double variavel_termos = 1;
  double sum_expression = 0;

  printf("Digiteo número de termos que a série pi terá:\n");
  scanf("%lf", &termos_serie_pi);

  for (int i = 0; i < termos_serie_pi; i++)
  {
    if (i % 2 == 0)
    {
      sum_expression += 1 / pow(variavel_termos, 3);
    }
    else
    {
      sum_expression -= 1 / pow(variavel_termos, 3);
    }
    variavel_termos += 2;
  }
  printf("%.5lf", pow(sum_expression * 32, 1.0 / 3.0));
  return 0;
}