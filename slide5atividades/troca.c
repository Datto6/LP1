#include <stdio.h>
void troca(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main(void){
    int x=10, y=20;
    troca(&x, &y);              // definir essa funcao
    printf("%d %d\n", x, y);
    return 0;
}
