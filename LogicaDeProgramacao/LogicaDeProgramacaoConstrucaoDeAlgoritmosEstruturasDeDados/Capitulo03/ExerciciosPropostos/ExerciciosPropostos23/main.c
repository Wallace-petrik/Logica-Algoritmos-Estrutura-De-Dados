#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int n1, n2, cont = 1, aux = 0;

    printf("Digite dois n�meros para in�cio e fim de um intervalo.\n");
        scanf("%d%d",&n1,&n2);

    for(int i = n1; i <= n2; i++){
        while(cont++<=n2){
            if(i%cont==0){
                aux++;
            }
        }
        if(aux==2){
            printf("\n%2d � primo.",i);

        }
        aux = 0;
        cont = 0;
    }
    return 0;
}
