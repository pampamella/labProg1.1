#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplinasMetodos.h"

void main(){
    Disciplinas *lista = NULL;
    Disciplinas *listaLeitura;
    inserirDisciplina(&lista,10000,"matdisc","veloso",20);
    inserirDisciplina(&lista,10001,"sistdig","rotava",41);
    inserirDisciplina(&lista,10009,"fentrans","gabriel",17);
    escreverDisciplinas(&lista);
    listaLeitura = lerDisciplinas();
    printDisciplinas(&listaLeitura);
}


