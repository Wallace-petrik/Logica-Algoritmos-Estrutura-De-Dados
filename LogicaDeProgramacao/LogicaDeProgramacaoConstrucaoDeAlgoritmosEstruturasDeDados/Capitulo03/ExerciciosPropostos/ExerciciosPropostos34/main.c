#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int idade,cont=0,otimo=0,bom=0,regular=0,ruim=0,pessimo=0;
    int somaIdadeRuim = 0,contRuim=0,mOtimo=0,mRuim=0;
    char resp;

    do{

        printf("\n\tEntre com sua idade: ");
            scanf("%d",&idade);

        if(idade<0){
            printf("\n\tDados invalidos");
            continue;
        }

        printf("\t===================\n");
        printf("\tNota\tSignificado\n");
        printf("\t===================\n");
        printf("\tA\t�timo\n");
        printf("\tB\tBom\n");
        printf("\tC\tRegular\n");
        printf("\tD\tRuim\n");
        printf("\tE\tP�ssimo\n");
        printf("\t===================\n");
        scanf(" %c",&resp);

            switch(resp){
            case 'a' :
            case 'A' :
                otimo++;
                if(idade>mOtimo){
                    mOtimo=idade;
                }
            break;

            case 'b' :
            case 'B' :
                bom++;
            break;

            case 'c' :
            case 'C' :
                regular++;
            break;

            case 'd' :
            case 'D' :
                ruim++;
                somaIdadeRuim+=idade;
                contRuim++;
                if(idade>mRuim){
                    mRuim=idade;
                }
            break;

            case 'e' :
            case 'E' :
                pessimo++;
            break;
            default :
                printf("\n\tDados invalidos\n");
                continue;
        }

        cont++;
    }while(cont<4);
    if(contRuim==0){
        contRuim=1;
    }
    printf("\nRespostas com avalia��o �TIMA = %d",otimo);
    printf("\nDiferen�a porcentural entre BOM e REGULAR � %d",abs(((bom*100)/cont)-((regular*100)/cont)));
    printf("\nM�dia de respostas RUINS � = %d",somaIdadeRuim/contRuim);
    printf("\nPorcentagem de respostas PESSIMAS � %d",(pessimo*100)/cont);
    printf("\nDiferen�a das maiores idades de BOM e RUIM � %d.",abs(mOtimo-mRuim));
    return 0;
}
