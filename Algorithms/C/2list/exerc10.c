/*
10. Fatorial - versão iterativa
   (para versão recursiva, ver exerc02)

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
    double r=1;
    do {
        r = r * n;
        n--;
    } while (n > 1);
    return r;
}
