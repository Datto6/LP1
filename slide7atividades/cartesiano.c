#include <stdio.h>
#include <math.h>

struct r2 { //pontos (x,y)
    int x;
    int y;
};

void preencheR2(struct r2* ptr,int x,int y){ //funcao p preencher ponto (x,y)
    ptr->x=x;
    ptr->y=y;
}
void vetorpontos(struct r2* lista,int tam){  //funcao q preenche lista de pontos 
    for (int i=0;i<tam;i++){
        struct r2 coisa;
        lista[i]=coisa;
        preencheR2(&coisa,i,tam-i);
    }
}

struct r2 distmax(struct r2 p1, struct r2 p2){  //funcao q retorna ponto com distancia max de (0,0)
    float dist1=sqrt(pow(p1.x,2)+pow(p1.y,2));
    float dist2=sqrt(pow(p2.x,2)+pow(p2.y,2));
    if (dist1>dist2){
        return p1;
    }
    if (dist2>dist1){
        return p2;
    }
    else {
        return p1;
    }
}

void escreverbonito(struct r2* lista,int xmax,int ymax){   //funcao p display de pontos (x,y), nao terminada!!!
    for (int i=0;i<=xmax;i++){
        printf("%d ",i);
    }
    printf("\n");
    for (int i=0;i<=ymax;i++){
        printf("%d\n",i);
    }
}
int main(void){
    struct r2 listazona[10];
    vetorpontos(listazona,10);
    struct r2 ponto1;
    struct r2 ponto2;
    preencheR2(&ponto1,3,4);
    preencheR2(&ponto2,19,15);
    printf("%d\n",distmax(ponto1,ponto2).x);
}
