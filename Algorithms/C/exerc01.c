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

void numEsq(int n, int max){
    printf("%d",n);
    if (n == max)
        return;
     else {
        numEsq(n+1,max);
        printf("%d",n);
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    for(int i=1; i <= n; i++) {
        numEsq(1,i);
        printf("\n");
    }
    return 0;
}



//#include <stdlib.h>
//#include <stdio.h>
//
//#define MAX 10
//
//int main(int argc, char **argv){
//    printf("Hello World!");
//    return 0;
//}
//#define __STDC_WANT_LIB_EXT2__ 1
//
//#include <stdio.h>
//#include <stdlib.h>

//void get_y_or_n(void) {
//    char *response = NULL;
//    size_t len;
//    puts("Continue? [y] n: ");
//    if ((getline(&response, &len, stdin) < 0) || (len && response[0] == 'n')) {
//        free(response);
//        exit(0);
//    }
//    free(response);
// }
