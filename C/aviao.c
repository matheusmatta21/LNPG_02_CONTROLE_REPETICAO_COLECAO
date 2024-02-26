#include <stdio.h>
#include <string.h>

int main()
{
    char possui_rg[10];
    char data_nascimento_rg[10];
    char possui_passagem[10];
    char data_nascimento_passagem[10];
    char cadeira_passageiro[3];
    char sim_rg[2] = "RG";
    char sim_passagem[8] = "Passagem";
    int quantidade_passsageiros;

    printf("Digite a quantidade de passageiros:\n");
    scanf("%d", &quantidade_passsageiros);

    for (int i = 0; i < quantidade_passsageiros; i++)
    {
        printf("Possui RG? (RG para sim e Nao para não):\n");
        scanf("%s", possui_rg);

        if (strcmp(possui_rg, sim_rg) != 0)
        {
            printf("A saída é nessa direção.\n");
            continue;
        }
        else if (strcmp(possui_rg, sim_rg) == 0)
        {
            printf("Data de nascimento do RG (no formato DD/MM/AAAA):\n");
            scanf("%s", data_nascimento_rg);
            printf("Possui passagem? (Passagem para sim e Nao para não):\n");
            scanf("%s", possui_passagem);
            if (strcmp(possui_passagem, sim_passagem) != 0)
            {
                printf("A saída é nessa direção.\n");
                continue;
            }
            else if (strcmp(possui_passagem, sim_passagem) == 0)
            {
                printf("Data de nascimento da passagem (no formato DD/MM/AAAA):\n");
                scanf("%s", data_nascimento_passagem);
                if (strcmp(data_nascimento_rg, data_nascimento_passagem) != 0)
                {
                    printf("190\n");
                    continue;
                }
                else
                {
                    printf("Digite o numero do assento:\n");
                    scanf("%s", cadeira_passageiro);
                    printf("o seu assento é %s\nTenha um ótimo dia!", cadeira_passageiro);
                }
            }
        }
    }
    return 0;
}
