#include <stdio.h>
#define N 10
 
double mult_linha(double matriz[N][N], double original[N][N], int n, int linha, int coluna)
{
    int i = 0;
    double soma = 0;
    for (i = 0; i < n; i++)
    {
        soma += matriz[linha][i] * original[i][coluna];
    }
    return soma;
}
void copiar(double fonte[N][N], double destino[N][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            destino[i][j] = fonte[i][j];
        }
    }
}
void mult(double matriz[N][N], int n, double original[N][N], int original_tamanho)
{
    double matriz_atual[N][N];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matriz_atual[i][j] = mult_linha(matriz, original, n, i, j);
        }
    }
    copiar(matriz_atual, matriz, n);
}
void printAll(double matriz[N][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.3lf ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    double matriz[N][N];
    double matriz_copia[N][N];
    int i, j, n, k;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &matriz[i][j]);
            matriz_copia[i][j] = matriz[i][j];
        }
    }
    i = 0;
    for (i = 0; i < (k - 1); i++)
    {
        mult(matriz, n, matriz_copia, n);
    }
    printAll(matriz, n);
    return 0;
}