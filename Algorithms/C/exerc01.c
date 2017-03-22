/*
1. Faça um programa em C que imprima exatamente a saı́da especificada na figura 1 (abaixo) de maneira
que, em todo o programa, não apareçam mais do que três comandos de impressão.

1
121
12321
1234321
123454321
12345654321
1234567654321
123456787654321
12345678987654321
     Figura 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void numEsq(int n, int max);

int main(){
    int n;
// caso queira ler da entrada
//    scanf("%d",&n);
// fixado em 9 (pcausa do exercicio)
    n=9;
    for(int i=1; i <= n; i++) {
        numEsq(1,i);
        printf("\n");
    }
    return 0;
}

void numEsq(int n, int max){
    printf("%d",n);
    if (n == max)
        return;
     else {
        numEsq(n+1,max);
        printf("%d",n);
    }
}
