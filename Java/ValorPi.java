

import java.util.Scanner;

public class ValorPi {
    public static void main(String[] args) {
        double termos_serie_pi;
        double variavel_termos = 1;
        double sum_expression = 0;

        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite o número de termos que a série de pi terá: ");
            termos_serie_pi = scanner.nextDouble();

            for(int i = 0 ;i < termos_serie_pi; i++){
                if(i % 2 == 0){
                    sum_expression = sum_expression + 1/Math.pow(variavel_termos, 3);
                } else{
                    sum_expression = sum_expression - 1/Math.pow(variavel_termos, 3);
                }
                variavel_termos += 2;
                System.out.println(sum_expression);
            }
            System.out.printf("O valor de pi é %.5f", Math.cbrt(sum_expression * 32));
        }
    }
}
