#include <stdio.h>
#include <string.h>

void escreva_string (FILE* f, char* str) { //porque colocar fopen e fclose dentro vai dar ruim?
    int max=strlen(str);
    for(int i=0;i<max;i++){
        fputc(str[i],f);
    }
}

int main(void){
    char coisa[26];
    scanf("%s",coisa);
    FILE* arquivo1=fopen("/home/ime/aula/terceiro.txt","w"); //isso aqui dentro da funcao da seg fault so quando uso vec
    int max=strlen(coisa);
    escreva_string(arquivo1,coisa);

    char vec[10][26];
    for(int i=0;i<10;i++){
        scanf("%s",vec[i]);
    }

    for(int i=0;i<10;i++){
        escreva_string(arquivo1,vec[i]);
        fputc('\n',arquivo1);
    }
    fclose(arquivo1);
    return 0; 
}
