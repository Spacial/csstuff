/*
QuickSort
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define RESET   "\033[1;25r"

#define DEBUG 0
#define TAMANHO 5000

void mostra(int v[TAMANHO], int tam);

void mostroca(int v[TAMANHO], int tam, int i, int j,int s);

int carregarray(int v[TAMANHO], int *elementos);

void socarrega(int v[TAMANHO], int tam);

void quicksort(int v[TAMANHO], int l, int r);

int partition(int v[TAMANHO], int l, int r);

void troca(int v[TAMANHO], int i, int j);

int main(){
    int elementos=0;
    int vetor[TAMANHO];
    if (carregarray(vetor,&elementos))
        return -1;
    printf("Vetor:\n");
    mostra(vetor,elementos);
    printf("Ordenado:\n");
    quicksort(vetor,0,elementos-1);
    mostra(vetor,elementos);
    return 0;
}

void quicksort(int v[TAMANHO], int l, int r){
    int s=0;
    if (DEBUG){
        printf("QS> %d,%d\n",l,r);
    }
    if (l < r){
        s = partition(v,l,r);
        if (DEBUG > 2 )
                printf("s: %d\n",s);
        if (DEBUG)
            mostroca(v,r,-1,-1,s);
        quicksort(v,l,s-1);
        quicksort(v,s+1,r);
    }
}

int partition(int v[TAMANHO], int l, int r){
    int pivo=v[r],i=l,j=l;
    if (DEBUG)
        printf("P> p:%d, v[%d], j: %d\n",pivo,i,j);

    for(j=l;j<r;j++){
        if (v[j] <= pivo){
            if (i!=j) {
                troca(v,i,j);
                if (DEBUG)
                    mostroca(v,r,i,j,-1);
            }
            i++;
        }
    }
    troca(v,i,r);
    return i;
}

void troca(int v[TAMANHO], int i, int j){
    if ((i > TAMANHO) || (j > TAMANHO))
        return;
    int x=v[i];
    if (DEBUG > 2)
        printf("Trocar: %d,%d\n",i,j);
    v[i]=v[j];
    v[j]=x;
}

void mostra(int v[TAMANHO], int tam){
    for (int i=0; i< tam; i++){
        printf("%d ",v[i]);
    }
    printf(" \n");
}

void mostroca(int v[TAMANHO], int tam,int i, int j,int s){
    for (int x=0; x< tam; x++){
        if (x==i)
            printf(ANSI_COLOR_GREEN"%d "ANSI_COLOR_RESET,v[x]);
        else if (x==j)
            printf(ANSI_COLOR_CYAN"%d "ANSI_COLOR_RESET,v[x]);
        else if (x==s)
            printf(ANSI_COLOR_YELLOW"%d "ANSI_COLOR_RESET,v[x]);
        else
            printf("%d ",v[x]);
    }
    printf(" \n");
}

int carregarray(int *v, int *elementos){
    scanf("%d\n",elementos);
    if (DEBUG)
        printf("Total de elementos a serem lidos: %d\n",*elementos);
    if (*elementos > TAMANHO) {
        printf("Total de elementos a serem lidos é maior que o #define, ajustar! \n Elementos: %d\n MAX: %d",*elementos,TAMANHO);
        return 1;
    }
    socarrega(v,*elementos);
    return 0;
}

void socarrega(int v[TAMANHO], int tam){
    if (DEBUG)
        printf("Lendo: %d elementos..\n",tam);
    for (int i=0; i< tam; i++){
        scanf("%d",&v[i]);
        if (DEBUG)
            printf(".%d.",v[i]);
    }
    if (DEBUG)
        printf("\n");
}
