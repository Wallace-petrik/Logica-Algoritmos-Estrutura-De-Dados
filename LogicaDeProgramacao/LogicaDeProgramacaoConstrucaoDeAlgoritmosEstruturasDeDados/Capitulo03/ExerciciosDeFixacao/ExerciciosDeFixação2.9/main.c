#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a,b;
    char simbolo;

    printf("\n-----------------------------");
    printf("\nS�mbolo | Opera��o aritm�tica");
    printf("\n-----------------------------");
    printf("\n+                      Adi��o");
    printf("\n-                   Subtra��o");
    printf("\n*               Multiplica��o");
    printf("\n/                     Divis�o");
    printf("\n-----------------------------");

    printf("\nEntre com dois n�meros inteiros: ");
        scanf("%d%d",&a,&b);
    printf("\nEntre com o tipo da opera��o: ");
        scanf(" %c",&simbolo);

    switch(simbolo){
        case '+':
            printf("\n %d + %d = %d",a,b,a+b);
        break;
        case '-':
            printf("\n %d + %d = %d",a,b,a-b);
        break;
        case '*':
            printf("\n %d + %d = %d",a,b,a*b);
        break;
        case '/':
            printf("\n %d + %d = %.1f",a,b,(float)a/b);
        break;
        default:
            printf("\nOpera��o invalida.\nEntre com os simbolos da tabela.\n\n");
        break;
    }
    return 0;
}
