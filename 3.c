#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define N 1000
#define N_VOGAL 6
#define print_perfil(x) printf("(%d,%d,%d,%d,%d)\n", x[0], x[1], x[2], x[3], x[4])
#define PERFIL_VAZIO {0, 0, 0, 0, 0}
char lista_de_vogais[N_VOGAL] = {'a', 'e', 'i', 'o', 'u', '\0'};
int findchar(char *str, char value)
{
    int i;
    for (i = 0; *str != '\0'; str++, i++)
    {
        if (tolower(*str) == tolower(value))
        {
            return i;
        }
    }
    return -1;
}
int gera_perfil(char *str, int *perfil)
{
    while (*str != '\0')
    {
        int i;
        int index = findchar(lista_de_vogais, *str);
        if (index != -1)
        {
            perfil[index]++;
        }
 
        str++;
    }
}
double d_perfil(int *p1, int *p2)
{
    int i = 0;
    double soma = 0;
    for (i = 0; i < 5; i++)
    {
        soma += pow((p1[i] - p2[i]), 2);
    }
    return sqrt(soma);
}
 
int main()
{
    char t[(N * 2) + 2];
    scanf("%[^\n]%*c", t);
    int i, len = strlen(t), quant = 0;
    for (i = 0; i < len; i++)
    {
        if (t[i] == ';')
        {
            quant++;
        }
    }
 
    if (quant > 1 || quant < 1)
    {
        printf("FORMATO INVALIDO!\n");
        return 0;
    }
    char word[N + 1];
    int index = findchar(t, ';');
    for(i=0; i< index; i++){
       word[i] = t[i];
    }
    int perfil_word[5] = PERFIL_VAZIO;
 
    char str[N + 1];
    int j =0;
     for(i=index+1; i< len; i++, j++){
       str[j] = t[i];
    }
    int perfil_str[5] = PERFIL_VAZIO;
 
    gera_perfil(word, perfil_word);
    gera_perfil(str, perfil_str);
 
    print_perfil(perfil_word);
    print_perfil(perfil_str);
    printf("%.2lf\n", d_perfil(perfil_word, perfil_str));
    return 0;
}