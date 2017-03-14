/*
4. Aqui temos uma forma peculiar de realizar uma multiplicação entre dois números: multiplique o
    primeiro por 2 e divida o segundo por 2 até que o primeiro seja reduzido a 1. Toda vez que o primeiro
    for impar, lembre-se do segundo. Não considere qualquer fração durante o processo. O produto dos
    dois números é igual a soma dos números que foram lembrados. Exemplo: 53 × 26 =
    53      26       13       6       3       1
    26      52      104     208     416     832
    26 +            104 +           416 +   832 = 1378
    Faça uma função em C que receba dois reais e retorne a multiplicação dos dois, do modo como foi
    especificado acima. Não é permitido uso de vetores.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <assert.h>
//#include <limits.h>
//#include <stdbool.h>

#define DEBUG 0

int main(){
    int n = 1, temp = 0;
    float n1 = 0.0, n2 = 0.0;
    float total =  0.0;
    scanf("%f %f",&n1,&n2);
    while (n){
//    for (int n=n1; n >= 1; n--){
        temp = n1;
        if ((temp % 2) == 1){
            if (DEBUG){
                printf("soma-> %f : %f\n",total,n2);
            }
            total += n2;
        }
        n1 = temp/2;
        n2 = n2*2;
        if (DEBUG){
            printf("%d = %f : %f\n",temp,n1,n2);
        }
        if (temp == 1){
            n=0;
        }
    }
    printf("\n Total: %f\n", total);
    return 0;
}
