#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "alocacao.h"
int main(void){
    int input;
    while(1){
        printf("Qual materia voce quer ver? [1] Tipagem de dados [2] Funcoes [3] Ponteiros [4] Compostos [5]Arquivos [6] Listas encadeadas [7] Alocacao Dinamica");
        scanf("%d",&input);
        puts("");
        switch (input){
            case tipagem:
                // MostrarTipos();
                break;
            case funcoes:
                // MostrarFuncoes();
            case ponteiros:
                // MostrarPonteiros();
            case compostos:
                // MostrarCompostos();
            case arquivos:
                // MostrarArquivos();
            case encadeadas:
                // MostrarEncadeadas();
            case alocacao:
                MostrarAlocacao();
                // assert(0 && "cheguei ate aqui2");
            deafult:
                break;
        }
        if(input==sair){
            break;
        }
    }
}
