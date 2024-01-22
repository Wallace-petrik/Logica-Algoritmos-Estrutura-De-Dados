#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int numeroDaPassagem;
    char nomeDoPassageiro[40];
    int sexo;
}Poltronas;

typedef struct{
    char origem[40];
    char destino[40];
    char data[11];
    int horario[2];
    int distancia;
    Poltronas passageiros[44];
}Linha;

int main(){
    setlocale(LC_ALL,"");

    Linha onibus[10] = {{"Campinas","Rio de Janeiro","20/03/2024",17,30,400,00,"Wallace",1}};

    int opcao = 0, linhasDoOnibus = 0, controle = 0,contador = 0,horas = 0, minutos = 0, horasChegada = 0, minutosChegada = 0;
    float tempo = 0,chegada, percentual,contadorM, contadorF,janelaP = 0, janelaI = 0;
    const int velocidadeM = 60;

    do{
        system("cls");
        printf("1 Para buscar �nibus.\n");
        printf("2 Para linha de �nibus que est�o lotadas.\n");
        printf("3 Para informa tempo estimado de chegada e dura��o da viagem.\n");
        printf("4 Para listar quantidade de poltronas livres e seu percentual.\n");
        printf("5 Para percentual de homens e mulheres.\n");
        printf("6 Para listar todas as poltronas livres de todos os �nibus.\n");
        printf("7 Para sair\n");
            scanf("%d",&opcao);
        switch(opcao){

            case 1:
                controle = 0;
                system("cls");
                printf("Entre com o numero do �nibus:");
                    scanf("%d",&linhasDoOnibus);
                for(int i = 0; i < 10; i++){
                    if(i==linhasDoOnibus){
                        printf("Hor�rio de Sa�da : %d:%d\n",onibus[i].horario[0],onibus[i].horario[1]);
                        printf("Dist�ncia = %d\n",onibus[i].distancia);
                        controle = 1;
                        break;
                    }
                }
                if(controle==0){
                    printf("Linha de �nibus n�o encontrada\n");
                }
                controle = 0;
                system("pause");
                system("cls");
            break;
            case 2:
                system("cls");
                controle = 0;
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 44; j++){
                        if(onibus[i].passageiros[j].sexo==1||onibus[i].passageiros[j].sexo==2){
                            contador++;
                        }
                    }
                    if(contador==44){
                        printf("Linha de �nibus %d lotada.\n",i);
                        controle = 1;
                    }
                    contador = 0;
                }
                if(controle==0){
                    printf("Nenhum �nibus lotado.\n");
                }
                system("pause");
                system("cls");
            break;
            case 3:
                system("cls");
                controle = 0;
                do{
                    printf("Entre com a linha do �nibus: ");
                        scanf("%d",&controle);

                    if(controle>=0&&controle<=9){
                        tempo = (float)onibus[controle].distancia/velocidadeM;
                        horas = tempo;
                        minutos = (tempo-horas)*60;

                        if(onibus[controle].horario[1]+minutos>=60){
                            minutosChegada = ((minutos+onibus[controle].horario[1])%60);
                            horasChegada = (horas+onibus[controle].horario[0]+1);
                        }else{
                            minutosChegada = minutos+onibus[controle].horario[1];
                        }

                        if(horasChegada>24){
                            horasChegada = horasChegada%24;
                        }else if(horasChegada==24){
                            horasChegada = 0;
                        }

                        printf("A viagem da linha %d ter� dura��o de %d:%d com tempo estimado para �s %.2d:%.2d horas.\n",
                               controle,(int)horas,(int)minutos,horasChegada,minutosChegada);
                    }else{
                        printf("\nLinha n�o encontrada.\n");
                        system("pause");
                        system("cls");
                    }
                }while(controle<0&&controle>9);
                system("pause");
                system("cls");
            break;
            case 4:
                system("cls");
                contador = 0;
                do{
                    printf("Entre com a linha do �nibus: ");
                        scanf("%d",&controle);

                    if(controle>=0&&controle<=9){

                    for(int i = 0; i < 10; i++){
                        if(onibus[controle].passageiros[i].sexo>0&&onibus[controle].passageiros[i].sexo<3){
                            contador++;
                        }
                    }

                    if(contador>0){
                        percentual = (contador*100.0)/44;
                        printf("Percentual de ocupa�ao = %.2f%%\n",percentual);
                        printf("Poltronas livres = %d\n",44-contador);
                    }

                    }else{
                        printf("\nLinha n�o encontrada.\n");
                    }
                    system("pause");
                    system("cls");
                }while(controle<0&&controle>9);
            break;
            case 5:
                system("cls");
                contadorM = 0;
                contadorF = 0;
                do{
                    printf("Entre com a linha do �nibus: ");
                        scanf("%d",&controle);

                    if(controle>=0&&controle<=9){

                        for(int i = 0; i < 10; i++){
                            if(onibus[controle].passageiros[i].sexo>0&&onibus[controle].passageiros[i].sexo<3){
                                onibus[controle].passageiros[i].sexo==1 ? contadorM++ : contadorF++;
                            }
                        }
                        printf("Percentual de Homens = %.2f%%\nPercentual de Mulheres = %.2f%%\n",(contadorM*100.0)/44,(contadorF*100.0)/44);
                    }else{
                        printf("\nLinha n�o encontrada.\n");
                    }
                    system("pause");
                    system("cls");
                }while(controle<0&&controle>9);
            break;
            case 6:
                system("cls");
                janelaP = 0;
                janelaI = 0;
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 44; j++){
                        if(onibus[i].passageiros[j].sexo>0&&onibus[i].passageiros[j].sexo<3){
                            if(i%2==0){
                                janelaP++;
                            }else{
                                janelaI++;
                            }
                            controle++;
                        }
                    }
                    printf("Linha [%d] janela %.2f%% ocupada, corredor %.2f%% ocupado, poltronas livres = %d\n",i,(janelaI*100)/22,(janelaP*100)/22,44-controle);
                    janelaI = 0;
                    janelaP = 0;
                    controle = 0;
                }

                system("pause");
                system("cls");
            break;
            case 7:
                system("cls");
                printf("At� logo.\n");
            break;
            default:
                system("cls");
                printf("Op��o invalida\n");
                system("pause");
        }
    }while(opcao!=7);

    return 0;
}
