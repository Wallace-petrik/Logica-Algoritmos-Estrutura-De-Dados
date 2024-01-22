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

    Linha onibus[10] = {{"Campinas","Rio de Janeiro","20/03/2024",17,30,400,01,"Wallace",1}};

    int opcao = 0, linhasDoOnibus = 0, controle = 0,contador = 0,horas = 0, minutos = 0, horasChegada = 0, minutosChegada = 0;
    float tempo = 0,chegada;
    const int velocidadeM = 60;

    do{
        system("cls");
        printf("1 Para buscar �nibus.\n");
        printf("2 Para linha de �nibus que est�o lotadas.\n");
        printf("3 Para informa tempo estimado de chegada e dura��o da viagem.\n");
        printf("10 Para sair\n");
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
            case 10:
                system("cls");
                printf("At� logo.\n");
            break;
            default:
                system("cls");
                printf("Op��o invalida\n");
                system("pause");
        }
    }while(opcao!=10);

    return 0;
}
