//
// Created by erick on 10/07/2019.
//
#ifndef DESAFIO_MUXI_TPILHA_H
#define DESAFIO_MUXI_TPILHA_H

#endif //DESAFIO_MUXI_TPILHA_H

typedef struct pilha TPilha;
TPilha * inicializa (void);
void push (TPilha *p, int elem);
int pop (TPilha *p);
void libera (TPilha *p);
int vazia (TPilha *p);

void retira_pares (TPilha *p);
