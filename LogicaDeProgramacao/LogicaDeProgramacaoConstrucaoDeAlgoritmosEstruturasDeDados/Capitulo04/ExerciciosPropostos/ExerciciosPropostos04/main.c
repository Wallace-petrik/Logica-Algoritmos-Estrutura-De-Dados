#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5

int main(){
    setlocale(LC_ALL,"");

    float notas[tam];
    float media = 0,soma = 0,acima = 0,abaixo = 0;

    for(int i = 0; i < tam; i++){
        printf("\nEntre com a %d� nota: ",i+1);
            scanf("%f",&notas[i]);
            soma += notas[i];
    }

    media = soma/tam;

    for(int i = 0; i < tam  ; i++){
        if(notas[i]>media+(media*0.1)){
            acima++;
        }else if(notas[i]<media-(media*0.1)){
            abaixo++;
        }
    }
    printf("\nM�dia = %.1f.\n10%% acima da m�dia %.1f.\n10%% abaixo da m�dia %.1f\n\n",media,acima,abaixo);
    return 0;
}
