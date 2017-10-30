#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    //codigo suicida.
    fp = fopen ("ex02.c", "w");
    fprintf(fp, "Este eh o meu primeiro arquivo\n");
    fprintf(fp, "Viva!\n");
    
    
    fclose(fp);
    
    return(0);
}
