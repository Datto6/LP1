#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
    int  idade;
    char nome[64];
    int  peso;
} Pessoa;

void preenchePessoa(int idade, char* nome, int peso, Pessoa* ptr){
    ptr->idade=idade;
    strncpy(ptr->nome,nome,64);
    ptr->peso=peso;
}

int main(void){
    Pessoa vec[10];
    for (int i=0;i<10;i++){
        int idade;
        int peso;
        char nome[64];
        scanf("%d",&idade);
        scanf("%d",&peso);
        scanf("%s",nome);
        preenchePessoa(idade,nome,peso,vec+i);
    }
    return 0;
}
