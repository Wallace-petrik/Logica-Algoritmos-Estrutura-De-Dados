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
        printf("\nQuadr�pedes? ");
            scanf(" %c",&resp);
        if(resp=='s' || resp=='S'){
            printf("\nCarn�voros? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){
                printf("\nO animal � um LE�O.");
            }else{
                printf("\nHerb�veros? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal � um CAVALO.");
                }else{
                    printf("\nN�o foi possivel identificar o animal");
                }
            }
        }else{
            printf("\nB�pedes? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){
                printf("\nOn�voros? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal � um HOMEM.");
                }else{
                    printf("\nFrut�varos? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal � um MACACO.");
                    }else{
                        printf("\nN�o foi possivel identificar o animal");
                    }
                }
            }else {
                printf("\nVoadores? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal � um MORCEGO.");
                }else{
                    printf("\nAqu�ticos? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal � uma BALEIA.");
                    }else{
                        printf("\nN�o foi possivel identificar o animal");
                    }
                }
            }
        }

    }else{
        printf("\n� Aves? ");
            scanf(" %c",&resp);
        if(resp=='s' || resp=='S'){
            printf("\nN�o voadores? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){
                printf("\nTropicais? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal � um AVESTRUZ.");
                }else{
                    printf("\nPolares? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal � um PINGUIM.");
                    }else{
                        printf("\nN�o foi possivel identificar o animal");
                    }
                }
            }else{
                printf("\nNadadores? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal � um PATO.");
                }else{
                    printf("\nDe rapina? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal � uma �GUIA.");
                    }else{
                        printf("\nN�o foi possivel identificar o animal");
                    }
                }
            }

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
                        }else{
                            printf("\nN�o foi possivel identificar o animal");
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
