#include <stdio.h>
#include <stdbool.h>

#define SOMA_1_9 45

//Verifica se a soma de cada linha é diferente do valor limite individualmente.
bool verifica_linhas_sudoku(int tabela[9][9]){
    int aux_somas_linhas[9] = {0};
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            aux_somas_linhas[i] += tabela[j][i];
        }
        if ((aux_somas_linhas[i] != SOMA_1_9)){
            printf("Problema na Linha %d!", i);
            return false;
        }
    }
    return true;
}

//Verifica se a soma de cada coluna é diferente do valor limite individualmente.
bool verifica_colunas_sudoku(int tabela[9][9]){
    int aux_somas_colunas[9] = {0};
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            aux_somas_colunas[i] += tabela[i][j];
        }
        if ((aux_somas_colunas[i] != SOMA_1_9)){
            printf("Problema na Coluna %d!", i);
            return false;
        }
    }
    return true;
}

//Verifica se em cada sub-bloco da tabela sudoku, a soma dos valores é igual ao valor limite
bool verifica_sub_blocos_sudoku(int i, int j, int tabela[9][9]){
    int aux_soma_bloco = 0;
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            aux_soma_bloco += tabela[i * 3 + k][j * 3 + l];
        }
    }
    if (aux_soma_bloco != SOMA_1_9) {
        printf("%d", aux_soma_bloco);
        printf("Problema no bloco %d,%d!", i, j);
        return false;
    }
    return true;
}


//Verifica todos os blocos...
bool verifica_blocos_sudoku(int tabela[9][9]){
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (verifica_sub_blocos_sudoku(i, j, tabela) != true) {
                printf("Problema no bloco %d,%d!", i, j);
                return false;
            }
        }
    }
    return true;
}


//Se as linhas, as colunas e cada sub-bloco tiver a soma 45, que é a soma de 1 até 9, então a tabela está OK
//Do contrário existe problema ou nas linhas, ou colunas ou sub-blocos.
bool verifica_tabela_sudoku(int tabela[9][9]){
    if (verifica_linhas_sudoku(tabela) && verifica_colunas_sudoku(tabela) && verifica_blocos_sudoku(tabela)){
        return true;
    }
    return false;
}