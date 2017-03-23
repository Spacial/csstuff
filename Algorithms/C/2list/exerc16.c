/*
16. Diferença de Vetores

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

#define DEBUG 2

#define MAXTAM 100

int dv(int *v,int a, int *u, int p, int l);

void mostra(int *seq, int tam);

void mostrad(int *seq, int destaque, int tam);

int levetor(int *v, int l);

int main(){
    int *v=NULL, *u=NULL, a=0, p=0, l=0, lv=0, lu=0;
    scanf("%d",&a);
    scanf("%d",&p);
    scanf("%d\n",&l);
    lv=levetor(v,l);
    lu=levetor(u,l);
    if (DEBUG) {
        printf("L- v: %d\n   u: %d\n",lv,lu);
        mostra(v,l-1);
        mostra(u,l-1);
    }
    if ((lv-a) == (lu-p)){
        printf("L: %d\n",l);
        printf("Resposta: %d\n",dv(v,a,u,p,l-1));
    } else {
        printf("Alguma coisa errada:\n");
        printf("\t a: %d, l: %d, v:\n",a,l);
        mostra(v,l);
        printf("\t p: %d, u:\n",p);
        mostra(u,l);
    }

    return 0;
}

int dv(int *v,int a, int *u, int p, int l){
    if ((a==0) && (p==0)){
         mostra(v,l);
         printf(" v[a]: %d, u[p]:%d\n",v[a],u[p]);
         mostra(u,l);
    }
    if (DEBUG){
            printf(" a: %d, p:%d, l: %d\n",a,p,l);
    }
    if ( a > l ){
        if (DEBUG > 1){
            printf(" %d a > l %d\n",a,l);
        }
        return l+1;
    }
    if (v[a] != u[p]) {
        if (DEBUG > 1){
            printf(" %d v[a] != v[p] %d\n",v[a],u[p]);
        }
        return a;
    } else {
        if (DEBUG > 1){
            printf(" a: %d, p:%d, l: %d\n",a,p,l);
        }
        return dv(v,a+1,u,p+1,l);
    }
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

int levetor(int *v,int l){
    int lido=0,tam=0;
	v = malloc(sizeof(int)*MAXTAM);
	while((tam < l) && (scanf("%d",&lido)==1)){
        v[tam]=lido;
        tam++;
	}
    if (DEBUG > 2){
                printf("Eu li:\n");
                mostra(v,tam);
    }
	return tam;
}
