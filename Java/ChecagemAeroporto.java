
import java.util.Scanner;

public class ChecagemAeroporto {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int quantidade_passageiros;
            String possui_rg;
            String data_nascimento_rg;
            String possui_passagem;
            String data_nascimento_passagem;
            String ascento_desejado;

            System.out.println("Quantos passageiros?");
            quantidade_passageiros = scanner.nextInt();

            for (int i = 0; i < quantidade_passageiros; i++) {
                System.out.println("Possui RG? (RG - Sim |Não - Não) ");
                possui_rg = scanner.next();

                if (possui_rg.toLowerCase().contains("nao") || possui_rg.toLowerCase().contains("não")) {
                    System.out.println("A saída é nessa direção.\n");
                    continue;
                } else if (possui_rg.toLowerCase().contains("rg")) {
                    System.out.println("Ok.\n");
                }

                System.out.println("Qual a data de nascimento que consta no RG? (No formato 'DD/MM/AAAA') ");
                data_nascimento_rg = scanner.next();

                System.out.println("Possui Passagem? (Passagem - Sim |Não - Não)");
                possui_passagem = scanner.next();

                if (possui_passagem.toLowerCase().contains("nao") || possui_passagem.toLowerCase().contains("não")) {
                    System.out.println("A saída é nessa direção.\n");
                    continue;
                } else if (possui_passagem.toLowerCase().contains("passagem")) {
                    System.out.println("Ok.\n");
                }

                System.out.println("Qual a data de nascimento que consta na passagem? (No formato 'DD/MM/AAAA') ");
                data_nascimento_passagem = scanner.next();

                if (data_nascimento_rg.contains(data_nascimento_passagem)) {
                    System.out.println("Ok.\n");
                } else {
                    System.out.println("190\n");
                    continue;
                }

                System.out.println("Qual é o ascento do passageiro? ");
                ascento_desejado = scanner.next();

                System.out.println("O seu ascento é o " + ascento_desejado + "." + " Tenha uma boa viagem!\n");

            }
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
