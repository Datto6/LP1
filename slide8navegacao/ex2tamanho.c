#include <stdio.h>


long int tamanho(FILE* arq){
    long int tamanho=0;
    int desnecessario;
    fseek(arq,0,SEEK_SET);
    while(fgetc(arq)!=EOF){
        tamanho++;
    }
    return tamanho;
}

int main(void){
    FILE* arq=fopen("ex2.txt","r");
    long int teste=tamanho(arq);
    printf("%ld\n",teste);
    fclose(arq);
    return 0;
}
