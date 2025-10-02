#include <stdio.h>
#include <string.h>
int main(void){
    char vec[10][26];
    FILE* arquivo1=fopen("/home/ime/aula/terceiro.txt","w");
    for(int i=0;i<10;i++){
        scanf("%s",vec[i]);
    }

    for(int i=0;i<10;i++){
        int max=strlen(vec[i]);
        for (int j=0;j<max;j++){
            fputc(vec[i][j],arquivo1);
        }
        fputc('\n',arquivo1);
    }
    fclose(arquivo1);
    return 0; 
}
