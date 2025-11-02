#include <stdio.h>

void meio(FILE* arq,char inserido){
    fseek(arq, 0, SEEK_END);           
    long int fim = ftell(arq);          
    fseek(arq, fim / 2, SEEK_SET);      
    fputc(inserido, arq); 
}

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
    FILE* arq=fopen("ex2.txt","r+");
    long int teste=tamanho(arq);
    printf("%ld\n",teste);
    meio(arq,'A');

    long int teste1=tamanho(arq);
    printf("%ld\n",teste1);

    fclose(arq);
    return 0;
}
