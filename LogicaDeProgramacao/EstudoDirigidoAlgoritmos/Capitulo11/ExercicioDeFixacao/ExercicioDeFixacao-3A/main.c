#include <stdio.h>
#include <locale.h>

void calcularsomatoriaorial(int n, int *so);

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;
    int somatoria;

    printf("Entre com um n�mero para a somat�ria de um numero: ");
        scanf("%d",&numero);

    calcularsomatoriaorial(numero,&somatoria);

    printf("Somat�ria : %d",somatoria);

    return 0;
}

void calcularsomatoriaorial(int n, int *so){

    *so = 0;

    for(int i = 1; i <= n; i++){

    *so += i;

    }
}
