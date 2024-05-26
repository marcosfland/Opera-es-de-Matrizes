#include <stdio.h>

#define max_lin 7
#define max_col 7

int lin1, col1, lin2, col2;
int matriz_1[max_lin][max_col];
int matriz_2[max_lin][max_col];
int result[max_lin][max_col];
int termo;

void solicita_matriz(int matriz[max_lin][max_col], int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Digite o termo [%d][%d]: ", i, j);
            scanf("%d", &termo);
            matriz[i][j] = termo;
        }
    }
}

void imprime_matriz(int matriz[max_lin][max_col], int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplica_matrizes(int matriz1[max_lin][max_col], int matriz2[max_lin][max_col], int lin1, int col1, int lin2, int col2)
{
    if (col1 != lin2)
    {
        printf("Impossivel multiplicar as matrizes. O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda matriz.\n");
        return;
    }

    for (int i = 0; i < lin1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    printf("Resultado da multiplicacao:\n");
    imprime_matriz(result, lin1, col2);
}

void divide_matrizes(int matriz1[max_lin][max_col], int matriz2[max_lin][max_col], int lin1, int col1, int lin2, int col2)
{
    if (lin1 != lin2 || col1 != col2)
    {
        printf("Impossivel dividir as matrizes. As matrizes devem ter a mesma dimensao.\n");
        return;
    }

    for (int i = 0; i < lin1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            if (matriz2[i][j] == 0)
            {
                printf("Impossivel dividir por zero.\n");
                return;
            }
            result[i][j] = matriz1[i][j] / matriz2[i][j];
        }
    }

    printf("Resultado da divisao:\n");
    imprime_matriz(result, lin1, col1);
}

int main(void)
{
    int opcao;

    printf("Digite o numero de linhas da primeira matriz: ");
    scanf("%d", &lin1);
    printf("Digite o numero de colunas da primeira matriz: ");
    scanf("%d", &col1);

    solicita_matriz(matriz_1, lin1, col1);
    imprime_matriz(matriz_1, lin1, col1);

    printf("Digite a opcao desejada:\n");
    printf("1 - Multiplicar matrizes\n");
    printf("2 - Dividir matrizes\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            printf("Digite o numero de linhas da segunda matriz: ");
            scanf("%d", &lin2);
            printf("Digite o numero de colunas da segunda matriz: ");
            scanf("%d", &col2);

            solicita_matriz(matriz_2, lin2, col2);
            imprime_matriz(matriz_2, lin2, col2);

            multiplica_matrizes(matriz_1, matriz_2, lin1, col1, lin2, col2);
            break;

        case 2:
            printf("Digite o numero de linhas da segunda matriz: ");
            scanf("%d", &lin2);
            printf("Digite o numero de colunas da segunda matriz: ");
            scanf("%d", &col2);

            solicita_matriz(matriz_2, lin2, col2);
            imprime_matriz(matriz_2, lin2, col2);

            divide_matrizes(matriz_1, matriz_2, lin1, col1, lin2, col2);
            break;

        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}