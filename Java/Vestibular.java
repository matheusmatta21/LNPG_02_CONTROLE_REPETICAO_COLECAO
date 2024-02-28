import java.util.Scanner;

public class Vestibular {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int[] gabarito_prova = new int[10];
            int quantidade_participantes;
            String[] array_aluno = new String[20];
            int[] respostas_aluno = new int[20];
            int pontuacao_aluno = 0;
            int[] pontuacoes_alunos = new int[20];
            int maior_pontuacao = 0;
            int menor_pontuacao = 11;
            float quantidade_media_acima = 0;
            float percentual_media_acima = 0;

            for (int i = 0; i < 10; i++) {
                System.out.printf("Digite o gabarito da prova (QUESTÃO %d)\n", i + 1);
                gabarito_prova[i] = scanner.nextInt();
            }
            System.out.println("Digite a quantidade de participantes (no máximo 20):");
            quantidade_participantes = scanner.nextInt();

            // loop para ler o nome do participante e suas notas

            for (int i = 0; i < quantidade_participantes; i++) {
                System.out.println("Digite o primeiro nome do participante (* para parar):");
                array_aluno[i] = scanner.next();
                if (array_aluno[i].contains("*")) {
                    break;
                }
                for (int j = 0; j < 10; j++) {
                    System.out.printf("Digite a resposta do participante na questão %d\n", j + 1);

                    respostas_aluno[j] = scanner.nextInt();
                }
                // loop para verificar a pontuação do aluno
                for (int i2 = 0; i2 < 10; i2++) {
                    if (array_aluno[i].contains("*")) {
                        continue;
                    }
                    if (respostas_aluno[i2] == gabarito_prova[i2]) {
                        pontuacao_aluno++;
                    }
                }
                // atribuição da pontuação do aluno e reiniciamento do contador de pontuações
                pontuacoes_alunos[i] = pontuacao_aluno;
                pontuacao_aluno = 0;
            } // encerramento do looping principal
            for (int i = 0; i < quantidade_participantes; i++) {
                if (array_aluno[i].contains("*")) {
                    continue;
                }
                if (pontuacoes_alunos[i] > maior_pontuacao) {
                    maior_pontuacao = pontuacoes_alunos[i];
                }
                if (menor_pontuacao > pontuacoes_alunos[i]) {
                    menor_pontuacao = pontuacoes_alunos[i];
                }
            }
            for (int i = 0; i < quantidade_participantes; i++) {
                if (array_aluno[i].contains("*")) {
                    continue;
                }
                if (pontuacoes_alunos[i] > 5) {
                    quantidade_media_acima++;
                }
            }
            percentual_media_acima = quantidade_media_acima / quantidade_participantes;
            // imprimir alunos, respostas e suas notas
            for (int i = 0; i < quantidade_participantes; i++) {
                if (array_aluno[i].contains("*")) {
                    continue;
                }
                System.out.printf("Aluno: %s, Pontuação: %d\n", array_aluno[i], pontuacoes_alunos[i]);
            }
            // imprimir maior e menor nota, juntamente com o nome do aluno
            for (int i = 0; i < quantidade_participantes; i++) {
                if (array_aluno[i].contains("*")) {
                    continue;
                }
                if (maior_pontuacao == pontuacoes_alunos[i]) {
                    System.out.printf("A maior nota foi do (a) aluno (a) %s, com pontuação %d\n", array_aluno[i],
                            pontuacoes_alunos[i]);
                }
                if (menor_pontuacao == pontuacoes_alunos[i]) {
                    System.out.printf("A menor nota foi do (a) aluno (a) %s, com pontuação %d\n", array_aluno[i],
                            pontuacoes_alunos[i]);
                }
            }
            System.out.printf("%.1f%% dos alunos acertaram mais da metade das questões da prova.",
                    percentual_media_acima * 100);

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

