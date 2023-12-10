#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void LimparTela(){
    system("cls || clear");
}

struct Produto {
    char Nome[500];
    float Preco;
    int QuantidadeEst;
};

void realizarCompra(struct Produto *Produto, int quantidadeComprada) {
    if (quantidadeComprada > 0 && quantidadeComprada <= Produto->QuantidadeEst) {
        Produto->QuantidadeEst -= quantidadeComprada;
        printf("Compra realizada com sucesso!\n");
        printf("Quantidade comprada: %d\n", quantidadeComprada);
    } else if (quantidadeComprada <= 0) {
        printf("Quantidade inválida para compra.\n");
    } else {
        printf("Quantidade insuficiente em estoque.\n");
    }
}

float calcularValorTotal(const struct Produto Produto) {
    return Produto.Preco * Produto.QuantidadeEst;
}

void consultarEstoque(const struct Produto *Produto) {
    printf("Nome do produto: %s\n", Produto->Nome);
    printf("Preço: %.2f\n", Produto->Preco);
    printf("Quantidade em estoque: %d\n", Produto->QuantidadeEst);
    printf("Valor total em estoque: %.2f\n", calcularValorTotal(*Produto));
}

int main() {
    
    setlocale(LC_ALL, "portuguese");

    struct Produto Produto;
    strcpy(Produto.Nome, "Relogio CASIO");
    Produto.Preco = 160.90;
    Produto.QuantidadeEst = 35;

    int opcao;
    int quantidadeComprada;

    do {
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        
        LimparTela();

        switch (opcao) {
            case 1:
                printf("Informe a quantidade a ser comprada: ");
                scanf("%d", &quantidadeComprada);
                realizarCompra(&Produto, quantidadeComprada);
                break;
            case 2:
                consultarEstoque(&Produto);
                break;
            case 3:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
