# include <stdio.h>
typedef struct Caixa{
    int valor;
    struct Caixa* prox;
}Caixa;

Caixa constroi(Caixa* prox){ 
    Caixa saida;
    saida.prox=prox; //nao "aloca" proximo sozinho, precisa que o programador ja informe
    scanf("%d",&saida.valor); //pega valor com usuario
    return saida; //retorna variavel local, precisa ser atribuido a um externo fora da função
}
void printar(Caixa* coisa){
    Caixa* p=coisa;
    while(p!=NULL){ //enquanto nao chegou ao final
        printf("%d",p->valor);
        p=p->prox;
        if (p!=NULL) printf(" ->"); 
    }
    printf("\n");
}
int main(void){
    Caixa coisa1;  Caixa coisa2;
    Caixa coisa3; Caixa coisa4; Caixa coisa5; //declaracoes de caixas
    coisa1=constroi(&coisa2);
    coisa2=constroi(&coisa3);
    coisa3=constroi(&coisa4);
    coisa4=constroi(&coisa5);
    coisa5=constroi(NULL); //NULL porque e o ultimo elemento da lista
    printar(&coisa1);
    return 0;
}
