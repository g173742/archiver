#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    char x,ret;
    //nome,r=read
    fp = fopen ("arquivo.txt", "r");
    
    //verificar sucesso
    if(fp==NULL){
        printf("Arquivo Inexistente\n");
        exit(1);
    }
    
    
    ret = fscanf(fp,"%c",&x);
    
    while(ret!=EOF){
        printf("%c",x);
        ret = fscanf(fp,"%c",&x);
        
    }
    fclose(fp);
    
    return(0);
}






