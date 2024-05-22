#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero;

    printf("Digite um n�mero para saber se � primo ou n�o: ");
        scanf("%d",&numero);

    verificarSeNumeroEPrimo(numero);

    return 0;
}

void verificarSeNumeroEPrimo(int numero){

    int contador;

    for(int i = 1; i <= numero; i++){
         if(numero%i==0){
            contador++;
         }
    }

    if(contador==2){
        printf("O n�mero %d � primo",numero);
    }else{
        printf("O n�mero %d n�o � primo",numero);

    }
}
