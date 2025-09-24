#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <string.h>

/* FUNÇÕES DE MANIPULAÇÃO DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÁ VAZIA RETORNA 1 QUANDO ESTÁ VAZIA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/

typedef struct data
{
    int dia,mes,ano;
} data;


typedef struct pet
{
    int id;
    char nome[50];
    char especie[30];
    int idade;
    data nas;
    int prioridade;
} pet;

typedef struct nos
{
    pet dados;
    struct nos *prox;
} Nos;

typedef struct fila
{
    Nos * ini;
    Nos * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Nos* ins_fim (Nos *fim, int id,char nome[],char especie[],int idade,data auxda,int prio)
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->dados.id=id;
    strcpy(p->dados.nome, nome);
    strcpy(p->dados.especie, especie);
    p->dados.idade=idade;
    p->dados.nas=auxda;
    p->dados.prioridade=prio;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
        fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int id,char nome[],char especie[],int idade,data auxda,int prio)
{

    f->fim = ins_fim(f->fim,id,nome,especie,idade,auxda,prio);
    if (f->ini==NULL) /* fila antes vazia? */
        f->ini = f->fim;
}

Nos* retira_ini (Nos* ini)
{
    Nos* p = ini->prox;
    free(ini);
    return p;
}

pet RetiraFila (Fila* f)
{
    pet D;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0);
    }
    D = f->ini->dados;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL)
    f->fim = NULL;
    return D;
}





void imprimeFila (Fila* f)
{
    Nos* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
               q->dados.id, q->dados.nome, q->dados.especie, q->dados.idade, q->dados.nas.dia, q->dados.nas.mes, q->dados.nas.ano,
               q->dados.prioridade == 1 ? "Urgente" : "Normal");;
    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    Nos* q = f->ini;
    while (q!=NULL)
    {
        Nos* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

#endif // FILA_H_INCLUDED
