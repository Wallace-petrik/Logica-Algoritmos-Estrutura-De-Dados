#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL,"");

    int valor;

    printf("Entre com n�mero qualquer: ");
        scanf("%d",&valor);

    /*
    if(valor<0){
        printf("O valor m�dulo dele � = %d",valor*-1);
    }else{
        printf("O valor m�dulo dele � = %d",valor);
    }*/

    printf("O valor m�dulo dele � = %d",abs(valor));
    return 0;
}
