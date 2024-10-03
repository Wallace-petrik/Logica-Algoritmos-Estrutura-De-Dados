#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int numeroDoCheque;
    int agencia;
    int conta;
    int dv;
    char nome[10];
    float valor;
}Cheque;

FILE *arqCheque;
Cheque cheque;

void leituraDosCheques();
void menu();

int main(){
    setlocale(LC_ALL,"Portuguese");

    menu();

    return 0;
}

void menu(){

    int opcao = 0;

    do{
        printf("1 /p leitua do cheque\n");
        printf("0 /p sai\n\n");

        printf("Digite uma op��o: ");
            scanf("%d",&opcao);

        switch(opcao){
            case 0:
                system("cls");
                printf("At� logo !!!\n\n");
            break;
            case 1:
                system("cls");
                leituraDosCheques();
            break;
            default:
                printf("Op��o invalida!!!\n");
                system("pause");
                system("cls");

        }

    }while(opcao!=0);

}

void leituraDosCheques(){
    if((arqCheque = fopen("arquivo.dat","a+b"))==NULL){
       printf("Erro ao abrir o arquivo!!!\n");
       system("pause");
       exit(1);
    }else{
        printf("Entre com os dados do cheque\n");
        printf("N�mero do cheque: ");
            scanf("%d",&cheque.numeroDoCheque);
        printf("Ag�ncia: ");
            scanf("%d",&cheque.agencia);
        printf("Conta: ");
            scanf("%d",&cheque.conta);
            cheque.dv = digitoVerificador(cheque.conta);
        printf("Nome: ");
            fflush(stdin);
            scanf("%[^\n]",&cheque.nome);
        printf("Valor: ");
            scanf("%f",&cheque.valor);

        fwrite(&cheque,1,sizeof(cheque),arqCheque);
        system("cls");
    }
    if(fclose(arqCheque)!= 0){
        printf("Erro ao fechar o arquivo!!!");
        exit(1);
    }
}

int inversorNumero(int numeroParaInverter){
    int rev = 0;
    int num = numeroParaInverter;
    while (num != 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }
    return rev + numeroParaInverter;
}

int qualcularQuantidadeDeDigitos(int numero){

    int quantidadeDeDigitos = 0;

    while(numero>0){

        numero = numero/10;
        quantidadeDeDigitos++;
    }

    return quantidadeDeDigitos;
}

void digitoVerificador(int numeroConta){

    int digito = 0, soma = 0;

    int numeroInvertido = inversorNumero(numeroConta);
    int quantidadeDeDigitos = qualcularQuantidadeDeDigitos(numeroInvertido);

    for(int i = quantidadeDeDigitos; i >= 1; i--){

        digito = numeroInvertido % 10;
        soma += digito * i;
        numeroInvertido /= 10;

    }
    return soma;
}


