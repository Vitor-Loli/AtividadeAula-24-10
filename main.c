#include <stdio.h>

void exec1() {
    int x = 15;
    int *px;
    px = &x;

    printf("Valor de X: %d\n", x);
    printf("Endereço de X: %p\n", (void*)&px);
    printf("Valor de X através do ponteiro: %d\n", *px);
}

void exec2(int *num) {
    *num = *num + 10;
}

void exec3() {
    int numeros[5];
    int *nums = numeros;
    int soma = 0;
    float media = 0;

    for (int i = 0; i < 5; i++) {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", nums + i);
    }

    for (int i = 0; i < 5; i++) {
        soma += *(nums + i);
    }

    media = soma / 5;
    printf("\nMédia dos inteiros: %.2f\n", media);
}

int main(void) {
    int opc = 0;
    do {
        printf("\nMENU\n");
        printf("[1] - Exercício 1\n");
        printf("[2] - Exercício 2\n");
        printf("[3] - Exercício 3\n");
        printf("[4] - Sair\n");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                exec1();
                break;
            case 2:
                int numero;
                int *num;
                num = &numero;
                printf("Informe o valor do número: \n");
                scanf("%d", num);
                printf("Número antes da soma: %d\n", *num);
                exec2(num);
                printf("Número + 10: %d\n", *num);
                break;
            case 3:
                exec3();
                break;
            case 4:
                printf("Até logo!");
                break;

            default:
                printf("Opção inválida!");
        }

    }while (opc !=4);
}