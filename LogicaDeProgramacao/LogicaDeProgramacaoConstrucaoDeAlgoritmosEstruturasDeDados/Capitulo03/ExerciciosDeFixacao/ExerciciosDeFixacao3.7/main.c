#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int number,maior,menor;
    int i;

    maior = number;
    menor = number;

    while(++i<=20){
        printf("\nEntre com o %d� n�mero: ",i);
            scanf("%d",&number);

            if(i==1){
                maior = number;
                menor = number;
            }else{
                if(number>maior){
                    maior=number;
                }else{
                    if(number<menor){
                        menor=number;
                    }
                }
            }


    }

    printf("\nO maior n�mero = %d.\nO menor n�mero = %d.\n",maior,menor);
    return 0;
}
