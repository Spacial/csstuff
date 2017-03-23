/*
15. Dados n, k ∈ N o coeficiente binomial nk
 é o número de subconjuntos de k elementos de
um conjunto de n elementos, e é dado por

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

#define DEBUG 0

#define MAXTAM 100

int cobin( int n, int k);

int main(){
    int n = 0, k =0;
    scanf("%d %d",&n,&k);
    printf("Coef. Bin (%d,%d): %d\n",n,k,cobin(n,k));
    return 0;
}

int cobin(int n, int k){
    if ( n < k)
        return 0;
    if ( k == 0)
        return 1;
    return cobin(n-1,k-1)+cobin(n-1,k);
}

