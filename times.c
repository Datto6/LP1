#include <stdio.h>
struct Time{
        char nome[3];
        int vitorias;
        int derrotas;
        int empates;
        int pontos;
    };
int main(void){
    struct Time lista_times[20];
    for (int i=1;i<=20;i++){
        struct Time time_novo;
        scanf("%s",&time_novo.nome);
        scanf("%d",&time_novo.vitorias);
        scanf("%d",&time_novo.derrotas);
        scanf("%d",&time_novo.empates);
        time_novo.pontos=time_novo.vitorias*3+time_novo.empates;
        lista_times[i]=time_novo;
    }
    int min=50000;
    int max=-1;
    for (int i =1;i<=20;i++){

        if (lista_times[i].pontos>max){
            max=lista_times[i].pontos;
        }
        else if (lista_times[i].pontos<min){
            min=lista_times[i].pontos;
        }
        
    }
    printf("%d e o maximo de pontos\n",max);
    printf("%d e o minimo\n",min);
    return 0;
}