#include <stdio.h>

/** ponteiro simples */

int main(){
    int *x;
    int y=1;
    x=&y;
    (*x)++;
    printf("%d\n",y);
}