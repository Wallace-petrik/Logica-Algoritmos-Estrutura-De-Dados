#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    const float pi = 3.14;
    float raio,area;

    printf("\nEntre com a raio para calcular a �rea do c�rculo: ");
        scanf("%f",&raio);

    area = pi*raio*raio;

    printf("\n�rea do c�rculo � = %.2f\n",area);

    return 0;
}
