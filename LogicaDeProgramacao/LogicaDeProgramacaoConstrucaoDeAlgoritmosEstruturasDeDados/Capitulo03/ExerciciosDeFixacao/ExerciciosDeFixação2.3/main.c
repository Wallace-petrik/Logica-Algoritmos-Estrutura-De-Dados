#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a = 1, b = 3, c = (-4);
    float delta,x1,x2;

    if(a == 0){
        printf("\nN�o � uma equa��o do 2� grau");
        printf("\n\n");
    }else{
        delta = pow(b,2)-4*a*c;
        if(delta<0){
            printf("\nA equa��o n�o possui solu��o real");

            printf("\n\n");
        }else if(delta==0){
            printf("\nA equan��o possui uma solu��o real");
            x1 = (- b + sqrt(delta))/2*a;
            printf("\n x� = %.1f",x1);
            printf("\n\n");
        }else{
            printf("\nA equan��o possui duas solu��o reais");
            x1 = (- b + sqrt(delta))/2*a;
            x2 = (- b - sqrt(delta))/2*a;
            printf("\nx� = %.1f",x1);
            printf("\nx� = %.1f",x2);
            printf("\n\n");
        }
    }

    return 0;
}

