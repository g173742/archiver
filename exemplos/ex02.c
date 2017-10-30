#include <stdio.h>

/** ponteiro v[0] */
int main(){
    int *x;
    int y=1;
    x=&y;
    x[0]++;
    printf("%d\n",y);
}