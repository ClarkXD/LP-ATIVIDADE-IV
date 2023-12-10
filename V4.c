#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void LimparTela(){
    system("cls || clear");
}

struct ContaBancaria{
    int numeroConta;
    char nomeTitular[500];
    float saldo;
    char tipoConta[500];
};
void sacar(struct ContaBancaria *Conta, float valor) {
    if (valor > Conta->saldo) {
        printf("Saldo insuficiente para realizar o saque. \n");
    } else {
        Conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n",valor);
    }
}
void depositar(struct ContaBancaria *Conta, float valor) {
    Conta->saldo += valor;
    printf("Depósito de %.2f realizado com sucesso.\n",valor);
}
void Imprimir(struct ContaBancaria *Conta){
    printf("Saldo da Conta: %.2f \n",Conta->saldo);
}


int main(){

setlocale(LC_ALL, "portuguese");
    
struct ContaBancaria Conta;
    Conta.numeroConta = 121213;
    sprintf(Conta.nomeTitular, "Clark XD");
    Conta.saldo = 17578.03;
    sprintf(Conta.tipoConta, "Corrente");

    
    int opcao;
    float valor;

    do {
        printf("\n Menu:\n");
        printf("1- Depositar \n");
        printf("2- Sacar \n");
        printf("3- Imprimir Saldo \n");
        printf("0- Sair \n");
        printf("Escolha a operacao: ");
        scanf("%d", &opcao);

        LimparTela();
        
        switch (opcao) {
            case 1:
                printf("Digite o valor que quer depositar: ");
                scanf("%f", &valor);
                depositar(&Conta, valor);
                break;
            case 2:
                printf("Digite o valor que quer sacar: ");
                scanf("%f", &valor);
                sacar(&Conta, valor);
                break;
            case 3:
                Imprimir(&Conta);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida, Tente novamente.\n");
        }
    } while (opcao != 0);


    return 0;
}
