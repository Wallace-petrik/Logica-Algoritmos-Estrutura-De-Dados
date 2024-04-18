#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 20

typedef struct{

    int codigo;
    char nome[tam];
    char tipo[tam];
    int estoqueMinimo;

}Produtos;

typedef struct{

    int codigo;
    int dia;
    int mes;
    int ano;
    int quantidade;
    int tipo;
    float valor;

}Movimentacao;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqProdutos, *arqMovimentacao;

    Produtos produtos;
    Movimentacao movimentacao, movimentacaoAux;

    int opcao, total = 0;

    if((arqProdutos = fopen("arqProdutos.dat","a+b"))==NULL){
        system("cls");
        printf("Erro ao abrir os arquivos");
    }else{
        fclose(arqProdutos);
    }

    do{
        system("cls");
        printf("1 para cadastrar produto\n");
        printf("2 para entrada no estoque\n");
        printf("3 para sa�da de estoque\n");

        printf("\nDigite uma o��o: ");
            scanf("%d",&opcao);
        switch(opcao){

            case 0:

                system("cls");
                printf("At� logo!!!");

            break;
            case 1:

                if((arqProdutos = fopen("arqProdutos.dat","r+b"))==NULL){
                    printf("Erro ao abrir o arquivo!!!");
                    system("pause");
                }else{

                    printf("Digite o c�digo do produto: ");
                        scanf("%d",&produtos.codigo);
                        fflush(stdin);
                    printf("Digite o tipo do produto: ");
                        scanf("%[^\n]",&produtos.tipo);
                        fflush(stdin);
                    printf("Digite o nome do produto: ");
                        scanf("%[^\n]",&produtos.nome);
                        fflush(stdin);
                    printf("Digite a quantidade de m�nima de produtos: ");
                        scanf("%d",&produtos.estoqueMinimo);

                    fseek(arqProdutos,(produtos.codigo-1)*sizeof(produtos),SEEK_SET);
                    fwrite (&produtos,sizeof(produtos),1,arqProdutos);
                }
                if((fclose(arqProdutos))==0){
                    printf("Produto cadastrado com sucesso!!!!\n");
                    system("pause");
                }

            break;
            case 2:

                if((arqMovimentacao = fopen("arqMovimentacao.dat","a+b"))==NULL){
                    printf("Erro ao abrir o arquivo!!");
                    system("pause");
                }else{

                    printf("Digite o c�digo do produto: ");
                        scanf("%d",&movimentacao.codigo);
                    printf("Digite a data da compro: ");
                        scanf("%d%d%d",&movimentacao.dia,&movimentacao.mes,&movimentacao.ano);
                    printf("Digite a quantidade do produto: ");
                        scanf("%d",&movimentacao.quantidade);
                    printf("\n1 para compra\n2 para devolu��o\nDigite o tipo de entrada: ");
                        scanf("%d",&movimentacao.tipo);
                    if(movimentacao.tipo==1){
                        printf("Digite o pre�o da compra: ");
                            scanf("%f",&movimentacao.valor);
                    }else if(movimentacao.tipo==2){
                         movimentacao.valor = 0;
                    }else{
                        printf("Op��o invalida!!!");
                    }

                    fwrite(&movimentacao,sizeof(movimentacao),1,arqMovimentacao);
                }

                if(fclose(arqMovimentacao)==0){
                    printf("Opera��o realizada com sucesso!!!");
                    system("pause");
                }

            break;
            case 3:

                if((arqMovimentacao = fopen("arqMovimentacao.dat","a+b"))==NULL){
                    printf("Erro ao abrir o arquivo!!!");
                    system("pause");
                }else{
                    printf("Digite o c�digo do produto: ");
                        scanf("%d",&movimentacaoAux.codigo);
                    printf("Digite a quantidade da compra: ");
                        scanf("%d",&movimentacaoAux.quantidade);

                    while(fread(&movimentacao,sizeof(movimentacao),1,arqMovimentacao)){
                        if(movimentacaoAux.codigo==movimentacao.codigo){
                            if(movimentacao.tipo==1 || movimentacao.tipo==2){
                                total += movimentacao.quantidade;
                            }else{

                            }
                        }
                    }

                }

                if(fclose(arqMovimentacao)==0){
                    printf("Opera��o realizada com sucesso!!!");
                    system("pause");
                }

            break;
            default:
                printf("Opc��o invalida!!!\n");
                system("pause");

        }

    }while(opcao!=0);

    return 0;
}
