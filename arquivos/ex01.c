#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    
    fp = fopen ("ex01.txt", "w");
    fprintf(fp, "Este eh o meu primeiro arquivo\n");
    fprintf(fp, "Viva!\n");
    
    
    fclose(fp);
    
    return(0);
}