#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

int option;
int Naluno = 0;
int aux = 0;

typedef struct{
    char nome[30];
    int idade;
    float nota;
    int num;

}alunos;

alunos aluno[2];

void inserir(){
    
    system("cls");

    if (Naluno<2){
        for(int i = 0; i < 2; i++){

            fflush(stdin);
            printf("Nome: ");
            gets(aluno[i].nome);

            printf("Idade: ");
            scanf("%d", &aluno[i].idade);


            printf("Nota: ");
            scanf("%f", &aluno[i].nota);

            printf("Numero: ");
            scanf("%d", &aluno[i].num);

            while (aluno[i].num <= 0){
                printf("Coloque um numero valido: ");
                scanf("%d", &aluno[i].num);
            }


            printf("\n\nAluno Inserido\n\n");
            Naluno++;

        }
    }
    else
    {
        printf("A turma ja esta preenchida!\n\n");
        printf("A regressar ao menu...");
        sleep(2);

        return main();
    }

    getchar();
}
void listar(){

    for (int i = 0; i < 2; i++)
    { 
        if (aluno[i].idade != 0){
            printf("\n");
            printf("Nome: %s\n", aluno[i].nome);
            printf("Idade: %d\n", aluno[i].idade);
            printf("Nota: %.2f\n", aluno[i].nota);
            printf("Numero: %d\n", aluno[i].num);
        }
    }
getchar();
printf("\n");
}

void atualizar(){

    system("cls");

    printf("\n");
    fflush(stdin);

    printf("Atualize o nome: ");
    gets(aluno[option].nome);

    printf("Atualize a idade: ");
    scanf("%d", &aluno[option].idade);

    printf("Atualize a nota: ");
    scanf("%f", &aluno[option].nota);

    printf("Atualize o numero: ");
    scanf("%d", &aluno[option].num);

    printf("\nAluno Atualizado\n");
    printf("A regressar ao menu...");
    sleep(2);

    return main();

}
void eliminar(){

    printf("Qual o aluno que deseja remover? ");
    scanf("%d", &option);

    for(int i = (option-1); i < 2; i++){
        aluno[i] = aluno[i+1];
    }

    printf("A regressar ao menu...");
    sleep(2);

    return main();

}

void main(){

    do
    {
        system("cls");
        
        printf("Alunos\n\n");
        printf("1- Inserir\n");
        printf("2- Listar\n");
        printf("3- Atualizar\n");
        printf("4- Eliminar\n");
        printf("0- Sair\n\n");

        printf("Qual e o objetivo? ");
        scanf("%d", &option);

        switch(option){
            case 1: inserir();
            printf("\nA regressar ao menu...");
            sleep(2);   
            break;

            case 2: 

                system("cls");                
                
                listar();

                int option2;
                printf("Deseja voltar ao menu?\n");
                printf(" 1 :: Sim || 2 :: Nao\n");
                scanf("%d", &option2);

                if (option2==1)
                    break;

                else{
                    system("cls");
                    exit(0);
                }            

            case 3:
                system("cls");
                listar();
                printf("\n");
                
                printf("Que aluno deseja atualizar\n");
                scanf("%d", &option);

                option = option-1;

                atualizar();
                break;

            case 4: 
                system("cls");
                listar();

                printf("\n");
                eliminar();
                break;
        }
    } while (option!=0);
}