#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int number = 0;

    while(++number<=20){

        if(number%2==1){
            printf("\nO n�mero %d � impar",number);
        }

    }

    return 0;
}
