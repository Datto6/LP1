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
int Busca(Caixa* L, int x){
    Caixa* p=L;
    while(p!=NULL){
        if(p->valor==x){
            return 1;
        }
        p=p->prox;
    }
    return 0;
}
Caixa* removeLista(Caixa* L,int valor){
    Caixa* p=L;
    Caixa* pAnt=NULL;
    while(p!=NULL){
        if(p->valor==valor){
            if(pAnt==NULL){
                L=p->prox;
            }
            else{
                pAnt->prox=p->prox;
            }
            break;
        }
        else{
            pAnt=p;
            p=p->prox;
        }

    }
    return L;
}
Caixa * Concatena0rep(Caixa * L1, Caixa * L2) { //concatena duas listas encadeadas, sem repeticoes
	struct Caixa * p=L1;
	Caixa * L=NULL;
	Caixa * u=NULL;
	while (p!=NULL){
		InsereFinal(&L,p->valor,&u);
		p=p->prox;
	}
	p=L2;
	while (p!=NULL){
		if(!Busca(L1,p->valor)){
            InsereFinal(&L,p->valor,&u);
	    }
        p=p->prox;
    }
    return L;
}



int main(void){
    Caixa* cabeca=NULL;
    Caixa* ultimo=NULL;
    InsereFinal(&cabeca,1,&ultimo);
    InsereFinal(&cabeca,3,&ultimo);
    InsereFinal(&cabeca,4,&ultimo);
    InsereFinal(&cabeca,7,&ultimo);
    InsereFinal(&cabeca,8,&ultimo);
    exibe(cabeca);
    Caixa* cabeca2=NULL;
    Caixa* ultimo2=NULL;
    InsereFinal(&cabeca2,-10,&ultimo2);
    InsereFinal(&cabeca2,3,&ultimo2);
    InsereFinal(&cabeca2,7,&ultimo2);
    InsereFinal(&cabeca2,101,&ultimo2);
    InsereFinal(&cabeca2,110,&ultimo2);
    cabeca=Concatena0rep(cabeca,cabeca2);
    exibe(cabeca);
    return 0;
}
