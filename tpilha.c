//
// Created by erick on 10/07/2019.
//

typedef struct pilha TPilha;
TPilha * inicializa (void);
void push (TPilha *p, int elem);
int pop (TPilha *p);
void libera (TPilha *p);
int vazia (TPilha *p);


//Resposta Questão 5 - Remover todos os pares da pilha!
void retira_pares(TPilha *p){
    //Crio uma pilha auxiliar que chamei de p2.
    TPilha *p2 = inicializa();
    //Enquanto a pilha original P tiver elementos eu desempilho e empilho na pilha auxiliar se o elemento for ímpar.
    while(!vazia(p)){
        //Desempilho da pilha original
        int topo_p = pop(p);
        // Se o elemento for ímpar (Não par)...
        if(topo_p % 2 != 0){
            //Empilhar na pilha auxiliar
            push(p2, topo_p);
        }
    }
    //Todos os elementos ímpares de p estão em p2 em uma ordem inversa, precisamos ajeitá-los.
    //Enquanto a pilha auxiliar tiver elementos...
    while(!vazia(p2)){
        //Desempilhar da auxiliar e empilhar novamente na pilha original P
        push(p, pop(p2));
    }
    //Por fim, liberar espaço da pilha auxiliar.
    libera(p2);
}
