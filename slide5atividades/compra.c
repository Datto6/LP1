#include <stdio.h> 
void compra(int* conta, int valor){
    *conta= *conta-valor;
}
int main(void){
    int saldo1;
    int saldo2;
    int* ponteiro;
    scanf("%d %d",&saldo1,&saldo2);
    if (saldo1>saldo2){
        ponteiro=&saldo1;
    }
    else {
        ponteiro=&saldo2;
    }
    compra(ponteiro,500);
    printf("%d %d\n",saldo1,saldo2);
    return 0;
}
