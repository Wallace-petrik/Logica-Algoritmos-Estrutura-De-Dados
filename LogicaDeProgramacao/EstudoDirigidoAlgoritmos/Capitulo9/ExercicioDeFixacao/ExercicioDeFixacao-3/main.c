#include <stdio.h>
#include <locale.h>

#define elem 2

struct{
    char nome[30];
    float altura;
}typedef Pessoa;

int main(){

    setlocale(LC_ALL,"");

    Pessoa pessoa[elem];

    int opcao = 0;

    do{

        system("cls");
        fflush(stdin);

        printf("1 para registar pessoas\n");
        printf("2 para listar pessoas menors ou irguais a 1.5m\n");
        printf("3 para listar pessoas maiores que 1.5m\n");
        printf("4 para listar psssoas maiores que 1.5m e menores que 2.0m\n");
        printf("5 para listar todas as pessoas e m�dia de altura\n");
        printf("0 para sair\n: ");
            scanf("%d%*c",&opcao);

        switch(opcao){

            case 0:{
                printf("\n\nAt� logo !!!");
                getchar();
            break;}

            case 1:{

                system("cls");
                for(int i = 0; i < elem; i++){
                    printf("O nome e %d� pessoa: ",i+1);
                        scanf("%[^\n]%*c",pessoa[i].nome);
                    printf("Altura: ");
                        scanf("%f%*c",&pessoa[i].altura);
                    system("cls");
                }

            break;}

            case 2:{

                system("cls");

            break;}

            case 3:{

            break;}

            case 4:{

            break;}

            case 5:{

            break;}

            default:{
                printf("\n\nOp��o invalida !!!");
                getchar();
                system("cls");
            break;}
        }

    }while(opcao != 0);

    return 0;
}
