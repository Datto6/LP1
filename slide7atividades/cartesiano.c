#include <stdio.h>

struct r2 {
    int x;
    int y;
};

void preencheR2(struct r2* ptr,int x,int y){
    ptr->x=x;
    ptr->y=y;
}
void vetorpontos(struct r2* lista,int tam){
    for (int i=0;i<tam;i++){
        lista[i].x=i;
        lista[i].y=tam-i;
    }
}
void escreverbonito(struct r2* lista,int xmax,int ymax){
    for (int i=0;i<=xmax;i++){
        printf("%d ",i);
    }
    printf("\n");
    for (int i=0;i<=ymax;i++){
        printf("%d\n",i);
    }
}
int main(void){
    struct r2* listazona[10];
    vetorpontos(listazona,10);
}
