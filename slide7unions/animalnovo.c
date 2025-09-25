# include <stdio.h>

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
    }; //especia e nome do atributo union da struct animal
};
void preenchebicho(struct Animal* ptr,int tipo, int arr[]){ //funcao p preencher animal
    ptr->tipo=tipo;
    switch (ptr->tipo){
        case 0:
            ptr->anfibio.patas=arr[0];
            ptr->anfibio.espessura=arr[1];
            ptr->anfibio.cauda=arr[2];
            break;
        case 1:
            ptr->ave.cmbico=arr[0];
            ptr->ave.autonomia_voo=arr[1];
            ptr->ave.freqcanto=arr[2];
            break;
        case 2:
            ptr->mamifero.qnt_dentes=arr[0];
            ptr->mamifero.vol_cerebr=arr[1];
            ptr->mamifero.vel_terr=arr[2];
            break;
        case 3:
            ptr->reptil.venenoso=arr[0];
            ptr->reptil.autonomia_agua=arr[1];
            ptr->reptil.espess_ovos=arr[2];
            break;
    }
}
void array(int* arr, int x, int y, int z){
    arr[0]=x;
    arr[1]=y;
    arr[2]=z;
}
void exibe(struct Animal coisa){ //nao terminei ainda, falta reptil e pormenores do printf p testar
    switch (coisa.tipo){
        case 0: //anfibio
            printf("Numero de patas:%d \n",coisa.anfibio.patas);
            printf("Espessura da pele:%d \n",coisa.anfibio.espessura);
            printf("Cauda ? %d (1 significa sim, 0 nao)\n",coisa.anfibio.cauda);
            break;
        case 1: //ave
            printf("Numero de patas:%d reais\n",coisa.ave.cmbico);
            printf("Numero de patas:%d reais\n",coisa.ave.autonomia_voo);
            printf("Numero de patas:%d reais\n",coisa.ave.freqcanto);
            break;
        case 2: //mamifero
            printf("Numero de patas:%d reais\n",coisa.mamifero.qnt_dentes);
            printf("Numero de patas:%d reais\n",coisa.mamifero.vol_cerebr);
            printf("Numero de patas:%d reais\n",coisa.mamifero.vel_terr);
            break;
        case 3: //reptil

    }
}
int main(void){
    struct Animal bicho1; //sapo
    struct Animal bicho2; //macaco
    struct Animal bicho3;  //gorila
    struct Animal bicho4;  //cobra
    struct Animal bicho5;  //tartaruga
    struct Animal bicho6;  //aguia
    int arrayteste[3];
    array(arrayteste,5,5,5);

    preenchebicho(&bicho1,0,arrayteste);
    array(arrayteste,5,15,1);
    exibe(bicho1);
    preenchebicho(&bicho2,2,arrayteste);
    array(arrayteste,50,512,15);

    preenchebicho(&bicho3,2,arrayteste);
    array(arrayteste,03,52,54);

    preenchebicho(&bicho4,3,arrayteste);
    array(arrayteste,9,5,432);

    preenchebicho(&bicho5,0,arrayteste);
    array(arrayteste,553,35,1);

    preenchebicho(&bicho6,1,arrayteste);
    array(arrayteste,1,0,23);
}
