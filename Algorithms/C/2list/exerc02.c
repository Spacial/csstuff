/*
2. Fatorial - versão recursiva
   (para versão iterativa, ver exerc10)

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG = 0

double fat(int n);

int main(){
    int n=0;
    scanf("%d",&n);
    printf("Fatorial de %d, é %.0lf\n",n,fat(n));
    return 0;
}

double fat(int n){
    if (n == 1)
        return 1;
    else
        return n*fat(n-1);
}
