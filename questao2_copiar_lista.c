#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct aluno {
    int mat;
    float cr;
    struct aluno *prox;
}TAluno;

//Faz uma cópia de uma instância de aluno específica
TAluno *copiar_aluno(TAluno *l) {
    TAluno *novo = malloc(sizeof(TAluno));
    if (l != NULL) {
        novo->cr = l->cr;
        novo->mat = l->mat;
        novo->prox = l->prox;
        return novo;
    } else {
        return NULL;
    }
}

//Basicamente é necessário criar uma lista auxiliar e ir copiando os elementos para esta lista elemento a elemento.
TAluno *copia(TAluno *l){
    TAluno *primeiro = copiar_aluno(l);
    TAluno *ultimo1 = l;
    TAluno *ultimo2 = primeiro;
    do{
        ultimo1 = ultimo1->prox;
        ultimo2->prox = copiar_aluno(ultimo1);
        ultimo2 = ultimo2->prox;
    } while(ultimo2 != NULL);

    return primeiro;
}

//Função para imprimir uma lista.
void imprime_lista(TAluno *l){
    TAluno *anterior = NULL;
    TAluno *ptrProx = l;
    do{
        printf("END = %d; CR = %f ; ", (int)ptrProx, ptrProx->cr);
        printf("Mat = %d; prox = %d\n", ptrProx->mat, (int)ptrProx->prox);
        anterior = ptrProx;
        ptrProx = ptrProx->prox;
    } while(ptrProx != NULL);
}