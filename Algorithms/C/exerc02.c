/*
2. Adapte a solução do exercı́cio anterior para que a saı́da seja exatamente conforme especificada na
figura 2 (abaixo).

        1
       121
      12321
     1234321
    123454321
   12345654321
  1234567654321
 123456787654321
12345678987654321
 Figura 2

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
    n=9;
    for(int i=1; i <= n; i++) {
        for(int j=(n-i); j > 0; j--){
            printf(" ");
        }
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
