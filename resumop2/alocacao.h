#include "constantes.h"
#include "baixonivel.h"
#ifndef ALOCACAO_H
#define ALOCACAO_H

FILE* abrirParada(int topico){
        switch (topico){
            case tipagem:
                return fopen("tipagem.txt","rb");
                break;
            case funcoes:
                return fopen("funcoes.txt","rb");
            case ponteiros:
                return fopen("ponteiros.txt","rb");
            case compostos:
                return fopen("compostos.txt","rb");
            case arquivos:
                return fopen("arquivos.txt","rb");
            case encadeadas:
                return fopen("encadeadas.txt","rb");
            case alocacao:
                return fopen("alocacao.txt","rb");
            deafult:
                return NULL;
                break;
        }
}

void MostrarTopico(int topico){
    FILE* arq=abrirParada(topico);
    assert(arq!=NULL);
    int numtopicos=0;
    char lido;
    No* topicos=NULL; No* ultimo=NULL;
    fseek(arq,0,SEEK_SET);
    while(fread(&lido,sizeof(char),1,arq)){ //percorre o arquivo olhando os topicos
        int indiceInicio=ftell(arq);
        int indicefinal;
        if(lido==novotopico){
            // assert(0 && "cheguei ate aqui4");
            numtopicos++;
            while(fread(&lido,sizeof(char),1,arq)){ //enquanto le e nao encontra um :
                if(lido==':'){
                    indicefinal=ftell(arq);
                    // assert(0 && "cheguei ate aqui5");
                    break;
                }
            }
            int tam=indicefinal-indiceInicio;
            // assert(0 && "cheguei ate aqui6");
            InsereEnc(&topicos,numtopicos,tam+1,&ultimo);
        }
    }
    // assert(0 && "cheguei ate aqui10");
    fseek(arq,0,SEEK_SET);
    int indice=0;
    No* informacoes=NULL; ultimo=NULL;
    while(fread(&lido,sizeof(char),1,arq) && indice<numtopicos){ //percorre o arquivo olhando os topicos
        int indiceInicio=ftell(arq);
        int indicefinal;
        if(lido==inicioinfo){
            while(fread(&lido,sizeof(char),1,arq)){ //enquanto le e nao encontra um ~
                if(lido==finalinfo){
                    indicefinal=ftell(arq);
                    break;
                }
            }
            int tam=indicefinal-indiceInicio;
            InsereEnc(&informacoes,indice,tam+1,&ultimo); //cria lista encadeada de informacoes, com seu respectivo indice, e tamanho a ser alocado
        }
    }
    // assert(0 && "cheguei ate aqui11");
    No* p=topicos; No* q=informacoes; //
    fseek(arq,0,SEEK_SET);
    indice=0;

    while(fread(&lido,sizeof(char),1,arq)){ //percorre o arquivo preenchendo os vetores de topicos e de informacoes
        if(lido==novotopico && p!=NULL){
            indice++;
            int j=0;
            while(fread(&lido,sizeof(char),1,arq)){ //le, e quando ver um : para de preencher o topico
                p->nome[j]=lido;
                if(lido==':'){
                    p->nome[j]=lido;
                    p->nome[j+1]='\0';
                    break;
                }
                j++;
            }
            p=p->prox;
                // assert(0 && "cheguei ate aqui, lendo o topico");
        }
        if(lido==inicioinfo && q!=NULL){
            int j=0;
            while(fread(&lido,sizeof(char),1,arq)){ //enquanto le e nao encontra um ~
                q->nome[j]=lido;
                if(lido==finalinfo){
                    q->nome[j]='\0';
                    break;
                }
                j++;
                // assert(0 && "cheguei ate aqui, lendo a informacao");
            }
            q=q->prox;// anda pro proximo no de info
        }
        // assert(0 && "cheguei ate aqui, li uma informacao ou topico");
    }
    // assert(0 && "cheguei ate aqui13");
    indice=exibeTopicos(topicos)-1;
    p=topicos; q=informacoes;
    int j=0;
    while(p!=NULL && q!=NULL){
        if(j==indice){
            printf("%s ",p->nome);
            printf("%s ",q->nome);
            break;
        }
        j++;
        p=p->prox;
        q=q->prox;
    }
    puts("");
    fclose(arq);
}

#endif