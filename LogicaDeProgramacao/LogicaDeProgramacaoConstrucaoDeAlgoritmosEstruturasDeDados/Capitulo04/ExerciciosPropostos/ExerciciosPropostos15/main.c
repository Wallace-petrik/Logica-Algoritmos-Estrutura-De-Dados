#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_MAX 3



typedef struct{
    int codigoDeCatalogacao;
    int numeroDePaginas;
    char nomeDaObra[40];
    char nomeDoAutor[40];
    char editora[40];
    char doado[40];
}Obras;


void bubblesort(Obras livros[TMP_MAX]);
int buscarLivros(Obras livros[TAM_MAX], int codigoDeBusca);
int buscarLivrosPorNome(Obras livros[TAM_MAX], char nomeDoLivrosDeBusca[40]);

int main(){
    setlocale(LC_ALL,"");

    int codigo,opcao,area;
    char nome[40];

    Obras cienciasExatas[TAM_MAX] = {75,155,"Banana Rei","Calor Machado","Book","Reis",8,50,"ABC","Machado","Book","Leandra",22,300,"C++","wallace","Alura","Berenice"};
    Obras cienciasHumanas[TAM_MAX] = {80,290,"Rei macaco","Maria Clara","Darkside","CLara",15,70,"Design Patterns","Wallace","Saraiva","Rita",46,255,"Java","IGor","Alura","Ana"};
    Obras cienciasBiomedicas[TAM_MAX] = {55,120,"Rei Le�o","Gabriel Reis","Rocco","Lucas",06,180,"Amigos","Gustavo","Saraiva","Fenanda",11,75,"C++","Thiago","Alura","Ellen"};

    bubblesort(cienciasBiomedicas);
    bubblesort(cienciasExatas);
    bubblesort(cienciasHumanas);

        do{
        printf("\nESCOLHA UMA OP��O\n");
        printf("\n1/P buscar um livro c�digo");
        printf("\n2/P buscar um livro nome");
        printf("\n10/P Sair: ");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:
                //Busca por c�digo
                    do{
                        printf("\nESCOLHA UMA OP��O\n");
                        printf("\n1/P buscar um livro");
                        printf("\n2/P voltar para o menu anterior: ");
                            scanf("%d",&opcao);
                            fflush(stdin);
                        switch(opcao){

                            case 1:
                                do{
                                    printf("\nEntre com o c�digo do livro: ");
                                        scanf("%d",&codigo);
                                        fflush(stdin);
                                    printf("\nESCOLHA A �REA DO LIVRO\n");
                                    printf("\n1/P Ci�ncias Exatas");
                                    printf("\n2/P Ci�ncias Humanas");
                                    printf("\n3/P Ci�ncias Biomedicas\n4/P Voltar para o menu anterior: ");
                                        scanf("%d",&area);
                                        fflush(stdin);
                                    switch(area){
                                        case 1:
                                            area=buscarLivros(cienciasExatas,codigo);
                                        break;
                                        case 2:
                                            area=buscarLivros(cienciasHumanas,codigo);
                                        break;
                                        case 3:
                                            area=buscarLivros(cienciasBiomedicas,codigo);
                                        break;
                                        case 4:
                                            printf("Ok!!!");
                                        break;
                                        default:
                                            printf("\nDados de �rea invalidos.");
                                            printf("\nDigite novamente.");
                                    }
                                }while(area!=4);
                            break;
                            case 2:
                                printf("Ok!!!");
                            break;
                            default :
                                printf("\nEntrada invalida!");
                        }
                    }while(opcao!=2);

            break;
            case 2:
                //Busca por nome
                    do{
                        printf("\nESCOLHA UMA OP��O\n");
                        printf("\n1/P buscar um livro");
                        printf("\n2/P voltar para o menu anterior: ");
                            scanf("%d",&opcao);
                            fflush(stdin);
                        switch(opcao){

                            case 1:
                                do{
                                    printf("\nEntre com o nome do livro: ");
                                        scanf("%[^\n]",&nome);
                                        fflush(stdin);
                                    printf("\nESCOLHA A �REA DO LIVRO\n");
                                    printf("\n1/P Ci�ncias Exatas");
                                    printf("\n2/P Ci�ncias Humanas");
                                    printf("\n3/P Ci�ncias Biomedicas\n4/P Voltar para o menu anterior: ");
                                        scanf("%d",&area);
                                        fflush(stdin);
                                    switch(area){
                                        case 1:
                                            area=buscarLivrosPorNome(cienciasExatas,nome);
                                        break;
                                        case 2:
                                            area=buscarLivrosPorNome(cienciasHumanas,nome);
                                        break;
                                        case 3:
                                            area=buscarLivrosPorNome(cienciasBiomedicas,nome);
                                        break;
                                        case 4:
                                            printf("Ok!!!");
                                        break;
                                        default:
                                            printf("\nDados de �rea invalidos.");
                                            printf("\nDigite novamente.");
                                    }
                                }while(area!=4);
                            break;
                            case 2:
                                printf("Ok!!!");
                            break;
                            default :
                                printf("\nEntrada invalida!");
                        }
                    }while(opcao!=2);

            break;
            case 10:
                printf("\nAt� logo");
            break;
            default :
                printf("\nEntrada invalida!");
        }
    }while(opcao!=10);

    return 0;
}
int buscarLivrosPorNome(Obras livros[TAM_MAX], char nomeDoLivrosDeBusca[40]){
    int controle = 0;
    for(int i = 0; i < TAM_MAX; i++){
        if((strcmp(livros[i].nomeDaObra, nomeDoLivrosDeBusca))==0){
            printf("\nNome do livros: %s",livros[i].nomeDaObra);
            printf("\nNome do autor: %s\n",livros[i].nomeDoAutor);
            controle = 1;
            return 4;
        }
    }
    if(controle==0){
        printf("\nLivro n�o encontrado.");
    }
}
int buscarLivros(Obras livros[TAM_MAX], int codigoDeBusca){
    int controle = 0;
    for(int i = 0; i < TAM_MAX; i++){
        if(livros[i].codigoDeCatalogacao==codigoDeBusca){
            printf("\nNome do livros: %s",livros[i].nomeDaObra);
            printf("\nNome do autor: %s\n",livros[i].nomeDoAutor);
            controle = 1;
            return 4;
        }
    }
    if(controle==0){
        printf("\nLivro n�o encontrado.");
    }
}

void bubblesort(Obras livros[TAM_MAX]){
    int controle = 0, fim = TAM_MAX;
    Obras livroAux;
    do{
        controle = 0;
        for(int i = 0; i < fim - 1; i++){
            if(livros[i].codigoDeCatalogacao>livros[i+1].codigoDeCatalogacao){
                livroAux = livros[i];
                livros[i] = livros[i+1];
                livros[i+1] = livroAux;
                controle = i;
            }
        }
        fim --;
    }while(controle!=0);
}
