#include <stdio.h>


char obterSexo();
float obterSalario();
void mostraClassificacao(float salario);
void classificaSalario(float salario, int *abaixo, int *acima);

int main(){
    int numAssalariados, abaixoDoMinimo = 0, acimaDoMinimo = 0;

    printf("Informe o número de assalariados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++) {
        char sexo = obterSexo();
        float salario = obterSalario();

        if (salario > 1.0) {
            printf("\nSalário: R$ %.2f\n", salario);
            mostraClassificacao(salario);
            classificaSalario(salario, &abaixoDoMinimo, &acimaDoMinimo);
        } else {
            printf("\nSalario invalido. Informe um salario maior que R$1,00.\n");
            i--; 
        }
    }

    printf("\nQuantidade de assalariados abaixo do salário mínimo: %d\n", abaixoDoMinimo);
    printf("Quantidade de assalariados acima do salário mínimo: %d\n", acimaDoMinimo);

    return 0;
}

char obterSexo() {
    char sexo;

    printf("Informe o sexo do assalariado (M/F): ");
    scanf(" %c", &sexo);

    return sexo;
}

float obterSalario() {
    float salario;

    printf("Informe o salário do assalariado em reais (maior que R$1,00): ");
    scanf("%f", &salario);

    return salario;
}

void mostraClassificacao(float salario) {
    if (salario > 1400.0) {
        printf("Classificação: Acima do salário mínimo\n");
    } else if (salario == 1400.0) {
        printf("Classificação: Igual ao salário mínimo\n");
    } else {
        printf("Classificação: Abaixo do salário mínimo\n");
    }
}

void classificaSalario(float salario, int *abaixo, int *acima) {
    if (salario < 1400.0) {
        (*abaixo)++;
    } else {
        (*acima)++;
    }
}