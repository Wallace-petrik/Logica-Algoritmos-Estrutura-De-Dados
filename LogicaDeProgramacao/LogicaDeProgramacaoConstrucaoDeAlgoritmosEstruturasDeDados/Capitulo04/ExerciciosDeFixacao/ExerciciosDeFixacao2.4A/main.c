#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL,"");

    int matriz[7][7] = {{0,02,11,06,15,11,01},
                     {02,0,07,12,04,02,15},
                     {11,07,0,11,8,03,12},
                     {06,12,11,0,10,02,01},
                     {15,04,8,10,0,05,13},
                     {11,02,03,05,05,0,14},
                     {01,15,13,01,13,14,0}};

    int cidade01,cidade02;

    do{
        printf("\n0/p Rio de Janeiro\n1/p S�o Gon�alo\n2/p Duque de Caxias\n3/p Nova Igua�u\n4/p Belford Roxo\n5/p Niter�i\n6/p Petr�polis\n\nPara sair digite a mesma cidade duas vezesn");
        printf("\nEscolha duas cidades: ");
            scanf("%d%d",&cidade01,&cidade02);

        if(cidade01==cidade02){
            system("cls");
            printf("\nAt� logo!\n");
        }else{
            if((cidade01>=0 && cidade01<=6)&&(cidade02>=0 && cidade02<=6)){

                system("cls");
                printf("\nO tempo necess�rio para percorrer as duas �  igual = %d",matriz[cidade01][cidade02]);
                printf("\nPressione qualquer tecla para contin�ar");
                getch();
                system("cls");

            }else{
                system("cls");
                printf("\nCidades invalidas.\nTente novamente.\n");
                printf("\nPressione qualquer tecla para continuar");
                getch();
                system("cls");
            }
        }
    }while((cidade01!=cidade02));

    return 0;
}
