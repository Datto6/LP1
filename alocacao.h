
#include "constantes.h"
#ifndef ALOCACAO_H
#define ALOCACAO_H

void MostrarAlocacao(void){
    FILE* arq=fopen(ARQUIVO_ALOC,"rb");
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
                    q->nome[j]=lido;
                    q->nome[j+1]='\0';
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
    p=topicos; q=informacoes;
        printf("%s",p->nome);
        // assert(0 && "cheguei ate o final porra");

        printf("%s",q->nome[i]);
    puts("");//fins esteticos
    assert(0 && "para que eu quero ver essa printada da info");

    fclose(arq);
}

#endif