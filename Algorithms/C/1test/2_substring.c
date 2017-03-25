#include <stdio.h>

#define DEBUG 0

#define MAX 200

void carrega(char f[MAX], int *tf, char p[MAX], int *tp);

void mostra(char p[MAX], int i, int f);

int busca(char f[MAX], int x, int y, char p[MAX], int v, int w);

int compara(char f[MAX], int x, char p[MAX], int v, int w);

int main() {
    char f[MAX],p[MAX];
    int tf=0, tp=0;
    if (DEBUG)
        printf("Lendo as strings:  \n");
    carrega(f, &tf, p, &tp);
    if (DEBUG){
        printf("tamanhos: f(%d) e p(%d)  \n",tf,tp);
        printf("F:  \n");
        mostra(f, 0, tf);
        printf("P:  \n");
        mostra(p, 0, tp);
    }
    printf("Ocorrencias de p em f: %d .\n",busca(f,0,tf,p,0,tp));
    return 0;
}

int busca(char f[MAX], int x, int y, char p[MAX], int v, int w){
    if ((y-x) < (w-v))
        return 0;
    return compara(f,x,p,v,w) + busca(f,x+1,y,p,v,w);
}

int compara(char f[MAX], int x, char p[MAX], int v, int w){
    for (int i=v; i<w;i++)
        if (f[x+i] != p[i])
            return 0;
    return 1;
}

void carrega(char f[MAX], int *tf, char p[MAX], int *tp) {
  int i;

  scanf("%d", tf);
  scanf("%d\n", tp);

  for(i = 0; i < *tf; i++)
      scanf("%c", &f[i]);
  scanf("\n");
  for(i = 0; i < *tp; i++)
      scanf("%c", &p[i]);
  scanf("\n");

}

void mostra(char p[MAX], int i, int f) {
  int c=0;
  for(c = i; c < f; c++)
      printf("%c", p[c]);
  printf("\n");
}
