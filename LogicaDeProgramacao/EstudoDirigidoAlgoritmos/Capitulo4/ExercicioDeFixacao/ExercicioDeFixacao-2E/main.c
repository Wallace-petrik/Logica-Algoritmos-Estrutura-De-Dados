#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int valor1, valor2, diferenca;

    printf("Entre com dois valores: ");
        scanf("%d%d",&valor1,&valor2);

     if(valor1>valor2){
        diferenca = valor1 - valor2;
        printf("DIferen�a entre os dois valores � %d",diferenca);
     }else if(valor1<valor2){
        diferenca = valor2 - valor1;
        printf("DIferen�a entre os dois valores � %d",diferenca);
     }else{
        printf("N�o tem diferen�a entre os dois valores");
     }



    return 0;
}
