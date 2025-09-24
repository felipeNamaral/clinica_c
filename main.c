#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"
#include <locale.h>
#include<time.h>
#include <string.h>



int verificaID(Fila *N,Fila*E,int id)
{
    Nos *aux=N->ini;
    while(aux!=NULL)
    {
        if(aux->dados.id==id)
        {
            return 1;
        }
        aux=aux->prox;
    }

    aux=E->ini;
    while(aux!=NULL)
    {
        if(aux->dados.id==id)
        {
            return 1;
        }
        aux=aux->prox;
    }

    return 0;
}














void imprimirFilas(Fila *N,Fila* E)
{

    fflush(stdin);
    system("cls");

    printf("\n Lista animais cadastrados:\n\n");
    printf("Emergencia:\n");
    imprimeFila(E);
    printf("normal:\n");
    imprimeFila(N);
    system("pause");
}






int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int id,idade,prio;
    char nome[50],especie[30];
    data auxda;
    Fila *normal=CriaFila(),*emer=CriaFila(),*atendidos=CriaFila();
    int opcao;
    pet aux;

    printf("\n\n\n\n\t\t\t\t=============================================\n");
    printf("\t\t\t\t        BEM-VINDO(A) À CLÍNICA VETERINÁRIA    \n");
    printf("\t\t\t\t                *** JujuVet ***               \n");
    printf("\t\t\t\t=============================================\n");
    printf("\n");
    printf(" \t\t\t\tCuidando do seu pet com amor e dedicação!\n\n\n\n");
    printf("\n");

    system("pause");
    fflush(stdin);

    while(1)
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("                 MENU PRINCIPAL               \n");
        printf("---------------------------------------------\n");
        printf(" 1. Cadastrar novo animal\n");
        printf(" 2. Atender o Pet\n");
        printf(" 3. Buscar um pet pelo nome e/ou ID\n");
        printf(" 4. Imprimir um Relatório\n");
        printf(" 5. Próximo pet a ser atendido\n");
        printf(" 6. Pets que já foram atendidos\n");
        printf(" 7. Sair\n");
        printf("---------------------------------------------\n");
        printf("Digite a opção desejada: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            fflush(stdin);
            system("cls");

            id=rand() % 900 + 100;;
            printf("=====================================\n");
            printf("         Cadastro do Animal           \n");
            printf("=====================================\n");

            while(verificaID(normal,emer,id))
            {
                id=rand() % 900 + 100;;
            }
            printf("ID gerado automaticamente: %d\n", id);

            printf("Digite o nome do animal: ");
            gets(nome);

            printf("Digite a especie do animal: ");
            gets(especie);

            printf("Digite a idade do animal: ");
            scanf("%d", &idade);

            printf("Digite a data de nascimento:\n");
            printf("Dia: ");
            scanf("%d", &auxda.dia);
            printf("Mes: ");
            scanf("%d", &auxda.mes);
            printf("Ano: ");
            scanf("%d", &auxda.ano);
            printf("Digite a prioridade (0 - Normal | 1 - Urgente): ");
            scanf("%d",&prio);
            if(prio)
            {
                InsereFila(emer,id,nome,especie,idade,auxda,prio);
                printf("Animal cadastrado com sucesso na emergencia!!\n\n");
            }
            else
            {
                InsereFila(normal,id,nome,especie,idade,auxda,prio);
                printf("Animal cadastrado com sucesso no atendimento normal!!\n\n");
            }
            system("pause");
            break;








        case 2:

            fflush(stdin);
            system("cls");
            printf("\nAtendimento:\n\n");


            if(VaziaFila(emer)&&VaziaFila(normal))
            {
                printf("\t\tSem Pacientes!!\n");
            }
            else
            {
                if(!VaziaFila(emer))
                {
                    printf("\t Animal com prioridade atendido:\n");
                    aux=RetiraFila(emer);
                    InsereFila(atendidos,aux.id,aux.nome,aux.especie,aux.idade,aux.nas,aux.prioridade);
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           aux.id, aux.nome, aux.especie, aux.idade,
                           aux.nas.dia, aux.nas.mes, aux.nas.ano,
                           aux.prioridade == 1 ? "Urgente" : "Normal");
                }
                else
                {
                    printf("\t Animal sem prioridade atendido:\n");
                    aux=RetiraFila(normal);
                    InsereFila(atendidos, aux.id, aux.nome, aux.especie, aux.idade, aux.nas, aux.prioridade);
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           aux.id, aux.nome, aux.especie, aux.idade,
                           aux.nas.dia, aux.nas.mes, aux.nas.ano,
                           aux.prioridade == 1 ? "Urgente" : "Normal");
                }
            }


            system("pause");
            break;
        case 3:
            printf("\n[3] Ver histórico do animal selecionado.\n\n");
            break;



        case 4:
            imprimirFilas(normal,emer);
            break;





        case 5:
            printf("\n[5] Remarcar consulta selecionado.\n\n");
            break;
        case 6:
            printf("\n[6] Cancelar atendimento selecionado.\n\n");
            break;
        case 7:
            fflush(stdin);
            system("cls");
            printf("\nSaindo do sistema. Até logo!\n");

            return 0;

        default:
            printf("\nOpção inválida! Por favor, tente novamente.\n\n");
            break;
        }
    }

}


