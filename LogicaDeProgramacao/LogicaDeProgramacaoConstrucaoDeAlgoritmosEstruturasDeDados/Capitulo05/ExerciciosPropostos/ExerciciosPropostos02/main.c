#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 40

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int numeroSocio;
    char nome[tam];
    char endereco[tam];
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
    int dependentes;
    Data dataDeAssociacao;
}Associados;

typedef struct{
    int numeroSocio;
    Data dataDeVencimento;
    float valor;
    Data dataDePagamento;
}Mensalidade;

int main(){

    setlocale(LC_ALL,"");

    int opcao,contador;

    FILE *arquivoSociados, *arquivoMensalidade;

    Associados socio,socioAux;
    Mensalidade boleto;
    do{

        system("cls");
        printf("1 para cadastrar associados\n");
        printf("2 para apresentar n�mero de pessoas que pode frequentar o clube\n");
        printf("3 para listar aniversariantes do m�s\n");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

            case 0:

                system("cls");
                printf("At� logo!\n");

            break;
            case 1:

                system("cls");
                if((arquivoSociados = fopen("arquivoS.dat","ab+"))==NULL){

                    printf("Erro ao abrir o arquivo!\n");
                    system("pause");
                    exit(1);

                }else{

                    printf("N�mero de s�cio: ");
                        scanf("%d",&socio.numeroSocio);
                        fflush(stdin);
                    printf("Nome: ");
                        fgets(socio.nome,tam,stdin);
                        fflush(stdin);
                    printf("Endere�o: ");
                        fgets(socio.endereco,tam,stdin);
                        fflush(stdin);
                    printf("Bairro: ");
                        fgets(socio.bairro,tam,stdin);
                        fflush(stdin);
                    printf("Cidade: ");
                        fgets(socio.cidade,tam,stdin);
                        fflush(stdin);
                    printf("Estado: ");
                        fgets(socio.estado,tam,stdin);
                        fflush(stdin);
                    printf("N�mero de dependentes: ");
                        scanf("%d",&socio.dependentes);
                        fflush(stdin);
                    printf("Data de associa��o: ");
                        scanf("%d%d%d",&socio.dataDeAssociacao.dia,&socio.dataDeAssociacao.mes,&socio.dataDeAssociacao.ano);
                        fflush(stdin);

                        fwrite(&socio,sizeof(socio),1,arquivoSociados);

                }

                if((fclose(arquivoSociados))==0){

                    printf("As�ciado cadastrado com sucesso!\n");
                    system("pause");

                }

            break;
            case 2:

                if((arquivoSociados = fopen("arquivoS.dat","ab+"))==NULL){

                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);

                }else{

                    contador = 0;

                    while(fread(&socio,sizeof(socio),1,arquivoSociados)){

                        contador+= socio.dependentes+1;

                    }
                    if(contador>0){
                        printf("\nO total depssoas: %d\n\n",contador);
                    }
                }

                if((fclose(arquivoSociados))==0){

                    printf("�xito na busca!\n");
                    system("pause");

                }

            break;
             case 3:

                if((arquivoSociados = fopen("arquivoS.dat","ab+"))==NULL){

                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);

                }else{

                    printf("\nDigite o m�s: ");
                        scanf("%d",&socioAux.dataDeAssociacao.mes);
                    printf("\n");
                    while(fread(&socio,sizeof(socio),1,arquivoSociados)){

                        if(socioAux.dataDeAssociacao.mes==socio.dataDeAssociacao.mes){

                            printf("Nome: %s",socio.nome);

                        }

                    }

                }

                if((fclose(arquivoSociados))==0){

                    printf("\n�xito na busca!\n");
                    system("pause");

                }

            break;
            default:

                system("cls");
                printf("Op��o invalida!\n");
                system("pause");
        }

    }while(opcao!=0);

    return 0;
}
