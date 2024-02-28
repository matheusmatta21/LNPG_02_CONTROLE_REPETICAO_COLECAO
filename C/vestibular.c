#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gabarito_prova[10];
int lenght_gabarito = sizeof(gabarito_prova) / sizeof(gabarito_prova[0]);
int quantidade_participantes;
char nome_participante[20];
char array_aluno[20][20];
int respostas_aluno[20];
int pontuacao_aluno;
int pontuacoes_alunos[20];
int maior_pontuacao = 0;
int menor_pontuacao = 11;
float quantidade_media_acima = 0;
float percentual_media_acima = 0;

int main(void)
{
  // input do gabarito da prova
  for (int i = 0; i < 10; i++)
  {
    printf("Digite o gabarito da prova (QUESTÃO %i)\n", i + 1);
    scanf(" %i", &gabarito_prova[i]);
  }
  printf("Digite a quantidade de participantes (no máximo 20):");
  scanf("%i", &quantidade_participantes);

  // loop para ler o nome do participante e suas notas

  for (int i = 0; i < quantidade_participantes; i++)
  {
    printf("Digite o primeiro nome do participante (* para parar):\n");
    scanf(" %s", array_aluno[i]);
    if (strcmp(array_aluno[i], "*") == 0)
    {
      break;
    }
    printf("%s\n", array_aluno[i]);
    for (int j = 0; j < 10; j++)
    {
      printf("Digite a resposta do participante na questão %i\n", j + 1);
      scanf(" %i", &respostas_aluno[j]);
      printf("%i\n", respostas_aluno[j]);
    }

    // loop para verificar a pontuação do aluno
    for (int i = 0; i < 10; i++)
    {
      if (strcmp(array_aluno[i], "*") == 0)
      {
        continue;
      }
      if (respostas_aluno[i] == gabarito_prova[i])
      {
        pontuacao_aluno++;
      }
    }
    // atribuição da pontuação do aluno e reiniciamento do contador de pontuações
    pontuacoes_alunos[i] = pontuacao_aluno;
    pontuacao_aluno = 0;
  } // encerramento do looping principal

  // verificação da maior e menor nota, respectivamente
  for (int i = 0; i < quantidade_participantes; i++)
  {
    if (strcmp(array_aluno[i], "*") == 0)
    {
      continue;
    }
    if (pontuacoes_alunos[i] > maior_pontuacao)
    {
      maior_pontuacao = pontuacoes_alunos[i];
    }
    if (menor_pontuacao > pontuacoes_alunos[i])
    {
      menor_pontuacao = pontuacoes_alunos[i];
    }
  }

  // verificacao do percentual de participantes com mais de 5 acertos
  for (int i = 0; i < quantidade_participantes; i++)
  {
    if (strcmp(array_aluno[i], "*") == 0)
    {
      continue;
    }
    if (pontuacoes_alunos[i] > 5)
    {
      quantidade_media_acima++;
    }
  }
  printf("%f", quantidade_media_acima);
  percentual_media_acima = quantidade_media_acima / quantidade_participantes;

  // imprimir alunos, respostas e suas notas
  for (int i = 0; i < quantidade_participantes; i++)
  {
    if (strcmp(array_aluno[i], "*") == 0)
    {
      continue;
    }
    printf("Aluno: %s, Pontuação: %i\n", array_aluno[i],
           pontuacoes_alunos[i]);
  }
  // imprimir maior e menor nota, juntamente com o nome do aluno
  for (int i = 0; i < quantidade_participantes; i++)
  {
    if (strcmp(array_aluno[i], "*") == 0)
    {
      continue;
    }
    if (maior_pontuacao == pontuacoes_alunos[i])
    {
      printf("A maior nota foi do (a) aluno (a) %s, com pontuação %i\n", array_aluno[i], pontuacoes_alunos[i]);
    }
    if (menor_pontuacao == pontuacoes_alunos[i])
    {
      printf("A menor nota foi do (a) aluno (a) %s, com pontuação %i\n", array_aluno[i], pontuacoes_alunos[i]);
    }
  }
  printf("%.1f%% dos alunos acertaram mais da metade das questões da prova.", percentual_media_acima * 100);

  return 0;
}
