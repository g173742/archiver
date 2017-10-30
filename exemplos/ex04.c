#include <stdio.h>
#include <string.h>

/** ponteiro percorrendo um vetor */
int busca(char v[], char k){
    for(int i=0;v[i]!='\0';i++){
        if(v[i]==k){
            return 1;
        }
    }
    
    return 0;
}

int busca2(char v[], char k){
    
    for(char *aux=&v[0];(*aux)!='\0';aux++){
        if((*aux)==k){
            return 1;
        }
    }
    
    return 0;
}


int main(){
    
    char v[100];;
    strcpy(v,"abcde");
    printf("%d\n",busca2(v,'x'));
    
    
}