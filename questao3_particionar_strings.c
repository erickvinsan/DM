//
// Created by erick on 09/07/2019.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* String to SubString Function*/
char** s2ss(char *str){
    int count_barras = 0;
    //Verifico o número de barras na string original.
    for (int i = 0; i < strlen(str); i++){
        if(str[i] == '/'){
            count_barras++;
        }
    }
    //Crio ponteiros para ponteiros que serão as palavras recortadas.
    char **new_str = calloc(count_barras-1,sizeof(char*));
    //Variáveis que auxiliam no controle das posições da primeira e segunda barras que envolvem uma substring.
    int pos1 = -1, pos2 = -1;
    //Controla em qual palavra estamos.
    int count_pal_atual = 0;
    for(int i = 0; i < strlen(str); i++){
        //Capturo a posição da primeira e segunda barra.
        if (str[i] == '/' && pos1 == -1){
            pos1 = i;
        } else if (str[i] == '/' && pos1 != -1){
            pos2 = i;
        }
        //Se as duas são diferentes de -1 então achamos uma substring
        if(pos1 != -1 && pos2 != -1){
            //Calculo quantos caracteres tem essa substring
            size_t len_substr  = (int)pos2-((int)pos1)-1;
            //Aloco dinamicamente espaço em memória para ela.
            char *newstr = malloc((len_substr)* sizeof(char));
            //Copio neste espaço cada caractere sem destruir a string original
            for(int j = 0; j < len_substr; j++){
                newstr[j] = str[pos1+j+1];
            }
            //Defino o fim da substring
            newstr[len_substr] = '\0';
            //Coloco no vetor de retorno na posição correspondente.
            new_str[count_pal_atual] = newstr;
            count_pal_atual++;
            //atualizo as posições auxiliares trazendo a posição 1 para a antiga posição 2 e anulo a posição 2 para
            //que ela possa ser atualizada novamente
            pos1 = pos2;
            pos2 = -1;
        }
    }
    //Retorno do Ponteiro mestre.
    return new_str;
}
