#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void LimparTela(){
    system("cls || clear");
}

struct Contato{
    char nome[500];
    char telefone[500];
    char email[500];
};

char BuscarTelefone(struct Contato Contatos[], int NumeroComtatos, char nome){
    int i;
    for ( i = 0; i < NumeroComtatos; i++){
        if (strcmp(Contatos[i].nome, nome) == 0){
            return Contatos[i].telefone;
        }
        
    }
    return "N�o encontrado";
}
int main(){

    setlocale(LC_ALL, "portuguese");

    int i;
    char nomebusca[500];
    int NumeroComtatos = 3;
    struct Contato Contatos[3];

    for ( i = 0; i < 3; i++){
        printf("Digite o nome do contato %d: ", i + 1);
        scanf("%s", &Contatos[i].nome);

        printf("Digite o n�mero de telefone do contato %d: ", i + 1);
        scanf("%s", &Contatos[i].telefone);

        printf("Digite o email do contato %d: ", i + 1);
        scanf("%s", &Contatos[i].email);

    }

    LimparTela();

    printf("Digite o nome do contato que voc� buscar: ");
    scanf("%s", nomebusca);
    
    char telefoneEncontrado = BuscarTelefone(Contatos, NumeroComtatos, nomebusca);

    printf("N�mero de telefone para %s: %s\n", nomebusca, telefoneEncontrado);


    return 0;
}