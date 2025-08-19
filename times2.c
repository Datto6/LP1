#include <stdio.h>
struct Time{   //objeto para comparar times, depois poss
        char nome[3];
        int vitorias;
        int derrotas;
        int empates;
        int pontos;
    };

int main(void){
    struct Time lista_times[20];
    for (int i=1;i<=3;i++){
        struct Time time_novo;
        scanf("%s",time_novo.nome);
        scanf("%d",&time_novo.vitorias);
        scanf("%d",&time_novo.derrotas);
        scanf("%d",&time_novo.empates);
        time_novo.pontos=time_novo.vitorias*3+time_novo.empates;
        lista_times[i]=time_novo;
    }
    int min=50000; //valores arbitrários razoáveis para mínimo e máximo
    int max=-1;
    char nome_max[3];
    char nome_min[3];
    for (int i =1;i<=3;i++){

        if (lista_times[i].pontos>max){
            max=lista_times[i].pontos;
        }
        else if (lista_times[i].pontos<min){
            min=lista_times[i].pontos;
        }
    }
    for (int i =1;i<=3;i++){
        if (lista_times[i].pontos==max){
            for (int j=0;j<3;j++){ //e executado toda vez?
                nome_max[j]=lista_times[i].nome[j];
            }
            printf("Entrou1\n");
        }
        else if (lista_times[i].pontos==min){
            for (int j=0;j<3;j++){ //e executado toda vez?
                nome_min[j]=lista_times[i].nome[j];
            }
            printf("Entrou2\n");
        }
        printf("%s\n",nome_max);
    }
    printf("%d e o maximo de pontos, atingido pelo time %s\n",max,nome_max); //da erro no nome do max
    printf("%d e o minimo de pontos, atingido pelo time %s\n",min, nome_min);
    return 0;
}
