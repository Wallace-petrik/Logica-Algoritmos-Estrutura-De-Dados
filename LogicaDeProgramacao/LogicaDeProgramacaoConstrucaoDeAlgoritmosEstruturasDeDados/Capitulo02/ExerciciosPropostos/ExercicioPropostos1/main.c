#include <stdio.h>
#include <math.h>

int main(){
    int x,y;
    float z;

        scanf("%d",&x); // Atribuir dados a vari�vel X.
    printf("\n\t%d elevado ao cubo = %d\n",x,(int)pow(x,3)); //Exibir conte�do das vari�veis X e da fun��o POW.

    scanf("%d",&y);// Atribuir dados a vari�vel Y.
    printf("\n\t %d",x+y);//Exibir conte�do das soma vari�veis X e Y.

    z = (float)x/y;// Atribuir adivis�o das vari�vel X/Y.
    printf("\n\t %.1f",z);//Exibir conte�do da vari�vel Z.
    z = z+1;// Atribuir 1 mais valor de Z a vari�vel Z.
    x = (y+x)%2;// Atribuir o resto da soma de Y e X por 2 na vari�vel Z.

    printf("\n\t %d",x);//Exibir conte�do da vari�vel X.
    return 0;
}
