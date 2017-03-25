/*
Números Granizo
*/
#include <stdio.h>
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

void granizo(int x);

int main(){
    int x=0;
    scanf("%d",&x);
    printf("\n");
    granizo(x);
    printf("\n");
    return 0;
}


void granizo(int x){
    if (x < 1)
        return;
    printf("%d ",x);
    if (x == 1)
        return;
    if ((x%2) == 0)
        return granizo(x/2);
    else
        return granizo((x*3)+1);
}
