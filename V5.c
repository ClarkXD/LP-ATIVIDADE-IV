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
float calcularMediaSalarial(struct Funcionario funcionarios[], char cargoAlvo[]) {
    float somaSalarios = 0;
    int contador = 0;
    int i;

    for ( i = 0; i < 5; ++i) {
        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0) {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador > 0) {
        return somaSalarios / contador;
    } else {
        return 0;
    }
}
int main(){

    setlocale(LC_ALL, "portuguese");

    struct Funcionario funcionarios[5];
    int i;
    
    for ( i = 0; i < 5; ++i) {
        printf("Cargos Disponiveis \n);
        printf("Progamador \n);
        printf("Analista \n);

        fflush(stdin);
        printf("Digite o nome do funcionÃ¡rio %d: ", i + 1);
        gets(funcionarios[i].nome);
        fflush(stdin);

        printf("Digite o cargo do funcionÃ¡rio %d: ", i + 1);
        gets(funcionarios[i].cargo);
        fflush(stdin);

        printf("Digite o salÃ¡rio do funcionÃ¡rio %d: ", i + 1);
        scanf("%f", &funcionarios[i].salario);

        
    }

    LimparTela();

    char cargoAlvo[500] = "Programador";
    float mediaSalarial = calcularMediaSalarial(funcionarios, cargoAlvo);

    printf("A mÃ©dia salarial dos programadores Ã©: %.2f\n", mediaSalarial);



    return 0;
}
