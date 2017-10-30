#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** alocacao dinamica simples */

int main(){
    
    int *x;
    x = (int *)malloc(sizeof(int));
    (*x)=5;
    printf("%d\n",*x);
    x[0]++;
    printf("%d\n",x[0]);
    free(x);
    
    
}