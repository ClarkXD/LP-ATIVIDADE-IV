#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void LimparTela(){
    system("cls || clear");
}

struct Funcionario {
    char nome[500];
    char cargo[500];
    float salario;
};
float calcularMediaSalarial(struct Funcionario funcionarios[], const char cargoAlvo[]) {
    float somaSalarios = 0;
    int contador = 0;

    for (int i = 0; i < 5; ++i) {
        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0) {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador > 0) {
        return somaSalarios / contador;
    } else {
        return 0.0;
    }
}
int main(){

    setlocale(LC_ALL, "portuguese");

    struct Funcionario funcionarios[5];

    
    for (int i = 0; i < 5; ++i) {

        fflush(stdin);
        printf("Digite o nome do funcion�rio %d: ", i + 1);
        gets(funcionarios[i].nome);
        fflush(stdin);

        printf("Digite o cargo do funcion�rio %d: ", i + 1);
        gets(funcionarios[i].cargo);
        fflush(stdin);

        printf("Digite o sal�rio do funcion�rio %d: ", i + 1);
        scanf("%f", &funcionarios[i].salario);

        printf("\n\n");
    }

    LimparTela();

    char cargoAlvo[500] = "Programador";
    float mediaSalarial = calcularMediaSalarial(funcionarios, cargoAlvo);

    printf("A m�dia salarial dos programadores �: %.2f\n", mediaSalarial);



    return 0;
}