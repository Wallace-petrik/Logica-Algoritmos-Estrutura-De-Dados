#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int numero = 0 ;

    do{
    printf("\nEntre com um n�mero qualuer menor ou igual a 50: ");
        scanf("%d",&numero);
        if(numero>50){
            printf("Digite um n�mero valido!!!\n");
            system("pause");
            system("cls");
        }
    }while(numero>50);

    while(numero<250){
            if(numero*3>250){
                break;
            }
        numero *= 3;
    }
    printf("Resultado da multiplica��o sucessiva %d\n",numero);
    return 0;
}
