#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
    int valor;
    struct Caixa* prox;
} Caixa ;

void InsereFinal(Caixa ** L, int e, Caixa ** u) {  
	Caixa * novo = (Caixa *) malloc(sizeof(Caixa)); //aloca as caixas aqui
	novo->valor = e; novo->prox = NULL; 
	if (*u == NULL) {
		*L = novo; //se o ultimo nao existir, comeca lista ali
	} else {
		(*u)->prox = novo; //ultimo agora e o novo 
	}
	*u = novo;  //atualiza o novo ultimo da lista 
}
void exibe(Caixa* coisa){
    Caixa* p=coisa;
    while(p!=NULL){ //enquanto nao chegou ao final
        printf("%d",p->valor);
        p=p->prox;
        if (p!=NULL) printf(" ->"); 
    }
    printf("\n");
}

void InsereInicioEnc(Caixa ** L, int e) { //funcoes auxiliares 
	Caixa * novo = (Caixa *) malloc(sizeof(Caixa));
	novo->valor = e; novo->prox = *L; *L = novo; 
}

int main(void){
    int input;
    Caixa* cabeca=NULL;
    Caixa* ultimo=NULL;
    while(1){
        printf("Insere ai seu numero p lista, digite -1 p parar ");
        scanf("%d",&input);
        if(input==-1) break;
        InsereFinal(&cabeca,input,&ultimo);
        printf("\n");
    }
    exibe(cabeca);
    return 0;
}
