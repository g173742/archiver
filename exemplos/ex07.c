#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    int ra;
    float nota;
}Aluno;

/** alocacao dinamica de um registro */

int main(){
    
    Aluno *a;
    a = (Aluno *)malloc(sizeof(Aluno));
    a->ra=4;
    a->nota = 5.5;
    
    
    printf("%d %.2f\n",a->ra,a->nota);
    free(a);
    
    
}