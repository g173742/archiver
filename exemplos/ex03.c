#include <stdio.h>

/** ponteiro como vetor */
int main(){
    int *x;
    int y[4]={1,2,3,4};
    x=&y[1];
    printf("%d\n",x[0]);
    printf("%d\n",x[1]);
    (*x)++;
    (*(x+1))++;
    (*(x+2))++;
    printf("---\n");
    printf("%d\n",y[1]);
    printf("%d\n",y[2]);
    printf("%d\n",y[3]);
    
    
}