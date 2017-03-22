/*
9. Um coeficiente binomial, geralmente denotado (n?k), representa o número de possı́veis combinações de n
    elementos tomados k a k. Um “Triângulo de Pascal”, uma homenagem ao grande matemático Blaise
    Pascal, é uma tabela de valores de coeficientes combinatoriais para pequenos valores de n e k. Os
    números que não são mostrados na tabela têm valor zero. Este triângulo pode ser construı́do auto-
    maticamente usando-se uma propriedade conhecida dos coeficientes binomiais, denominada “fórmula
    da adição": (r?k) = (r-1 ?k ) + (r-1 ? k-1) ou seja, cada elemento do triângulo é a soma de dois
    elementos da linha anterior, um da mesma coluna e um da coluna anterior. Veja um exemplo de um triângulo de
    Pascal com 7 linhas:
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1
    1 6 15 20 15 6 1

    Faça um programa em que imprima na tela um triângulo de Pascal com 10 linhas. Seu programa deve
    obrigatoriamente fazer uso de exatamente dois vetores durante o processo de construção. Um deles
    conterá a última linha ı́mpar gerada, enquanto que o outro conterá a última linha par gerada.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define RESET   "\033[1;25r"

#define DEBUG 0

#define TAMANHO 10

void mostra(int *seq, int tam);

void mostrad(int *seq, int destaque, int tam);

int main(){
 	int *bp = NULL, k=0, tam=1;
	bp = malloc(sizeof(int)*TAMANHO);
	for (int i=0; i < TAMANHO; i++)
        bp[i]=0;
	bp[0]=1;
	printf("1\n");
    do {
        if (DEBUG){
            printf("Loop>> k: %d, t: %d\n",k,tam);
        }
        bp[tam++] = 1;
        mostra(bp,tam);
        for(int i=(tam-1); i > 0; i--){
            bp[i] = bp[i-1] + bp[i];
        }
        k++;
    } while (k < TAMANHO);
    return 0;
}

void mostra(int *seq, int tam){
    mostrad(seq,-1,tam);
}

void mostrad(int *seq, int destaque, int tam){
    for(int x=0; x<tam;x++){
        if (x==destaque)
            printf(ANSI_COLOR_RED"%d "ANSI_COLOR_RESET ,seq[x]);
        else
            printf("%d ",seq[x]);
	}
	printf("\n");
    if (DEBUG){
                printf("Mostrou com: dest: %d, tam: %d\n",destaque,tam);
    }
}
