#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int number = 0,soma = 0;

    while(++number<=100){
        soma+=number;
    }
    printf("\nSoma dos cem primeiro n�meros inteiros: %d\n",soma);
    // A soma dos cem primeiros n�meros inteiros pode ser calculada usando a f�rmula da soma de uma progress�o aritm�tica,
    // pois os n�meros inteiros seguem uma sequ�ncia com uma diferen�a constante de 1 entre eles.
    // Soma = (100/2)*(1+100)
    return 0;
}
