#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    const int kmPorLitro = 12;
    int tempoGasto = 0;
    int velocidadeMedia = 0;
    int distanciaPercorrida = 0;
    float litrosUsados = 0;

    printf("\n\t\tConbust�vel gasto em Viagem");
    printf("\n\nDigite a velocidade M�dia da viagem: ");
        scanf("%d",&velocidadeMedia);
    printf("\nDigite o tempo gasto na viagem: ");
        scanf("%d",&tempoGasto);

    distanciaPercorrida = (tempoGasto * velocidadeMedia);
    litrosUsados = (float)(distanciaPercorrida / kmPorLitro);

    printf("\n\nVelocidade m�dia :%d\nTempo gasto: %d\nDist�ncia percorrida :%d\nCombustivel gasto na viagem: %.2f\n",velocidadeMedia,tempoGasto,distanciaPercorrida,litrosUsados);

    return 0;
}
