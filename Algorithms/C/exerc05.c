/*
5. Um inteiro positivo N é perfeito se for igual a soma de seus divisores positivos diferentes de N .
    Exemplo: 6 é perfeito pois 1+2+3 = 6 e 1, 2, 3 são todos os divisores positivos de 6 e que são diferentes
            de 6.
    Faça um programa em C que recebe como entrada um número positivo K e mostre os K primeiros
    números perfeitos.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 0

double perfeito(double k);

int perfeitobruto(int k);

int main(){
    double k = 1;
    scanf("%lf",&k);
    printf("\nPerfeito: %lf\n",perfeito(k));
    return 0;
}


double perfeito(double k){
    if (DEBUG){
        printf("P recebe > %lf\n",k);
    }
    return ((pow(2,(k-1)) * (pow(2,k)-1)));
}


int perfeitobruto(int k){
    if (DEBUG){
        printf("P recebe > %d\n",k);
    }
    int soma=0;
    for(int i=1; i < k; i++){
    if (DEBUG){
        printf("for > %d -- %d\n",i,k);
        }
        if (!(k%i)){
            soma += i;
        }
    }
    return k-soma;
}
