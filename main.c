#include <stdio.h>
#include <stdbool.h>
#include "questao1_sudoku.c"
#include "questao2_copiar_lista.c"
#include "questao3_particionar_strings.c"
#include "questao4_impares_pares.c"

//Nome: Erick Vinicius Valadares dos Santos
int main(void) {
    //Questão 1 =============================================
    printf("Questao 1 ========================================\n");
    int tabela_sudoku[9][9] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
                                {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    bool tabela_ok = verifica_tabela_sudoku(tabela_sudoku);
    if (tabela_ok) {
        printf("A tabela Sudoku estah correta!\n");
    } else {
        printf("A tabela Sudoku estah incorreta!\n");
    }
    // FIM Questão 1 =========================================

    // Questão 2 =============================================
    printf("\nQuestao 2 ========================================\n\n");
    TAluno a1, a2, a3, a4;
    a1.mat = 100;
    a1.cr = 7.5;
    a1.prox = &a2;
    a2.mat = 101;
    a2.cr = 8.5;
    a2.prox = &a3;
    a3.mat = 102;
    a3.cr = 9.5;
    a3.prox = &a4;
    a4.mat = 103;
    a4.cr = 10;
    a4.prox = NULL;
    printf("Lista antiga: \n");
    imprime_lista(&a1);
    TAluno *a_novo = copia(&a1);
    printf("Lista nova: \n");
    imprime_lista(a_novo);
    // FIM Questão 2 =========================================

    // Questão 3 =============================================
    printf("\nQuestao 3 ========================================\n\n");
    char *str = "/fla/flu/bota/";
    printf("String original: %s\n", str);
    char** novo_formato = s2ss(str);
    for(int i = 0; i < 3; i++){
        printf("%s\n", novo_formato[i]);
    }
    printf("String original inalterada: %s\n", str);
    // FIM Questão 3 =========================================

    // Questão 4 =============================================
    printf("\nQuestao 4 ========================================\n\n");
    TLSE e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
    e1.info = 2;
    e1.prox = &e2;
    e2.info = 4;
    e2.prox = &e3;
    e3.info = 6;
    e3.prox = &e4;
    e4.info = 3;
    e4.prox = &e5;
    e5.info = 10;
    e5.prox = &e6;
    e6.info = 5;
    e6.prox = &e7;
    e7.info = 12;
    e7.prox = &e8;
    e8.info = 7;
    e8.prox = &e9;
    e9.info = 9;
    e9.prox = &e10;
    e10.info = 14;
    e10.prox = NULL;
    TLSE *i_p_l = i_p(&e1);
    printf("Lista Impares e Pares: \n");
    imp_l(i_p_l);
    printf("\nLista Original: \n");
    imp_l(&e1);
    // FIM Questão 4 =========================================

    printf("\nQuestao 5 ========================================\n\n");
    // Questão 5 =============================================

    printf("**** RESPOSTA PARA QUESTAO 5 NO ARQUIVO tpilha.c ****\n");

    // FIM Questão 5 =========================================

    return 0;
}