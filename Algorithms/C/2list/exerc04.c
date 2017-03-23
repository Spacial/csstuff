/*
4. soma de vetor

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

int somavec(int *v, int a, int b);

void mostra(int *seq, int tam);

void mostrad(int *seq, int destaque, int tam);

int main(){
    int *v=NULL, a=0, b=0, tam=0;
    int  lido=0;
	v = malloc(sizeof(int)*MAXTAM);
	scanf("%d %d",&a,&b);
	while(scanf("%d,",&lido)==1){
        v[tam]=lido;
        tam++;
	}
    mostra(v,tam);
    printf("Somando de %d a %d\n",a,b);
    printf("A soma é: %d\n ",somavec(v,a,b));

    return 0;
}

// Requisitos: sempre b>=a
int somavec(int *v, int a, int b){
    if (a == b)
        return v[a];
    else
        return v[a]+somavec(v, a+1, b);

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
