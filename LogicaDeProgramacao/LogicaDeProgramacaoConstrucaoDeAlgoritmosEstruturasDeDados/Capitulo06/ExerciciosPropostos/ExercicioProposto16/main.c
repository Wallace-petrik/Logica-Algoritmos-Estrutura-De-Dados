#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define tam 3

void digitacaoValoresNoVetor(int *vetor);
void imprimirSomatorio(int *vetor);
float calcularMedia(int *vetor);
float calcularDesvioPadrao(int *vet);
void substituirValorNegativosPorZero(int *vetor);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int vet[tam] = {1,-10,100};

    //digitacaoValoresNoVetor(vet);
    //calcularMedia(vet);
    //printf("\nA m�dia � = %.2f",calcularMedia(vet));
    //printf("\nDesvio padr�o: %.2f",calcularDesvioPadrao(vet));
    substituirValorNegativosPorZero(vet);
    return 0;
}

void digitacaoValoresNoVetor(int *vetor){

    printf("Digite os valores: ");

    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor[i]);
    }

}

void imprimirSomatorio(int *vetor){
    int somatorio = 0;
    for(int i = 0; i < tam; i++){
        somatorio += vetor[i];
    }
    printf("\nO somat�rio dos itens do vetor � = %d",somatorio);
}

float calcularMedia(int *vetor){
    float media = 0, somatorio;
    for(int i = 0; i < tam; i++){
        somatorio += vetor[i];
    }
    media = (float)somatorio/tam;
    return media;
}

float calcularDesvioPadrao(int *vetor){

    float media = calcularMedia(vetor);
    float variancia = 0;
    float desvioPadrao = 0;

    for(int i = 0; i < tam; i++){
        if(media>=vetor[i]){
            variancia += (media-vetor[i])*(media-vetor[i]);
        }else{
            variancia += (vetor[i]-media)*(vetor[i]-media);
        }
    }
    variancia = variancia/tam;
    desvioPadrao = sqrt(variancia);
    return desvioPadrao;
}

void substituirValorNegativosPorZero(int *vetor){
    for(int i = 0; i < tam; i++){

        if(vetor[i]<0){
            vetor[i]=0;
        }
    }
}


