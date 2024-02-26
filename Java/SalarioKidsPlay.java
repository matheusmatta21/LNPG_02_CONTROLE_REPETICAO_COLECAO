

import java.util.Scanner;

public class SalarioKidsPlay {
    public static void main(String[] args) {
        try(Scanner scanner = new Scanner(System.in)){
            int quantidade_brinquedos;
            double valor_vendas;
            double salario_base;
            double bonus = 0;
            double salario_total;

            System.out.println("Digite a quantidade de brinquedos vendidos: ");
            quantidade_brinquedos = scanner.nextInt();
            
            valor_vendas = (quantidade_brinquedos * 19.90);
            salario_base = valor_vendas  * 0.5;
            

            while(quantidade_brinquedos >= 15){
                bonus += salario_base * 0.08;
                quantidade_brinquedos -= 15;
            }

            salario_total = salario_base + bonus;
            System.out.printf("Valor total arrecadado em vendas: %.2f\nValor ganho como bônus: %.2f\nValor total do salário: %.2f", valor_vendas, bonus, salario_total);
        }
    }
}
