/*
13. Verificação de um vetor se é palíndromo.
    VERSÃO RECURSIVA

Para testar todas entradas de uma vez:
  bash-$ for i in $(ls exerc13*in); do ./exerc13 < ${i}; done
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

int palin(int *v, int a, int b);

void mostra(int *seq, int tam);

void mostrad(int *seq, int destaque, int tam);

int main(){
    int *v=NULL, tam=0;
    int  lido=0;
	v = malloc(sizeof(int)*MAXTAM);
	while(scanf("%d ",&lido)==1){
        v[tam]=lido;
        tam++;
	}
    mostra(v,tam);
    if (palin(v,0,tam-1))
            printf("É palíndromo.\n");
    else
            printf("Não é palíndromo.\n");
    return 0;
}

// Requisitos: sempre b>=a
// retornos: 1 sim, 0 não.
int palin(int *v, int a, int b){
    if (a >= b)
            return 1;
    else {
         if (v[a] != v[b])
            return 0;
        else
            return palin(v,a+1,b-1);
    }
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
    if (DEBUG){
                printf("Mostrou com: dest: %d, tam: %d\n",destaque,tam);
    }
}
