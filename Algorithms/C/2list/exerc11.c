/*
11. Exponenciação - interativo
    rec: 03

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG = 0

double expon(int n,int x);

int main(){
    int n=0, x=0;
    scanf("%d %d",&n,&x);
    printf("%d elevado a %d, é %.0lf\n",n,x,expon(n,x));
    return 0;
}

double expon(int n,int x){
    int i=1;
    double r=1;
    do {
        r = r*n;
        i++;
    } while (i<=x);
    return r;
}

