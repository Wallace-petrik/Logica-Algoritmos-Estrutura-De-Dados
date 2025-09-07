#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct{
    int codigo;
    char titulo[30];
    char autor[30];
    char assunto[30];
    char editora[30];
    int ano;
    int edicao;
}typedef Livro;

FILE *abrirArquivo(char *nomeDoArquivo,char *modoDeAbertura);

int main(){
    setlocale(LC_ALL,"");

    int opcao,achou,cont;

    Livro livro,auxLivro;
    FILE *arquivo, *novoArquivo;


    do{
        system("cls");
        printf("SISTEMA DE GERENCIAMENTO DE LIVROS\n");
        printf("1 /p Cadastrar\n");
        printf("2 /p Listar \n");
        printf("3 /p Alterar\n");
        printf("4 /p Buscar\n");
        printf("5 /p Excluir\n");
        printf("6 /p Sair\n:");
        scanf("%d%*c",&opcao);
        fflush(stdin);

        switch(opcao){
            case 1:{
                system("cls");
                arquivo = abrirArquivo("arquivo.dat","ab");
                printf("\tEntre com os dados do livro !!!\n\n");
                printf("Código: ");
                    scanf("%d%*c",&livro.codigo);
                printf("Titulo: ");
                    scanf("%[^\n]%*c",&livro.titulo);
                printf("Autor: ");
                    scanf("%[^\n]%*c",&livro.autor);
                printf("Assunto: ");
                    scanf("%[^\n]%*c",&livro.assunto);
                printf("Editora: ");
                    scanf("%[^\n]%*c",&livro.editora);
                printf("Ano: ");
                    scanf("%d%*c",&livro.ano);
                printf("Edição: ");
                    scanf("%d%*c",&livro.edicao);
                fwrite(&livro,sizeof(livro),1,arquivo);

                if(!ferror(arquivo)){
                    if(!fclose(arquivo)){
                        printf("\nSucesso ao salvar os dados !!!");
                    }else printf("Erro ao fechar o arquivo !!! ");

                }else printf("\n\nErro ao salvar os dados.");
                getchar();
            break;}
            case 2:{
                arquivo = abrirArquivo("arquivo.dat","rb");
                while(fread(&livro,sizeof(livro),1,arquivo)==1){
                    printf("Livro: %s\n",livro.titulo);
                }
                getchar();
                fclose(arquivo);
            break;}
            case 3:{

                achou = 0;
                cont = -1;

                arquivo = abrirArquivo("arquivo.dat","r+b");

                printf("Digite o código do livro que deseja alterar: ");
                    scanf("%d%*c",&auxLivro.codigo);

                while(fread(&livro,sizeof(livro),1,arquivo)==1){
                    cont++;
                    if(livro.codigo==auxLivro.codigo){
                        achou = cont;
                        break;
                    }

                }

                if(achou==0){
                    printf("\nLivro não encontrado !!!");
                    getchar();
                }else{

                    do{
                    system("cls");
                    printf("1 para alterar código");
                    printf("\n2 para alterar titulo");
                    printf("\n3 para alterar autor");
                    printf("\n4 para alterar assunto");
                    printf("\n5 para alterar editora");
                    printf("\n6 para alterar ano");
                    printf("\n7 para alterar edicao");
                    printf("\n8 para voltar ao menu anterior\n:");
                        scanf("%d%*c",&opcao);

                    switch(opcao){

                        case 1:{

                            printf("Digite o novo código:");
                                scanf("%d%*c",&livro.codigo);

                        break;}
                        case 2:{



                        break;}
                        case 3:{

                        break;}
                        case 4:{

                        break;}
                        case 5:{

                        break;}
                        case 6:{

                        break;}
                        case 7:{

                        break;}
                        default:{
                            if(opcao!=8){
                                printf("Opção invalida");
                                getchar();
                            }
                        break;}

                    }

                }while(opcao!=8);

                fseek(arquivo,cont*(sizeof(livro)),SEEK_SET);
                fwrite(&livro,sizeof(livro),1,arquivo);

            }

            if(!ferror(arquivo)){
                if(!fclose(arquivo)){
                    printf("\nSucesso na operação !!!");
                }else printf("Erro na operação !!! ");

            }else printf("\n\nErro na operação.");
            getchar();

            break;}
            case 4:{
                system("cls");
                int achou;
                printf("Digite o nome do livro que está buscando: ");
                    scanf("%[^\n]%*c",&auxLivro.titulo);
                arquivo = abrirArquivo("arquivo.dat","rb");
                while(fread(&livro,sizeof(livro),1,arquivo)==1){
                        achou = 0;
                    if(strcmp(auxLivro.titulo,livro.titulo)==0){
                        printf("O livro %s foi encontrado\n",livro.titulo);
                        printf("\nCódigo: %d",livro.codigo);
                        printf("\nTitulo: %s",livro.titulo);
                        printf("\nAssunto: %s",livro.assunto);
                        achou = 1;
                        break;
                    }
                }
                if(!achou){
                    printf("Livro não encontrado !!!");
                }
                getchar();
                fclose(arquivo);
            break;}
            case 5:{

            achou = 0;

            printf("Digite o nome do livro que deseja excluir: ");
                scanf("%[^\n]%*c",auxLivro.titulo);

            arquivo = abrirArquivo("arquivo.dat","r+b");
            novoArquivo = abrirArquivo("novoArquivo.dat","a+b");

            while((fread(&livro,sizeof(livro),1,arquivo))==1){
                if((strcmp(livro.titulo,auxLivro.titulo))!=0){
                    fwrite(&livro,sizeof(livro),1,novoArquivo);
                }else{
                    achou = 1;
                }
            }

            if(!ferror(arquivo) && !ferror(novoArquivo)){

                if(!fclose(arquivo) && !fclose(novoArquivo)){
                    printf("\nSucesso na operação de exclusão !!!");
                }else printf("Erro na operação !!! ");

            }else printf("\n\nErro na operação.");
            getchar();

            remove("arquivo.dat");
            rename("novoArquivo.dat","arquivo.dat");

            break;}
            case 6:{
                printf("Até logo!!!\n");
            break;}
            default:{
                printf("Opção invalida\nTente novamente !!!\n\nPressione qualquer tecla para continuar");
                system("pause");
            }
        }

    }while(opcao!=6);

    return 0;
}

FILE *abrirArquivo(char *nomeDoArquivo,char *modoDeAbertura){
    FILE *arquivo = fopen(nomeDoArquivo,modoDeAbertura);
    if(arquivo ==NULL){
        printf("Falha ao abrir o arquivo %s!!!",nomeDoArquivo);
        system("pause");
        exit(1);
    }
    return arquivo;
}
