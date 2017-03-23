/*
5. Fibonacci (recursivo)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG = 0

int fib(int n);

int main(){
    int n=0;
    scanf("%d",&n);
    // apresenta com n-1, pois é mais intuitivo
    // F(0) = 1, F(1) = 1, F(2)=2 e assim vai..
    printf(" O F(%d) é %d\n",n,fib(n-1));
    return 0;
}

int fib(int n){
    if (n <= 1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
