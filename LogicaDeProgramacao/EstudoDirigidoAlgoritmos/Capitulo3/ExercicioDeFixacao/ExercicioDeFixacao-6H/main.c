#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL,"");

    int valor;
    int resultado;

    printf("Entre com um n�mero inteiro: ");
        scanf("%d",&valor);

    resultado = (int)pow(valor, 2);

    printf("%d� = %d",valor,resultado);

    return 0;
}
