#include <stdio.h>
#include <locale.h>
#define tam 3

struct {

    char nome[30];
    char endereco[50];
    int telefone;

} typedef Agenda;

int main(){

    setlocale(LC_ALL,"");

    Agenda minhaAgenda[tam];

    int opcao = 0;

    do{
        system("cls");
        printf("1 para Cadastrar contato~\n");
        printf("2 para Pesquisar contato\n");
        printf("3 para Ordenar por nome\n");
        printf("4 para listar contatos\n");
        printf("5 para sair\n:");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:

                system("cls");
                for(int i = 0; i < tam; i++){
                    system("cls");
                    printf("Contato %d\n",i+1);
                    printf("Digite o nome: ");
                        fflush(stdin);
                        scanf("%[^\n]s",minhaAgenda[i].nome);
                    printf("Digite o Endere�o: ");
                        fflush(stdin);
                        scanf("%[^\n]s",minhaAgenda[i].endereco);
                    printf("Digite o telefone: ");
                        fflush(stdin);
                        scanf("%d",&minhaAgenda[i].telefone);
                        system("pause");
                }

            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
                printf("\n\tAt� logo!!!");
            break;
            default:

                printf("\n\tOpi��o invalida!!!\n");
                system("pause");

        }

    }while(opcao != 5);

    return 0;
}
