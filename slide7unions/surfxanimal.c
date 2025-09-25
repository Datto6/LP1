# include <stdio.h>
#include <string.h>
struct Surfista{
    int borda;
    int aereo;
    int tubo;
    int tamanho_onda;
    int fraude;
    char nome[255];
};

struct Animal{
    int tipo; 
    union {
        struct anfibio{ //tipo=0
            int patas;
            int espessura;
            int cauda;
        } anfibio;
        struct ave{  //tipo =1
            int cmbico;
            int autonomia_voo;
            int freqcanto;
        } ave; //nome do atributo da union
        struct mamifero{ //tipo ==2
            int qnt_dentes;
            int vol_cerebr;
            int vel_terr;
        } mamifero;
        struct Reptil{  //tipo ==3
            int venenoso;
            int autonomia_agua;
            int espess_ovos;
        } reptil;
    } especie; //especia e nome do atributo union da struct animal
};

void preenchebicho(struct Animal* ptr,int tipo, int arr[]){ //funcao p preencher animal
    ptr->tipo=tipo;
    switch (ptr->tipo){
        case 0:
            ptr->especie.anfibio.patas=arr[0];
            ptr->especie.anfibio.espessura=arr[1];
            ptr->especie.anfibio.cauda=arr[2];
            break;
        case 1:
            ptr->especie.ave.cmbico=arr[0];
            ptr->especie.ave.autonomia_voo=arr[1];
            ptr->especie.ave.freqcanto=arr[2];
            break;
        case 2:
            ptr->especie.mamifero.qnt_dentes=arr[0];
            ptr->especie.mamifero.vol_cerebr=arr[1];
            ptr->especie.mamifero.vel_terr=arr[2];
            break;
        case 3:
            ptr->especie.reptil.venenoso=arr[0];
            ptr->especie.reptil.autonomia_agua=arr[1];
            ptr->especie.reptil.espess_ovos=arr[2];
            break;
    }
}

// void preencheB(struct Surfista* ptr){
//     scanf("%d",&ptr->borda);
//     scanf("%d",&ptr->aereo);
//     scanf("%d",&ptr->tubo);
//     scanf("%d",&ptr->tamanho_onda);
//     scanf("%d",&ptr->fraude);
//     scanf("%s",ptr->nome);
// }
void preencheSurf(struct Surfista* ptr, int arr[],char nome[]){
    ptr->borda=arr[0];
    ptr->aereo=arr[1];
    ptr->tubo=arr[2];
    ptr->tamanho_onda=arr[3];
    ptr->fraude=arr;
    strncpy(ptr->nome,nome,255);
}
struct entidade{
    int classe;
    union{
        struct Surfista;
        struct Animal;
    } conteudo;
};

void preencheEntidade(struct entidade* ptr, int classe,int arr[],char nome[],int tipo){
    if(ptr->classe==0){
        preencheSurf(ptr,arr,nome);
    }
    if (ptr->classe==1){
        preenchebicho(ptr,tipo,arr);
    }
}