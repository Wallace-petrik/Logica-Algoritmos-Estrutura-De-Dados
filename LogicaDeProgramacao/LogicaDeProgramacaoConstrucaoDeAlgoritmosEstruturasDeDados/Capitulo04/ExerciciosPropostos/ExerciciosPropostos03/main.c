#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tan 10

int main(){
    setlocale(LC_ALL,"");

    int vet[tan];
    int sequencia = 1,maiorSequencia = 0;

    for(int i = 0; i < tan; i++){
        printf("\nEntre com o %d� n�mero: ",1+i);
            scanf("%d",&vet[i]);
    }

    for(int i = 0; i < tan; i++){
        if(vet[i] <= vet[i+1]){
            sequencia++;
        }else if(sequencia>maiorSequencia){
            maiorSequencia=sequencia;
            sequencia = 0;
        }
    }

    if(maiorSequencia==0){
        printf("N�o temos nenhuma sequencia!");
    }else{
        printf("\nA maior sequencia � %d.",maiorSequencia);
    }

    return 0;
}
