#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero = 0;

    printf("Digite um n�mero inteiro qualquer: ");
        scanf("%d",&numero);

    verificarNumero(numero);
    return 0;
}

void verificarNumero(int numero){

    if(numero%6==0){
        printf("O n�mero %d � divis�vel por 6\n",numero);
    }else{
        printf("O n�mero %d n�o � divis�vedel por 6\n",numero);
    }

}
