#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int codProduto;

    printf("\n----------------------------------");
    printf("\nC�digo                     Produto");
    printf("\n----------------------------------");
    printf("\n1                    N�o-perec�vel");
    printf("\n2,3 ou 4                 Perec�vel");
    printf("\n5 ou 6                   Vestu�rio");
    printf("\n7                  Higiene pessoal");
    printf("\n8 at� 15       Limpeza eUtens�lios");
    printf("\n----------------------------------");

    printf("\n\nEntre com o c�digo do produto: ");
        scanf("%d",&codProduto);

    switch(codProduto){
        case 1: printf("\nN�o-perec�vel");
        break;
        case 2:
        case 3:
        case 4:
            printf("\nPerec�vel");
        break;
        case 5:
        case 6: printf("\nVestu�rio");
        break;
        case 7: printf("\nHigiene pessoal");
        break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:printf("\nLimpeza e utens�lios");
        break;
        default: printf("\nInv�lido");
    }

    return 0;
}
