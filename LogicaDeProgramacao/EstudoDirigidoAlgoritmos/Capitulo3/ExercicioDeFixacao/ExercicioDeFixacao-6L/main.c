#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    float medidaEmPes, medidadeEmMetros;

    printf("Entre com uma medida em p�s: ");
        scanf("%f",&medidaEmPes);

    medidadeEmMetros = medidaEmPes/3.281;

    printf("A medida em metros � %.2f",medidadeEmMetros);

    return 0;
}
