#include <stdio.h>

int main()
{
    float preco_jogo = 19.90;
    int quantidade_jogos;
    double valor_vendas;
    double valor_bonus;
    double valor_total;

    printf("Digite a quantidade de jogos vendidos: \n");
    scanf("%d", &quantidade_jogos);

    while (quantidade_jogos < 0)
    {
        printf("Digite um valor válido: \n");
        scanf("%d", &quantidade_jogos);
    }

    valor_vendas = (quantidade_jogos * preco_jogo) * 0.5;

    while (1)
    {
        if (quantidade_jogos - 15 >= 0 && quantidade_jogos >= 15)
        {
            valor_bonus += valor_vendas * 0.08;
            quantidade_jogos = quantidade_jogos - 15;
        }
        else
        {
            break;
        }
    }

    valor_total = valor_vendas + valor_bonus;

    printf("O valor de vendas foi de R$%.2lf \nO valor de bonus foi de R$%.2lf \nO valor total foi de R$%.2lf ", valor_vendas, valor_bonus, valor_total);

    return 0;
}