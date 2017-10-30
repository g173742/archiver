#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    int ra;
    float nota;
}Aluno;


/** construtor de um registro */

Aluno * novoAluno(int ra, float nota){
    Aluno * x = (Aluno *)malloc(sizeof(Aluno));
    x->ra=ra;
    x->nota=nota;
    return x;
}

void atualizaA(Aluno * a){
    a->nota++;
}
void imprimeA(Aluno *a){
    printf("%d %.2f\n",a->ra,a->nota);
}

int main(){
    
    Aluno *a = novoAluno(33,9);
    atualizaA(a);
    imprimeA(a);
    free(a);
    
    
}