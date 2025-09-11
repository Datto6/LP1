# include <stdio.h>
int tamanho (char* str){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
void concatena (char* d, char* o1, char* o2){
    int t1=tamanho(d);
    int t2=tamanho(o1);
    int t3=tamanho(o2);
    for (int i=0;i<t2+t3;){
        
    }
}
int main(void){
    printf("%d\n",tamanho("coisa"));
    return 0;
}
