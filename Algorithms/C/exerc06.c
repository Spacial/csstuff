/*
6. Escreva um programa em C para ler uma sequência de números inteiros, terminada em −1. Para
    cada número inteiro lido, o programa deve verificar se este número está na base binária, ou seja, se é
    composto apenas pelos dı́gitos 0 e 1. Caso o número esteja na base binária, o programa deve imprimir
    seu valor na base decimal. Caso contrário, deve imprimir uma mensagem indicando que o número
    não é binário. Ao final do programa deve ser impresso, em formato decimal, o maior número válido
    (binário) da sequência.
    Dica: dado o número 10011 em base binária, seu valor correspondente em base decimal será dado por
        1 ∗ 2^4 + 0 ∗ 2^3 + 0 ∗ 2^2 + 1 ∗ 2^1 + 1 ∗ 2^0 = 19
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 0
#define MAXCHAR 100

int main(){
    int n=0,i=0,tam=0;
    char t[MAXCHAR],*s=malloc(sizeof *s);
    double soma=0;
    do {
        scanf("%s",t);
        tam=strlen(t);
        if (DEBUG)
            printf("T:%s, TAM: %d\n",t,tam);
        strncpy(s,t,tam);
        if ( s[0] == '-')
            return 0;
        i=0;
        soma=0;
        do {
            if (( s[i] != '0' ) && ( s[i] != '1' )) {
                printf("Não é binário!\n");
                return 0;
            } else {
                if (s[i] == '1'){
                    soma += pow(2,tam-i-1);
                }
            }
            i++;
        } while (i < tam);
        printf("Decimal: %.0lf\n", soma);
    } while(!n);
    return 0;
}
