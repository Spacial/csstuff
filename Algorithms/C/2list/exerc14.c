/*
        VERSÃO RECURSIVA
14. Seja p um vetor de números racionais indexado por [a..b]. Dados c ≤ d ∈ [a..b], vamos
denotar por pc,d o polinômio pc,d(x) .

Por exemplo, se p é o vetor dado por

i    0  1  2  3  4  5
p[i] 4  8 15 16 23 42

então,
        p0,5 (x) = 4x^0 + 8x^1 + 15x^2 + 16x^3 + 23x^4 + 42x^5 ,
e

        p2,4 (x) = 15x^0 + 16x^1 + 23x^2.

formato da entrada:
a b
p[0..i]

exemplo (1º):
0 5
4 8 15 16 23 42

Obs: para fazer como mostrar o polinomio feito, acabou saindo a versão iterativa ;)
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

float pcd(int *v, int a, int b, float x, int c);

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
    printf("p_%d,%d(%0.2f) = %0.2f \n",a,b,x,pcd(v,a,b,x,0));
    return 0;
}

// Requisitos: sempre b>=a, b < tam

float pcd(int *v, int a, int b, float x, int c){
    float r = 0;
    r= v[a]*expon(x,c);
    if (DEBUG){
        printf(">> r: %0.2f, v[%d]: %d, x: %0.2f, b: %d, c: %d\n",r,a,v[a],x,b,c);
    }
    if (a == b)
        return r;
    else
        return r+pcd(v,a+1,b,x,c+1);
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
