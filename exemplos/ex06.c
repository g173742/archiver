#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/** alocacao dinamica de um vetor */

int main(){
    int n=5;
    int *x;
    x = (int *)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        x[i]=i;
    }
    for(int i=0;i<5;i++){
        printf("%d-",x[i]);
    }
    
    printf("\n");
    free(x);
    
    
}