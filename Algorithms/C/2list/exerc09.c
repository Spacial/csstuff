/*
9. Minimo do vetor
    (versão iterativa, versão recursiva é o exercicio 01)

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

#define MAXTAM 100

int minvec(int *v, int a, int b);

void mostra(int *seq, int tam);

void mostrad(int *seq, int destaque, int tam);

int main(){
    int *v=NULL, tam=0;
    int  lido=0;
	v = malloc(sizeof(int)*MAXTAM);
	while(scanf("%d",&lido)==1){
        v[tam]=lido;
        tam++;
	}
    if (DEBUG){
             printf(" Dados do vetor, tam: %d último lido: %d \n",tam,lido);
    }
    lido=minvec(v,0,tam-1);
    printf("Minvec: %d\n",lido+1);
    mostrad(v,lido,tam);
    return 0;
}

// Requisitos: sempre b>=a
int minvec(int *v, int a, int b){
    int m=a;
    if (DEBUG > 2){
                mostrad(v,a,b);
    }
    for (int i=a;i<b; i++){
        if (a == b)
            return a;
        if (DEBUG > 1){
             printf(" Chamada: a: %d, b: %d, "ANSI_COLOR_YELLOW"i: %d"ANSI_COLOR_RESET ", v[i]: %d, v[a]: %d  >> ",a,b,i,v[i],v[a]);
        }
        if (v[i] < v[m]) {
            m = i;
            if (DEBUG){
               mostrad(v,i,b);
            }
        }
    }
    return m;
}
//
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
    if (DEBUG > 4){
                printf("Mostrou com: dest: %d, tam: %d\n",destaque,tam);
    }
}
