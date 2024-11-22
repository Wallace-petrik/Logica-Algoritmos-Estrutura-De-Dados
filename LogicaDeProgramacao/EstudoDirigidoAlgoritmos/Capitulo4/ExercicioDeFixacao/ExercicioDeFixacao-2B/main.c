#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL,"");

    int valorA, valorB, valorC;
    int delta;
    float x1, x2;
    printf("Entre com tr�s valores para calcular a equa��o do segundo grau: ");
        scanf("%d%d%d",&valorA,&valorB,&valorC);

    delta = (valorB*valorB)-4*valorA*valorC;

    if(delta<0){
        printf("A equa��o n�o possui valore real !!!");
    }else if(delta>0){
        x1 = (-valorB+sqrt(delta))/2*valorA;
        x2 = (-valorB-sqrt(delta))/2*valorA;

        printf("\nSolu��o real x': %.2f",x1);
        printf("\nSolu��o real x\": %.2f",x2);
    }else{
        x1 = (-valorB+sqrt(delta))/2*valorA;
        printf("\nSolu��o real x': %.2f",x1);
    }

    return 0;
}
