#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[30];
    char rua[30];
    char bairro[30];
    char estadoCivil[30];
    char cargo[30];
    int numeroDeDependentes;
    int cep;
    int anoDeAdmissao;
    int anoDeDemisap;
    int cpf;
    int tel;
    int setor;
    float salario;

}regFunc;

typedef struct{
    int posicao;
    int codigo;
}regCod;

int main(){

    setlocale(LC_ALL,"");

    int opcao, contador;

    FILE *funcionarios, *codigos;

    regFunc colaborador;
    regCod cod,codaux;
    do{

        system("cls");
        printf("1 para cadastrar funcionario.\n");
        printf("2 para listar todos os colaboradores.\n");
        printf("3 para alterar dados.\n");
            scanf("%d",&opcao);
            fflush(stdin);

            if(((funcionarios = fopen("registrodefuncionarios.dat","ab+"))==NULL)||((codigos = fopen("indices.dat","wb"))==NULL)){
                printf("Erro ao gerar �ndices");
                exit(1);
            }else{
                contador = 0;
                while(fread(&colaborador,sizeof(colaborador),1,funcionarios)){

                    cod.codigo = 2001000+contador;
                    cod.posicao = cod.codigo-2001000;
                    contador++;
                    fwrite(&cod,sizeof(cod),1,codigos);
                }

                fclose(funcionarios);
                fclose(codigos);

            }

        switch(opcao){

            case 0:

                system("cls");
                printf("At� logo!\n");
                system("pause");

            break;
            case 1:

                system("cls");
                if((funcionarios = fopen("registrodefuncionarios.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo");
                    exit(1);
                }else{

                    printf("Nome: ");
                        fgets(colaborador.nome,30,stdin);
                        fflush(stdin);
                    printf("\nRua: ");
                        fgets(colaborador.rua,30,stdin);
                        fflush(stdin);
                    printf("\nBairro: ");
                        fgets(colaborador.bairro,30,stdin);
                        fflush(stdin);
                    printf("\nCEP: ");
                        scanf("%d",&colaborador.cep);
                        fflush(stdin);
                    printf("\nCPF: ");
                        scanf("%d",&colaborador.cpf);
                        fflush(stdin);
                    printf("\nTelefone: ");
                        scanf("%d",&colaborador.tel);
                        fflush(stdin);
                    printf("\nAno de admiss�o: ");
                        scanf("%d",&colaborador.anoDeAdmissao);
                        fflush(stdin);
                    printf("\nAno de demiss�o: ");
                        scanf("%d",&colaborador.anoDeDemisap);
                        fflush(stdin);
                    printf("\nEstado civil: ");
                        fgets(colaborador.estadoCivil,30,stdin);
                        fflush(stdin);
                    printf("\nN� de dependentes: ");
                        scanf("%d",&colaborador.numeroDeDependentes);
                        fflush(stdin);
                    printf("\nSal�rio: ");
                        scanf("%f",&colaborador.salario);
                        fflush(stdin);
                    printf("\nSetor: ");
                        scanf("%d",&colaborador.setor);
                        fflush(stdin);
                    printf("\nCargo: ");
                        fgets(colaborador.cargo,30,stdin);
                        fflush(stdin);

                    fwrite(&colaborador,sizeof(colaborador),1,funcionarios);

                    if(fclose(funcionarios)==0){
                        system("cls");
                        printf("Dados salvos com sucesso!\n");
                        system("pause");
                    }

                }

            break;
            case 2:

                system("cls");
                if((funcionarios = fopen("registrodefuncionarios.dat","ab+"))==NULL ||((codigos = fopen("indices.dat","ab+"))==NULL)){

                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);
                }else{

                    while(fread(&colaborador,sizeof(colaborador),1,funcionarios)){
                        fread(&cod,sizeof(cod),1,codigos);
                        printf("Matricula: %d\n",cod.codigo);
                        printf("Posi: %d\n",cod.posicao);
                        printf("Nome: %sCargo: %s",colaborador.nome,colaborador.cargo);
                        printf("Estado civil: %s",colaborador.estadoCivil);
                        printf("N�mero de dependentes: %d\n\n",colaborador.numeroDeDependentes);
                    }

                    if(fclose(funcionarios)==0 && fclose(codigos)==0){
                        printf("\n\nOpera��o realizada com sucesso!\n");
                        system("pause");
                    }
                }

            break;
            case 3:

                system("cls");
                if((funcionarios = fopen("registrodefuncionarios.dat","rb+"))==NULL || (codigos = fopen("indices.dat","rb+"))==NULL){
                    printf("Erro inesperado!\n");
                    exit(1);
                }else{

                    printf("Difite o c�digo do funcionario: \n");
                        scanf("%d",&codaux.codigo);
                        fflush(stdin);

                    fseek(codigos,sizeof(cod)*(codaux.codigo-2001000),SEEK_SET);
                    fread(&cod,sizeof(cod),1,codigos);

                    printf("Digite o novo n�mero de dependentes: ");
                        scanf("%d",&colaborador.numeroDeDependentes);
                        fflush(stdin);
                    printf("Digite o novo estado civil: ");
                        fgets(colaborador.estadoCivil,30,stdin);
                        fflush(stdin);

                    fseek(funcionarios,sizeof(colaborador)*cod.posicao,SEEK_CUR);
                    fwrite(&colaborador,sizeof(colaborador),1,funcionarios);
                }
                if((fclose(funcionarios)==0) && (fclose(codigos)==0)){
                        printf("Altera��es realizada com sucesso!\n");
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
