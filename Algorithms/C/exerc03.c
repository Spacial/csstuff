/*
3. Uma agência governamental deseja conhecer a distribuição da população do paı́s por faixa salarial.
    Para isto, coletou dados do último censo realizado e criou um arquivo contendo, em cada linha, a idade
    de um cidadão particular e seu salário. As idades variam de zero a 110 e os salários variam de zero a
    19.000,00 unidades da moeda local (salário do seu dirigente máximo).
    As faixas salariais de interesse são as seguintes:
        • de 0 a 3 salários mı́nimos
        • de 4 a 9 salários mı́nimos
        • de 10 a 20 salários mı́nimos
        • acima de 20 salários mı́nimos.
    Sendo o salário mı́nimo igual a 450,00 unidades da moeda local.

    Faça um programa em C que leia o arquivo de entrada e produza como saı́da os percentuais da
    população para cada faixa salarial de interesse.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <assert.h>
//#include <limits.h>
//#include <stdbool.h>


int main(){
    int n = 1, total =  0, g1 = 0;
    int g2 = 0,  g3 = 0, g4 = 0;
    float s, min = 450.0;
    float s1 = 0.0, s2 = 0.0;
    float s3 = 0.0, s4 = 0.0;
    while (n){
        scanf("%d %f\n",&n,&s);
//        printf("%d %f",n,s);
        if ((s >= 0.0) && (s <= (3 * min))) {
            g1++;
            s1 += s;
            total++;
        }
        else if ( (s >= (4 * min)) && (s <= (9 * min))) {
            g2++;
            s2 += s;
            total++;
        }
        else if ( (s >= (10 * min)) && (s <= (20 * min))) {
            g3++;
            s3 += s;
            total++;
        }
        else if (s > (20 * min)) {
            g4++;
            s4 += s;
            total++;
        }
    }
    printf("\n***** População total: %d", total);
    printf("\nTotal do G1: %d , média salarial: %f", (100*g1)/total, (s1/g1));
    printf("\nTotal do G2: %d , média salarial: %f", (100*g2)/total, (s2/g2));
    printf("\nTotal do G3: %d , média salarial: %f", (100*g3)/total, (s3/g3));
    printf("\nTotal do G4: %d , média salarial: %f", (100*g4)/total, (s4/g4));
    printf("\n");
    return 0;
}
