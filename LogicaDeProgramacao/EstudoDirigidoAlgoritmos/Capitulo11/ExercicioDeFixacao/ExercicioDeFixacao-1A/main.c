#include <stdio.h>
#include <locale.h>

#define qtd 3

struct{
    char nome[50];
    char endereco[50];
    int telefone;
}typedef Agenda;

Agenda contato[qtd];
int indice = 0, fim = qtd;

void cadastrarContato();

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        printf(" ======================\n");
        printf(" |1 para cadastramento |\n");
        printf(" ======================\n");
        printf(" |2 para pesquisa      |\n");
        printf(" ======================\n");
        printf(" |3 para corre��o      |\n");
        printf(" ======================\n");
        printf(" |4 para remo��o       |\n");
        printf(" ======================\n");
        printf(" |5 para sair          |\n");
        printf(" ======================\n : ");
            scanf("%d",&opcao);

        switch(opcao){

            case 1:{
                cadastrarContato();
            break;}

            case 2:{

            break;}

            case 3:{

            break;}

            case 4:{

            break;}

            case 5:{
                fflush(stdin);
                printf("\n At� logo !!! ");

            break;}

            default:{
                fflush(stdin);
                printf(" Op��o invalida !!!\n");
                getchar();
            }

        }

    }while(opcao != 5);

    return 0;
}

void cadastrarContato(){
    system("cls");
    fflush(stdin);
    if(indice == qtd){
        printf(" Agenda lotada !!!\n");
        getchar();
    }else{

        printf(" Digite o nome do contato: ");
            gets(contato[indice].nome);
        printf(" Digite o endere�o: ");
            gets(contato[indice].endereco);
        printf(" Digite o telefone: ");
            scanf("%d",&contato[indice].telefone);

        printf(" Cadastro realizado com sucesso !!!");
        system("pause");
        indice++;

    }
}
