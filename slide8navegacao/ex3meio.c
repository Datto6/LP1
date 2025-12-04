#include <stdio.h>

void meio(FILE* arq,char inserido){
    fseek(arq, 0, SEEK_END);           
    long int fim = ftell(arq);          
    fseek(arq, fim / 2, SEEK_SET);
    char* depois_metade[fim/2]; //alocacao dinamica, posso usar malloc aqui? nao encontrei muito outro jeito
    fread(depois_metade,sizeof(char),fim/2,arq); //ler todos os chars depois da metade
    fseek(arq, (fim / 2 ), SEEK_SET);     //voltar p metade
    fputc(inserido, arq);  //colocar o char desejado no meio
    fwrite(depois_metade,sizeof(char),fim/2,arq);  //colocar os outros da metade um para frente
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
