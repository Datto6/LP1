#include <stdio.h>
#include <math.h>

struct caba { //pontos (x,y)
    int id;
    int x;
    int y;
};

void preencheCaba(struct caba* ptr,int id, int x,int y){ //funcao p preencher ponto (x,y)
    ptr->id=id;
    ptr->x=x;
    ptr->y=y;
}
void vetorpontos(struct caba* lista,int tam){  //funcao q preenche lista de pontos 
    for (int i=0;i<tam;i++){
        struct caba coisa;
        preencheCaba(&coisa,999-i,i,tam-i);
        lista[i]=coisa;
    }
}

struct caba distmax(struct caba p1, struct caba p2){  //funcao q retorna caba com distancia max de (0,0)
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

void escreverbonito(struct caba* lista,int quantos,int xmax,int ymax){   //funcao p display de pontos (x,y), nao terminada!!!
    for (int i=0;i<=xmax;i++){
        printf("%d ",i);
    }
    printf("\n");
    for (int i=0;i<=ymax;i++){
        printf("%d ",i);
        for(int j=0;j<=xmax;j++){
            for (int k=0;k<quantos;k++){
                if (lista[k].x==j && lista[k].y==i){
                    printf("%d",lista[k].id);
                    lista[k]=lista[quantos-1];
                    --quantos;
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}
void mostracoord(struct caba* listazona,int num){
    printf("%d %d %d\n",listazona[num].id,listazona[num].x,listazona[num].y);
}
int main(void){
    struct caba listazona[10];
    vetorpontos(listazona,10);
    mostracoord(listazona,0);
    escreverbonito(listazona,10,10,10);
}
