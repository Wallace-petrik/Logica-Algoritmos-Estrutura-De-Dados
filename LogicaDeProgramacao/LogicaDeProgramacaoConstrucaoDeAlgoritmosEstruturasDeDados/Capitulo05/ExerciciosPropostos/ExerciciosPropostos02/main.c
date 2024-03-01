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

    int opcao,contador,controle;

    FILE *arquivoAssociados, *arquivoMensalidade, *novoarquivo;

    Associados socio,socioAux;
    Mensalidade boleto,boletoAux;
    do{

        system("cls");
        printf("1 para associados\n");
        printf("2 para apresentar n�mero de pessoas que pode frequentar o clube\n");
        printf("3 para listar aniversariantes do m�s\n");
        printf("4 para listar mensaldades dos s�cios\n");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

            case 0:

                system("cls");
                printf("At� logo!\n");

            break;
            case 1:

                system("cls");
                if((arquivoAssociados = fopen("arquivoS.dat","rb+"))==NULL){

                    printf("Erro ao abrir o arquivo!\n");
                    system("pause");
                    exit(1);

                }else{

                    printf("1 para inclus�es\n2 para altera��es\n3 para exclus�es\n");
                        scanf("%d",&opcao);

                        if(opcao==1){
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

                            fwrite(&socio,sizeof(socio),1,arquivoAssociados);
                        }else if(opcao == 2){

                            printf("\nDigite o c�digo do associado: ");
                                scanf("%d",&socioAux.numeroSocio);

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

                            fseek(arquivoAssociados,sizeof(socio)*(socioAux.numeroSocio-1),SEEK_SET);
                            fwrite(&socio,sizeof(socio),1,arquivoAssociados);

                        }else if(opcao==3){

                            if((novoarquivo = fopen("novoarq.dat","a+b"))==NULL){

                                    printf("Erro ao abrir o arquivo\n");

                            }else{

                                printf("Digite o n�mero do s�cio: ");
                                    scanf("%d",&socioAux.numeroSocio);

                                while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                                    if(socio.numeroSocio<socioAux.numeroSocio){
                                        fwrite(&socio,sizeof(socio),1,novoarquivo);
                                    }else if(socio.numeroSocio>socioAux.numeroSocio){
                                        socio.numeroSocio--;
                                        fwrite(&socio,sizeof(socio),1,novoarquivo);
                                    }

                                }

                            }

                        }else{
                            printf("Op��o invalida\n");
                        }

                }

                if((fclose(arquivoAssociados))== 0 && (fclose(novoarquivo))== 0){

                    printf("�xito\n");
                    system("pause");

                }

                remove("arquivoS.dat");
                rename("novoarq.dat","arquivoS.dat");

            break;
            case 2:

                if((arquivoAssociados = fopen("arquivoS.dat","ab+"))==NULL){

                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);

                }else{

                    contador = 0;

                    while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                        contador+= socio.dependentes+1;

                    }
                    if(contador>0){
                        printf("\nO total depssoas: %d\n\n",contador);
                    }
                }

                if((fclose(arquivoAssociados))==0){

                    printf("�xito na busca!\n");
                    system("pause");

                }

            break;
            case 3:

                if((arquivoAssociados = fopen("arquivoS.dat","ab+"))==NULL){

                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);

                }else{

                    printf("\nDigite o m�s: ");
                        scanf("%d",&socioAux.dataDeAssociacao.mes);
                    printf("\n");
                    while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                        if(socioAux.dataDeAssociacao.mes==socio.dataDeAssociacao.mes){

                            printf("N�: %d\n",socio.numeroSocio);
                            printf("Nome: %s",socio.nome);

                        }

                    }

                }

                if((fclose(arquivoAssociados))==0){

                    printf("\n�xito na busca!\n");
                    system("pause");

                }

            break;
            case 4:

                system("cls");
                controle = 0;
                contador = 0;
                if((arquivoAssociados = fopen("arquivoS.dat","rb"))==NULL || (arquivoMensalidade = fopen("arquivosM.dat","r+b"))==NULL){

                    system("cls");
                    printf("Erro ao abrir os arquivos!\n");
                    exit(1);
                }else{

                    system("cls");
                    printf("Digite o c�digo so s�cio: ");
                        scanf("%d",&boletoAux.numeroSocio);

                    while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                        if(boletoAux.numeroSocio==socio.numeroSocio){

                            printf("Digite o valor individual: ");
                                scanf("%f",&boletoAux.valor);
                                socio.dependentes > 0 ? (boletoAux.valor *= socio.dependentes): boletoAux.valor;
                            printf("Digite a data de vencimento: ");
                                scanf("%d%d%d",&boletoAux.dataDeVencimento.dia,&boletoAux.dataDeVencimento.mes,&boletoAux.dataDeVencimento.ano);
                                boletoAux.dataDePagamento=boletoAux.dataDeVencimento;




                            if(0 == fread(&boleto,sizeof(boleto),1,arquivoMensalidade)){

                                fwrite(&boletoAux,sizeof(boletoAux),1,arquivoMensalidade);
                                break;

                            }else{

                               fseek(arquivoMensalidade,0,SEEK_SET);

                                while(fread(&boleto,sizeof(boleto),1,arquivoMensalidade)){

                                    if(boleto.numeroSocio==boletoAux.numeroSocio){

                                        fseek(arquivoMensalidade,-(sizeof(boletoAux)),SEEK_CUR);
                                        fwrite(&boletoAux,sizeof(boletoAux),1,arquivoMensalidade);
                                        controle = 1;
                                        break;
                                    }
                                }

                            }
                            if(controle == 0){
                                fwrite(&boletoAux,sizeof(boletoAux),1,arquivoMensalidade);
                            }
                        }

                    }

                }

                if((fclose(arquivoAssociados))== 0 && (fclose(arquivoMensalidade))== 0){

                    printf("Opera��o finalizada!\n");
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
