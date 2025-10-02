#include <stdio.h>
#include <string.h>
int main(void){
    char coisa[26];
    scanf("%s",coisa);
    FILE* arquivo1=fopen("/home/ime/aula/primeiro.txt","w");
    int max=strlen(coisa);
    for(int i=0;i<max;i++){
        fputc(coisa[i],arquivo1);
    }
    fclose(arquivo1);

    FILE* arquivo2=fopen("/home/ime/aula/primeiro.txt","r");
    char exibicao[26];
    for(int i=0;i<max;i++){
        int input=fgetc(arquivo2);
        if (input!=-1){
            exibicao[i]=(char)input;
        }
    }
    printf("%s \n",exibicao);
    fclose(arquivo2);
    return 0; 
}
