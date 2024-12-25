#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<ctype.h>
#define MAX_LEN_STR 256
#define INVALIDO -1
#define N_VOGAL 5
int lista_de_vogais[N_VOGAL] = {'a', 'e', 'i', 'o', 'u'};
bool e_vogal(char k, int *index)
{
    int i = 0;
    for (i = 0; i < N_VOGAL; i++)
    {
        if (lista_de_vogais[i] == tolower(k))
        {
            *index = i;
            return true;
        }
    }
    return false;
}
/**
 * Função que remove vogais e calcula a quantidade de vogais removidas
 * @param str string de entrada
 * @param vogais vetor de 5 posições que contabiliza a quantidade
 * de vogais removidas
 * @return A função atualiza os vetores str e vogais.
 */
void remove_vogais(char *str, int *vogais)
{
    char *inicio = str;
    char bucket[MAX_LEN_STR + 1];
    int k = 0;
    while (*str != '\0')
    {
        int index;
        if (e_vogal(*str, &index))
        {
            vogais[index]++;
            str++;
 
            continue;
        }
        bucket[k] = *str;
        k++;
        str++;
    }
    bucket[k] = '\0';
    strcpy(inicio, bucket);
};
void printfAll(int * vogais){
  int i =0;
  for(i=0; i< N_VOGAL; i++){
    printf("%c: %d\n", lista_de_vogais[i], vogais[i]);
  }
}
int main()
{
    int vogais[N_VOGAL] = {0, 0, 0, 0, 0};
    char word[MAX_LEN_STR + 1];
    scanf("%[^\n]%*c", word);
    remove_vogais(word, vogais);
    printf("%s\n", word);
    printfAll(vogais);
    return 0;
}