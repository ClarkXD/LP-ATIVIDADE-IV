#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void LimparTela(){
    system("cls || clear");
}


struct Aluno{
    char Nome [500];
    char dataNacimento [500];
    float N1, N2;
    float Media;
};
float calcularMedia(struct Aluno Aluno) {
    return (Aluno.N1 + Aluno.N2) / 2.0;
}
float estaAprovado(struct Aluno Aluno) {
    return Aluno.Media >= 7.0;
}

int main(){

    setlocale(LC_ALL, "portuguese");
    struct Aluno Aluno[5];

    for (int i = 0; i < 5; ++i) {
        
        fflush(stdin);
        printf("Digite o nome do aluno %d: ", i + 1);
        gets(Aluno[i].Nome);
        fflush(stdin);

        printf("Digite a data de nascimento do aluno %d: ", i + 1);
        gets(Aluno[i].dataNacimento);
        fflush(stdin);

        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &Aluno[i].N1);

        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &Aluno[i].N2);

        Aluno[i].Media = calcularMedia(Aluno[i]);
    }

    LimparTela();

    for (int i = 0; i < 5; ++i) {
        printf("Aluno: %s\n", Aluno[i].Nome);
        printf("M�dia: %.2f\n", Aluno[i].Media);

        if (estaAprovado(Aluno[i])) {
            printf("Situa��o: Aprovado\n");
        } else {
            printf("Situa��o: Reprovado\n");
        }

    }


    return 0;
}
