#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero;

    printf("Entre com um n�mero inteiro qualquer: ");
        scanf("%d",&numero);
    calcularRaizQuadrada(numero);
    return 0;
}

void calcularRaizQuadrada (int numero){
    int raizQuadrada = 0;

    raizQuadrada = numero * numero;

    printf("A raiz quadrada de %d � %d\n",numero,raizQuadrada);
}
