/*
8. Dada uma sequência x1 , x2, . . . , xk de números reais, verifique se existem dois segmentos consecutivos
    iguais nesta sequência, isto é, se existem i e m tais que:
                xi , xi+1 , . . . , xi+m−1 = xi+m, xi+m+1, . . . , xi+2m−1 .
    Imprima, caso existam, os valores de i e de m. Caso contrário, não imprima nada. Exemplo: Na
    sequência 7,9,5,4,5,4,8,6, existem i = 3 e m = 2.

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

#define MAXNUMS 100


void mostra(float *seq,int tam);

void mostradq(float *seq, int destaque, int tam);

void mostratd(float *seq, int destaque, int i, int j,int tam);

int main(){
	int k = 0, inicio = 0, maxseq=0, atual=0, idx=0;
 	float *seq = NULL, lido=0;
	seq = malloc(sizeof(float)*MAXNUMS);
	while(scanf("%f,",&lido)==1){
        seq[k]=lido;
        k++;
	}
    if (DEBUG){
        printf("\n Total de nºs lidos: %d \n",k);
        mostra(seq,k);
    }
    for(int i=0;i<k; i++){
        for(int j=i+1; j<k; j++){
                while (seq[i+atual] == seq[j+atual]){
                        atual++;
                }
                    if (atual > maxseq) {
                        maxseq = atual;
                        idx=j-maxseq;
                        inicio=i;
                    }

            }
            atual=0;
        }

    if (idx > 1) {
        mostra(seq,k);
        printf("i: %d, m: %d\n",inicio+1,maxseq);
    } else {
        printf("Sem repetições encontradas!\n");
    }
    return 0;
}

void mostra(float *seq,int tam){
    mostratd(seq,-1,-1,-1,tam);
}


void mostradq(float *seq, int destaque, int tam){
    mostratd(seq, destaque, -1,-1,tam);
}

void mostratd(float *seq, int destaque, int i, int j,int tam){
    for(int x=0; x<tam;x++){
        if (x==destaque)
            printf(ANSI_COLOR_RED"%0.2f,"ANSI_COLOR_RESET ,seq[x]);
        else if (x==i)
            printf(ANSI_COLOR_BLUE"%0.2f,"ANSI_COLOR_RESET ,seq[x]);
        else if (x==j)
            printf(ANSI_COLOR_GREEN"%0.2f,"ANSI_COLOR_RESET ,seq[x]);
        else
            printf("%0.2f,",seq[x]);
	}
	printf("\n");
    if (DEBUG){
                printf("Mostrou com: dest: %d, i: %d, j: %d, tam: %d\n",destaque,i,j,tam);
    }
}
