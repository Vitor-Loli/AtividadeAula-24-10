#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void exec4() {
    printf("Informe a quantidade de números: \n");
    int n;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    int soma = 0;
    double media = 0;

    for (int i = 0; i < n; i++) {
        printf("Informe o %dº número:\n", (i + 1));
        scanf("%d", &v[i]);
        soma += v[i];
    }

    media = soma / n;
    printf("A soma dos valores passados é: %d\n", soma);
    printf("A média dos valores passados é: %.2lf", media);

    free(v);
}

void exec5() {
    printf("Informe a quantidade de linhas:\n");
    int l;
    scanf("%d", &l);
    printf("Informe a quantidade de colunas:\n");
    int c;
    scanf("%d", &c);
    int *m = (int *) malloc(c * l * sizeof(int));

    for (int linha = 0; linha < l; linha++) {
        for (int coluna = 0; coluna < c; coluna++) {
            printf("Informe o valor para a %d linha/ %d coluna: ", linha + 1, coluna + 1);
            int valor;
            scanf("%d", &valor);
            m[linha * c + coluna] = valor;
        }
    }

    printf("Matriz:\n");
    for (int linha = 0; linha < l; linha++) {
        for (int coluna = 0; coluna < c; coluna++) {
            printf("%d ", m[linha * c + coluna]);
            if (coluna == c - 1) {
                printf("\n");
            }

        }
    }
}

void exec6() {
    char c[100];
    printf("Informe uma palavra para contar vogais:\n");
    scanf("%s", c);
    char *v = c;
    int contador = 0;
    while (*v != '\0') {
        if (*v == 'a' || *v == 'A' || *v == 'e' || *v == 'E' || *v == 'i' || *v == 'I' || *v == 'o' || *v == 'O' || *v == 'u' || *v == 'U') {
            contador++;
        }
        v++;
    }

    printf("A palavra '%s' contem %d vogais!", c, contador);
}

void exec7() {
    char c[100];

    printf("Digite uma palavra: ");
    scanf("%s", c);

    char *p = c;

    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        p++;
    }

    printf("Resultado: %s", c);
}

void exec8() {
    char origem[100];
    char destino[100];
    printf("Digite uma palavra: ");
    scanf("%s", origem);
    char *p = origem;
    int contador = 0;

    while (*p != '\0') {
        destino[contador] = *p;
        contador++;
        p++;
    }
    printf("String origem: %s\n", origem);
    printf("String destino: %s", destino);
}

int somaRecursiva(int v[], int n) {
    if (n == 0) {
        return 0;
    }

    if (n >= 1) {
        return v[n - 1] + somaRecursiva(v, n - 1);
    }
}

void exec9() {
    int n;
    printf("Informe a quantidade de valores:\n");
    scanf("%d", &n);
    int v[n];
    int soma = 0;
    for (int i = 0; i < n; i++) {
        printf("Informe o %dº valor:\n", i + 1);
        scanf("%d", &v[i]);
    }

    soma = somaRecursiva(v, n);

    printf("A soma dos valores passados é: %d", soma);
}

int ehPalindromo(char str[], int inicio, int fim) {
    // Caso base
    if (inicio >= fim) {
        return 1; // é palíndromo
    }

    // Se as letras forem diferentes
    if (str[inicio] != str[fim]) {
        return 0; // não é palíndromo
    }

    // Chamada recursiva
    return ehPalindromo(str, inicio + 1, fim - 1);
}

void exec10() {
    char c[100];

    printf("Digite uma string: ");
    scanf("%s", c);

    c[strcspn(c, "\n")] = '\0';

    int tamanho = strlen(c);

    if (ehPalindromo(c, 0, tamanho - 1)) {
        printf("É palíndromo\n");
    } else {
        printf("Não é palíndromo\n");
    }
}

typedef struct {
    char *nome;
    int idade;
    float nota;
} Aluno;

void imprimeString(char *str) {
    if (*str == '\0') {
        return;
    }
    printf("%c", *str);
    imprimeString(str + 1);
}

int comprimentoString(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + comprimentoString(str + 1);
}

void exec11() {
    int n, i;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &n);
    getchar();

    Aluno **alunos = (Aluno **) malloc(n * sizeof(Aluno*));

    for (i = 0; i < n; i++) {
        alunos[i] = (Aluno *) malloc(sizeof(Aluno));

        char buffer[100];

        printf("\nDigite o nome do aluno %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        int len = comprimentoString(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        alunos[i]->nome = (char *) malloc((len + 1) * sizeof(char));

        for (int j = 0; j < len; j++) {
            alunos[i]->nome[j] = buffer[j];
        }
        alunos[i]->nome[len] = '\0';

        printf("Digite a idade: ");
        scanf("%d", &alunos[i]->idade);

        printf("Digite a nota: ");
        scanf("%f", &alunos[i]->nota);
        getchar();
    }

    printf("\n=== Lista de Alunos ===\n");

    for (i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        imprimeString(alunos[i]->nome);
        printf("\nIdade: %d\n", alunos[i]->idade);
        printf("Nota : %.2f\n", alunos[i]->nota);
    }

    for (i = 0; i < n; i++) {
        free(alunos[i]->nome);
        free(alunos[i]);
    }
    free(alunos);

}

typedef struct {
    int matricula;
    char *nome;
    char *endereco;
    char *telefone;
} Aluno2;

void copiaString(char *dest, char *origem) {
    while (*origem != '\0') {
        *dest = *origem;
        dest++;
        origem++;
    }
    *dest = '\0';
}

void exec12() {
    int i;

    int total = 3;

    Aluno2 **tabela = (Aluno2 **) malloc(total * sizeof(Aluno2*));

    int matriculas[] = {101, 102, 103};

    char *nomes[] = {
        "Ana Silva",
        "Carlos Santos",
        "Mariana Oliveira"
    };

    char *enderecos[] = {
        "Rua das Flores, 123",
        "Av. Brasil, 456",
        "Rua Central, 789"
    };

    char *telefones[] = {
        "(11) 99999-1111",
        "(21) 98888-2222",
        "(31) 97777-3333"
    };

    for (i = 0; i < total; i++) {
        tabela[i] = (Aluno2*) malloc(sizeof(Aluno2));

        tabela[i]->matricula = matriculas[i];

        int lenNome = comprimentoString(nomes[i]);
        int lenEndereco = comprimentoString(enderecos[i]);
        int lenTelefone = comprimentoString(telefones[i]);

        tabela[i]->nome = (char*) malloc((lenNome + 1) * sizeof(char));
        tabela[i]->endereco = (char*) malloc((lenEndereco + 1) * sizeof(char));
        tabela[i]->telefone = (char*) malloc((lenTelefone + 1) * sizeof(char));

        copiaString(tabela[i]->nome, nomes[i]);
        copiaString(tabela[i]->endereco, enderecos[i]);
        copiaString(tabela[i]->telefone, telefones[i]);
    }

    printf("\n=== TABELA DE ALUNOS ===\n");

    for (i = 0; i < total; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Matrícula: %d\n", tabela[i]->matricula);

        printf("Nome: ");
        imprimeString(tabela[i]->nome);
        printf("\n");

        printf("Endereço: ");
        imprimeString(tabela[i]->endereco);
        printf("\n");

        printf("Telefone: ");
        imprimeString(tabela[i]->telefone);
        printf("\n");
    }

    for (i = 0; i < total; i++) {
        free(tabela[i]->nome);
        free(tabela[i]->endereco);
        free(tabela[i]->telefone);
        free(tabela[i]);
    }
    free(tabela);
}

int main(void) {
    int opc = 0;
    do {
        printf("\nMENU\n");
        printf("[1] - Exercício 1\n");
        printf("[2] - Exercício 2\n");
        printf("[3] - Exercício 3\n");
        printf("[4] - Exercício 4\n");
        printf("[5] - Exercício 5\n");
        printf("[6] - Exercício 6\n");
        printf("[7] - Exercício 7\n");
        printf("[8] - Exercício 8\n");
        printf("[9] - Exercício 9\n");
        printf("[10] - Exercício 10\n");
        printf("[11] - Exercício 11\n");
        printf("[12] - Exercício 12\n");
        printf("[13] - Sair\n");
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
                exec4();
                break;
            case 5:
                exec5();
                break;
            case 6:
                exec6();
                break;
            case 7:
                exec7();
                break;
            case 8:
                exec8();
                break;
            case 9:
                exec9();
                break;
            case 10:
                exec10();
                break;
            case 11:
                exec11();
                break;
            case 12:
                exec12();
                break;
            default:
                printf("Opção inválida!");
        }

    }while (opc !=13);
}