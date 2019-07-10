//
// Created by erick on 10/07/2019.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

//Busca a calda de uma lista e retorna um ponteiro para ele.
TLSE* b_c(TLSE *l){
    TLSE *ult = l;
    if(l != NULL){
        while(ult->prox != NULL){
            ult = ult->prox;
        }
    }
    return ult;
}

//Copia elemento
TLSE* c_e(TLSE* e){
    TLSE *n_e = (TLSE*)malloc(sizeof(TLSE));
    n_e->info = e->info;
    n_e->prox = NULL;
    return n_e;
}

//Insere Elemento em uma lista em sua calda (último elemento)
TLSE* i_e_c(TLSE *l, TLSE *e){
    TLSE *ult = b_c(l);
    if(l != NULL){
        ult->prox = c_e(e);
    } else{
        l = c_e(e);
    }
    return l;
}

//Método da questão pedida.
/* Basicamente a ideia é criar duas listas auxiliares e ir colocando os pares e impares nas listas correspondentes.
 * No final costuro a lista de pares no final da lista impar e retorno o elemento cabeça da lista impar.
 */
TLSE* i_p( TLSE *l){
    TLSE *curr = l;
    TLSE *i = NULL;
    TLSE *p = NULL;
    do{
        if (curr->info % 2 == 0){
            //É par
            p = i_e_c(p, curr);
        } else {
            //É ímpar
            i = i_e_c(i, curr);
        }
        curr = curr->prox;
    }while(curr != NULL);
    //Costura as listas
    TLSE *ult_i = b_c(i);
    ult_i->prox = p;
    return i;
}

//Este método imprime uma lista em ordem.
void imp_l(TLSE *l){
    TLSE *ptrProx = l;
    do{
        printf("END = %d; INFO = %i ; ", (int)ptrProx, ptrProx->info);
        printf("prox = %d\n", (int)ptrProx->prox);
        ptrProx = ptrProx->prox;
    } while(ptrProx != NULL);
}