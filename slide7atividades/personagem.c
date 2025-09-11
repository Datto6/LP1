# include <stdio.h>
struct Personagem{
    int forca;
    int energia;
    int experiencia;
};

struct Personagem preencheA(void){
    struct Personagem retorno;
    scanf("%d",&retorno.forca);
    scanf("%d",&retorno.energia);
    scanf("%d",&retorno.experiencia);
    return retorno;
}

void preencheB(struct Personagem* ptr){
    scanf("%d",&ptr->forca);
    scanf("%d",&ptr->energia);
    scanf("%d",&ptr->experiencia);
}

int main(void){
    struct Personagem p1=preencheA();
    struct Personagem p2;
    preencheB(&p2);
    printf("%d %d\n",p1.forca, p2.forca);
    return 0;
}
