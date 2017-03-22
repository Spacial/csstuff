/*
7. Suponha que um exército tenha 20 regimentos e que eles estão em processo de formação. Inicialmente o
    primeiro tem 1000 homens, o segundo 950, o terceiro 900, e assim por diante, até o vigésimo que tem 50.
   Suponhamos que a cada semana 100 homens são enviados para cada regimento, e no final da semana o
    maior regimento é enviado para o front. Imaginemos que o general do quinto regimento é companheiro
    de xadrez do comandante supremo, e que eles estão no meio de uma partida. O comandante supremo
    então envia apenas 30 homens para o quinto regimento a cada semana, esperando com isto poder
    acabar o jogo com seu colega. Escreva um programa em que diga, a cada semana, qual é o regimento
    enviado ao front e mostre o status dos outros regimentos. O programa deve também determinar
    exatamente quantas semanas levará o quinto regimento para ser deslocado ao front.
    1000 = (20 * 50) + (100 * semana)
     950 = (19 * 50) + (100 * semana)
     900 = (18 * 50) + (100 * semana)
     850 = (17 * 50) + (100 * semana)
     800 = (16 * 50) + (30 * semana)
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

int inicializa(int batalhoes[20]);

int front(int regimento, int valor);

int main(){
    int k = 0, reg,atual,max;
    int batalhoes[20];
    int jafoi[20];
    printf(" *** Envio pro front ***\n");
    if (inicializa(batalhoes)){
        printf(" *** erro ao inicializar o vetor ***\n");
        return -1;
    }
    for(int i=0; i< 20; i++){
        jafoi[i] = 0;
    }
    do {
        if (DEBUG){
                printf("Chamando seleciona pra semana: %d\n",k);
        }
	reg=-1;
	max=-1;
  	for (int i=0;i<20; i++){
                if (DEBUG){
                    printf("Descobrir o maior: buscando[%d]=%d\n",i,batalhoes[i]);
                }
                atual = front(i,batalhoes[i]);
                if ( (atual > max)  && (!jafoi[i])) {
                        if (DEBUG){
                            printf("um novo maior: atual[%d]=%d, max[%d] = %d\n",i,atual,max,reg);
                        }
                        max = atual;
                        reg = i;
                }
                batalhoes[i]=atual;
    	}
        if (!jafoi[reg])
            printf("Semana:"	ANSI_COLOR_GREEN	" %d\t "	ANSI_COLOR_RESET \
		   "Regimento enviado ao front: " ANSI_COLOR_GREEN	"%d\t" ANSI_COLOR_RESET \
		   "--  com "ANSI_COLOR_GREEN " %d "ANSI_COLOR_RESET  " homens.\n",k+1,reg+1,batalhoes[reg]);
        jafoi[reg]=1;
        k++;
    } while(k < 20);
    return 0;
}

int inicializa(int batalhoes[20]){
    for (int i=0;i<20; i++){
            batalhoes[i] = (20-i) * 50;
            if (DEBUG >= 3){
                    printf("Inicializei: [%d]=%d\n",i,((20-i)*50));
            }
    }
    return 0;
}

int front(int regimento, int valor){
    int delta = 100;
    if (regimento == 4)
        delta = 30;
    if (DEBUG >= 2){
        printf("Regimento: %d, homens: %d\n",regimento, valor);
    }
    return (valor + delta);
}
