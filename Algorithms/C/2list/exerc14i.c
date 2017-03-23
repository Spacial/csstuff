/*
14. VERSÃO ITERATIVA
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

#define DEBUG 1

#define MAXTAM 100

float pcd(int *v, int a, int b, float x);

void polinomio(int *seq, int a, int b);

void mostra(int *seq, int tam);

void mostrad(int *seq, int destaque, int tam);

float expon(int n,int x);

int main(){
    int *v=NULL, tam=0,a=0,b=0;
    int lido=0;
    float x=0;
	v = malloc(sizeof(int)*MAXTAM);
    scanf("%d %d %f\n",&a,&b,&x);
	while(scanf("%d ",&lido)==1){
        v[tam]=lido;
        tam++;
	}
    if (DEBUG){
        mostra(v,tam);
        polinomio(v,a,b);
        printf("Dados> a: %d, b: %d, x: %0.2f, tam: %d\n",a,b,x,tam);
    }
    printf("p_%d,%d(%0.2f) = %0.2f \n",a,b,x,pcd(v,a,b,x));
    return 0;
}

// Requisitos: sempre b>=a, b < tam

float pcd(int *v, int a, int b, float x){
    float r=0;
    for(int i=a; i<=b;i++) {
            r += (v[i]*expon(x,(i-a)));
            if (DEBUG){
                printf(">> r: %0.2f, v[%d]: %d, x: %0.2f, i-a: %d\n",r,i,v[i],x,i-a);
            }
    }
    return r;
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
    if (DEBUG > 2){
                printf("Mostrou com: dest: %d, tam: %d\n",destaque,tam);
    }
}

void polinomio(int *seq, int a, int b){
    printf("p_%d,%d(x)= ",a,b);
    for(int x=a; x<=b;x++){
        if ( x != b )
            printf("%d"ANSI_COLOR_RED"x"ANSI_COLOR_YELLOW"^"ANSI_COLOR_MAGENTA"%d"ANSI_COLOR_RESET" + ",seq[x],(x-a));
        else
            printf("%d"ANSI_COLOR_RED"x"ANSI_COLOR_YELLOW"^"ANSI_COLOR_MAGENTA"%d"ANSI_COLOR_RESET,seq[x],(x-a));
    }
    printf("\n");
}

float expon(int n,int x){
    if (x == 0)
        return 1.0;
    else
        return n*expon(n,x-1);
}
