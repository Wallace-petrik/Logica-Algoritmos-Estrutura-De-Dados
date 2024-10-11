#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    typedef struct{
        int em;
        int sm;
        int et;
        int st ;
    }Dia;

    typedef struct{
        int atraso;
        int horas;
    }TotDia;

    Dia cartao[31];
    TotDia totalDia[31];

    int cont, i, toth, totatr;

    void Entreda(){

        int dia, a, b, c, d;
        cont = 0;
        printf("Digite o Dia: ");
            scanf("%d",&dia);

         while(dia > 0 && dia <32){

            printf("Entre com os dados do cart�o\n");
            printf("Digite a entreda manh�: ");
                scanf("%d",&a);
            printf("Digite a sa�da manh�: ");
                scanf("%d",&b);
            printf("Digite a entreda tarde: ");
                scanf("%d",&c);
            printf("Digite a sa�da tarde: ");
                scanf("%d",&d);

            cartao[dia].em = a;
            cartao[dia].sm = b;
            cartao[dia].et = c;
            cartao[dia].st = d;
            cont++;

            system("pause");
            system("cls");

            printf("Digite o Dia: ");
            scanf("%d",&dia);
         }

    }

    void Calculo(){

        int Minuto(int h){
           int m;
           m = (h/100)*60+h%100;

           return m;
        }
        int Atraso(int h, int periodo){
            int a;
            a = (Minuto(h)-periodo);

            return a;
        }
        int Total (int he, int hs){
            int t;
            t = (Minuto(hs)-Minuto(he));

            return t;
        }
        for(int i=1; i < cont; i++){

            totalDia[i].atraso = (Atraso(cartao[i].em,480) + Atraso(cartao[i].et, 840));
            totalDia[i].horas = (Total(cartao[i].em, cartao[i].sm)+Total(cartao[i].et, cartao[i].st));

        }

    }

    void Impressao(){
        for(int i = 1; i <= cont; i++){
            printf("\n%d\t%d",cartao[i].em,cartao[i].sm);
            printf("\n%d\t%d",cartao[i].et,cartao[i].st);
            printf("\n%d",(totalDia->horas) / 60);
            printf("\n%d",(totalDia->horas) % 60);
            printf("\n%d",(totalDia->atraso) / 60);
            printf("\n%d",(totalDia->atraso) % 60);
        }
        printf("\n\n%d\t%d\n",(toth/cont)/60,(toth/cont)%60);
        printf("\n%d\t%d",(toth/60),toth%60);
        printf("\n%d\t%d",(totatr/cont)/60,(totatr/cont)%60);
        printf("\n%d\t%d",(totatr/60),totatr%60);
    }

    void saldoDeHoras(){

        if(totalDia->horas == 40){
            printf("\nSem horas extras e horas devidas\n");
        }else if(totalDia->horas < 40){
            printf("Total de horas devidas: %d",40 - totalDia->horas);
        }else if(totalDia->horas > 40){
            printf("Total de horas extras: %d",totalDia->horas - 40);
        }

    }

    Entreda;

    if( cont>0){

        Calculo();
        Impressao();
        saldoDeHoras();
    }


    return 0;
}
