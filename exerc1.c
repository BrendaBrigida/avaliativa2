#include <stdio.h>

int validaQuantidade() {
    int quantidade;
    while (1) {
        printf("Informe a quantidade de pecas fabricadas: ");
        if (scanf("%d", &quantidade) == 1 && quantidade >= 0) {
            return quantidade;
        } else {
            printf("Quantidade invalida. Digite um valor nao negativo.\n");
            while (getchar() != '\n');  // Limpa o buffer do teclado
        }
    }
}

float calculaSalario(int quantidade) {
    float salarioBase = 600.0;
    float adicional = 0.0;

    if (quantidade > 50) {
        adicional += 0.5 * (quantidade > 80 ? 80 - 50 : quantidade - 50);
    }

    if (quantidade > 80) {
        adicional += 0.75 * (quantidade - 80);
    }

    return salarioBase + adicional;
}

void mostraFinal(float salario) {
    printf("O salario total do funcionário e: R$ %.2f\n", salario);
}

main() {
    char continuar;
    do {
        int quantidade = validaQuantidade();
        float salario = calculaSalario(quantidade);
        mostraFinal(salario);

        printf("Deseja calcular o salario de outro funcionario? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

   
}