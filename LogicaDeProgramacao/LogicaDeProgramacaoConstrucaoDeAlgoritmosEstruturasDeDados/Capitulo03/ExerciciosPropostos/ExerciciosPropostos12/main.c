#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    char resp;

    printf("\nEscolha um dos animais:\n");
    printf("\nL�o | Cavalo | Homem | Macaco | Morcego | Baleia | Avestruz |\nPinguim | Pato | �guia | Tartaruga | Crocodilo | Cobra | ");

    printf("\n\nResponda s/S para SIM e n/N para n�o.\n");

    printf("\n� mam�fero? ");
        scanf(" %c",&resp);
    if(resp=='s' || resp=='S'){

        //mam�feros

    }else{
        printf("\n� Aves? ");
            scanf(" %c",&resp);
        if(resp=='s' || resp=='S'){

            //aves

        }else{
            printf("\n� R�pteis? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){

                printf("\nCom cosco? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal � uma TARTARUGA.");
                }else{
                    printf("\n� Carn�voros? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal � um CROCODILO.");
                    }else {
                        printf("\nSem patas? ");
                            scanf(" %c",&resp);
                        if(resp=='s' || resp=='S'){
                            printf("\nO animal � um COBRA.");
                        }
                    }
                }

            }else{
                printf("\nN�o foi possivel identificar o animal");
            }
        }
    }

    return 0;
}
