#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int verificaID(Fila *N, Fila *E, int id, Fila *A)
{
    Nos *aux = N->ini;
    while (aux != NULL)
    {
        if (aux->dados.id == id)
        {
            return 1;
        }
        aux = aux->prox;
    }

    aux = E->ini;
    while (aux != NULL)
    {
        if (aux->dados.id == id)
        {
            return 1;
        }
        aux = aux->prox;
    }
    aux = A->ini;
    while (aux != NULL)
    {
        if (aux->dados.id == id)
        {
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

void imprimirFilas(Fila *N, Fila *E)
{

    fflush(stdin);
    system("cls");

    printf("\n Lista animais cadastrados:\n\n");
    printf("Emergencia:\n");
    if (VaziaFila(E))
        printf("Sem paciente na emergercia.\n");
    else
    {
        imprimeFila(E);
    }
    printf("normal:\n");
    if (VaziaFila(N))
        printf("Sem paciente.\n");
    else
    {
        imprimeFila(N);
    }
    system("pause");
}

void buscaPet(Fila *N, Fila *E, Fila *A)
{

    int id, aux = 0, tam;
    char nome[30];
    Nos *auxx;
    fflush(stdin);
    system("cls");
    if (VaziaFila(N) && VaziaFila(E) && VaziaFila(A))
    {
        printf("Sem pacientes cadastrados.\n");
    }
    else
    {
        printf("Digite o ID do pet ou o nome do pet: ");
        gets(nome);
        tam = strlen(nome);
        for (int i = 0; i < tam; i++)
        {
            if (!isdigit(nome[i]))
            {
                aux = 1;
                break;
            }
        }

        if (!aux)
        {
            id = atoi(nome);
            auxx = N->ini;
            while (auxx != NULL)
            {
                if (auxx->dados.id == id)
                {
                    printf("\nPet encontrado na fila normal:\n");
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           auxx->dados.id, auxx->dados.nome, auxx->dados.especie, auxx->dados.idade,
                           auxx->dados.nas.dia, auxx->dados.nas.mes, auxx->dados.nas.ano,
                           auxx->dados.prioridade == 1 ? "Urgente" : "Normal");
                    return;
                }
                auxx = auxx->prox;
            }
            auxx = E->ini;
            while (auxx != NULL)
            {
                if (auxx->dados.id == id)
                {
                    printf("\nPet encontrado na fila de emergencia:\n");
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           auxx->dados.id, auxx->dados.nome, auxx->dados.especie, auxx->dados.idade,
                           auxx->dados.nas.dia, auxx->dados.nas.mes, auxx->dados.nas.ano,
                           auxx->dados.prioridade == 1 ? "Urgente" : "Normal");
                    return;
                }
                auxx = auxx->prox;
            }
            auxx = A->ini;
            while (auxx != NULL)
            {
                if (auxx->dados.id == id)
                {
                    printf("\nPet encontrado na fila de atendidos:\n");
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           auxx->dados.id, auxx->dados.nome, auxx->dados.especie, auxx->dados.idade,
                           auxx->dados.nas.dia, auxx->dados.nas.mes, auxx->dados.nas.ano,
                           auxx->dados.prioridade == 1 ? "Urgente" : "Normal");
                    return;
                }
                auxx = auxx->prox;
            }
        }
        else
        {
            auxx = N->ini;
            while (auxx != NULL)
            {
                if (stricmp(auxx->dados.nome, nome) == 0)
                {
                    printf("\nPet encontrado na fila normal:\n");
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           auxx->dados.id, auxx->dados.nome, auxx->dados.especie, auxx->dados.idade,
                           auxx->dados.nas.dia, auxx->dados.nas.mes, auxx->dados.nas.ano,
                           auxx->dados.prioridade == 1 ? "Urgente" : "Normal");
                    return;
                }
                auxx = auxx->prox;
            }
            auxx = E->ini;
            while (auxx != NULL)
            {
                if (stricmp(auxx->dados.nome, nome) == 0)
                {
                    printf("\nPet encontrado na fila de emergencia:\n");
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           auxx->dados.id, auxx->dados.nome, auxx->dados.especie, auxx->dados.idade,
                           auxx->dados.nas.dia, auxx->dados.nas.mes, auxx->dados.nas.ano,
                           auxx->dados.prioridade == 1 ? "Urgente" : "Normal");
                    return;
                }
                auxx = auxx->prox;
            }
            auxx = A->ini;
            while (auxx != NULL)
            {
                if (stricmp(auxx->dados.nome, nome) == 0)
                {
                    printf("\nPet encontrado na fila de atendidos:\n");
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           auxx->dados.id, auxx->dados.nome, auxx->dados.especie, auxx->dados.idade,
                           auxx->dados.nas.dia, auxx->dados.nas.mes, auxx->dados.nas.ano,
                           auxx->dados.prioridade == 1 ? "Urgente" : "Normal");
                    return;
                }
                auxx = auxx->prox;
            }
        }
        printf("Pet não encontrado.\n");
    }
}

int main()
{

    Fila *normal = CriaFila(), *emer = CriaFila(), *atendidos = CriaFila();
    int opcao, id;
    pet aux, cad;
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    printf("\n\n\n\n\t\t\t\t=============================================\n");
    printf("\t\t\t\t        BEM-VINDO(A) À CLÍNICA VETERINÁRIA    \n");
    printf("\t\t\t\t                *** JujuVet ***               \n");
    printf("\t\t\t\t=============================================\n");
    printf("\n");
    printf(" \t\t\t\tCuidando do seu pet com amor e dedicação!\n\n\n\n");
    printf("\n");

    system("pause");
    fflush(stdin);

    while (1)
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

            id = rand() % 900 + 100;
            ;
            printf("=====================================\n");
            printf("         Cadastro do Animal           \n");
            printf("=====================================\n");

            while (verificaID(normal, emer, id, atendidos))
            {
                id = rand() % 900 + 100;
                ;
            }
            printf("ID gerado automaticamente: %d\n", id);
            cad.id = id;
            printf("Digite o nome do animal: ");
            gets(cad.nome);

            printf("Digite a especie do animal: ");
            gets(cad.especie);

            printf("Digite a idade do animal: ");
            scanf("%d", &cad.idade);

            printf("Digite a data de nascimento:\n");
            printf("Dia: ");
            scanf("%d", &cad.nas.dia);
            printf("Mes: ");
            scanf("%d", &cad.nas.mes);
            printf("Ano: ");
            scanf("%d", &cad.nas.ano);
            printf("Digite a prioridade (0 - Normal | 1 - Urgente): ");
            scanf("%d", &cad.prioridade);
            if (cad.prioridade)
            {
                InsereFila(emer, cad);
                printf("Animal cadastrado com sucesso na emergencia!!\n\n");
            }
            else
            {
                InsereFila(normal, cad);
                printf("Animal cadastrado com sucesso no atendimento normal!!\n\n");
            }
            system("pause");
            break;

        case 2:

            fflush(stdin);
            system("cls");
            printf("\nAtendimento:\n\n");

            if (VaziaFila(emer) && VaziaFila(normal))
            {
                printf("\t\tSem Pacientes!!\n");
            }
            else
            {
                if (!VaziaFila(emer))
                {
                    printf("\t Animal com prioridade atendido:\n");
                    aux = RetiraFila(emer);
                    InsereFila(atendidos, aux);
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           aux.id, aux.nome, aux.especie, aux.idade,
                           aux.nas.dia, aux.nas.mes, aux.nas.ano,
                           aux.prioridade == 1 ? "Urgente" : "Normal");
                }
                else
                {
                    printf("\t Animal sem prioridade atendido:\n");
                    aux = RetiraFila(normal);
                    InsereFila(atendidos, aux);
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           aux.id, aux.nome, aux.especie, aux.idade,
                           aux.nas.dia, aux.nas.mes, aux.nas.ano,
                           aux.prioridade == 1 ? "Urgente" : "Normal");
                }
            }

            system("pause");
            break;
        case 3:
            printf("\nBuscar um pet pelo nome e/ou ID.\n\n");
            buscaPet(normal, emer, atendidos);
            system("pause");
            break;

        case 4:
            imprimirFilas(normal, emer);
            break;



        case 5:
            fflush(stdin);
            system("cls");
            printf("\nPróximo pet a ser atendido:\n\n");
            if (VaziaFila(emer) && VaziaFila(normal))
            {
                printf("Sem pacientes .\n");
            }
            else
            {
                if(!VaziaFila(emer))
                {
                    printf("%-5d | %-15s | %-10s | %-5d | Urgente\n",
                           emer->ini->dados.id, emer->ini->dados.nome, emer->ini->dados.especie, emer->ini->dados.idade);
                }else{
                    printf("%-5d | %-15s | %-10s | %-5d | Normal\n",
                           normal->ini->dados.id, normal->ini->dados.nome, normal->ini->dados.especie, normal->ini->dados.idade);
                }
            }

            system("pause");
            break;
        case 6:
            fflush(stdin);
            system("cls");
            printf("\nPets que já foram atendidos:\n\n");
            if (VaziaFila(atendidos))
                printf("Nenhum pet foi atendido ainda.\n");
            else
            {
                imprimeFila(atendidos);
            }

            system("pause");
            break;

        case 7:
            fflush(stdin);
            system("cls");
            printf("\nSaindo do sistema. Até logo!\n");
            liberaFila(normal);
            liberaFila(emer);
            liberaFila(atendidos);
            return 0;

        default:
            printf("\nOpção inválida! Por favor, tente novamente.\n\n");
            break;
        }
    }
}
