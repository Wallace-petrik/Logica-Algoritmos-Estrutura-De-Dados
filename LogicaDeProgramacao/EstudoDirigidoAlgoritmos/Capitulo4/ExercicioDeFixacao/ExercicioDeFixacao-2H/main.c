#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int valor;

    printf("Digite um numero qualquer: ");
        scanf("%d",&valor);

    if(valor>=1 && valor<=10){
        printf("O valor est� na faixa de 1 a 10");
    }else printf("O valor n�o est� na faixa entre 1 a 10");

    return 0;
}
