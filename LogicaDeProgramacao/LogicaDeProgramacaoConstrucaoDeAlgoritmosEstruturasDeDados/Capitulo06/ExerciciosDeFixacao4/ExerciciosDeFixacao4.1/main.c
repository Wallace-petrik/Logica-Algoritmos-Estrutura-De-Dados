#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL,"");

    int numero;
    int quantidadeDeDigitos;

    printf("Digite um n�mero inteiro qualquer:");
        scanf("%d",&numero);

    quantidadeDeDigitos = qualcularQuantidadeDeDigitos(numero);

    printf("\nA quantidade de d�gitos � %d\n3",quantidadeDeDigitos);
    return 0;
}

int qualcularQuantidadeDeDigitos(int numero){

    int quantidadeDeDigitos = 0;

    while(numero>0){

        numero = numero/10;
        quantidadeDeDigitos++;
    }

    return quantidadeDeDigitos;
}
