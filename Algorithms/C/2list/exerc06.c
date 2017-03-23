/*
6. Reversão de vetor - recursivo
    (iterativo: 12 )
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

void revec(int *v, int a, int b);

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
    printf("O reverso é\n");
    revec(v,0,tam-1);
    mostra(v,tam);
    return 0;
}

// Requisitos: sempre b>=a
void revec(int *v, int a, int b){
    int x=0;
    if (a >= b)
        return;
    else {
        x=v[a];
        v[a]=v[b];
        v[b]=x;
        revec(v,a+1,b-1);
    }
        return ;

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
