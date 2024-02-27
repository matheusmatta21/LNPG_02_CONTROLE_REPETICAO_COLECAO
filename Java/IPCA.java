import java.util.Scanner;

public class IPCA {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int valor_mes;
            int valor_ano;
            double valor_ipca;
            int contador_input = 0;
            int[] array_mes = new int[100];
            int[] array_ano = new int[100];
            double[] array_valor_ipca = new double[100];
            int index_mes_maior = 0;
            int index_mes_menor = 0;
            int index_ano_maior = 0;
            int index_ano_menor = 0;
            double maior_ipca = 0;
            double menor_ipca = 999999999;
            double soma = 0;
            double media = 0;

            while (true) {
                System.out.println("Digite o mês (sem o 0 inicial) (-1 para parar):");
                valor_mes = scanner.nextInt();
                if (valor_mes == -1) {
                    break;
                }
                System.out.println("Digite o ano:");
                valor_ano = scanner.nextInt();
                System.out.println("Digite o valor do IPCA:");
                valor_ipca = scanner.nextDouble();
                array_ano[contador_input] = valor_ano;
                array_mes[contador_input] = valor_mes;
                array_valor_ipca[contador_input] = valor_ipca;
                contador_input++;
            }
            for (int i = 0; i < array_valor_ipca.length; i++) {
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
            for (int i = 0; i < array_valor_ipca.length; i++) {
                if (array_valor_ipca[i] == 0) {
                    continue;
                }
                soma += array_valor_ipca[i];
            }
            media = soma / contador_input;

            System.out.printf("O menor valor de IPCA foi de %.2f, correspondente ao mês %d do ano %d\n", menor_ipca,
                    array_mes[index_mes_menor], array_ano[index_ano_menor]);
            System.out.printf("O maior valor de IPCA foi de %.2f, correspondente ao mês %d do ano %d\n", maior_ipca,
                    array_mes[index_mes_maior], array_ano[index_ano_maior]);
            System.out.printf("A média dos valores de IPCA foi de %.2f\n", media);
        }
    }
}
