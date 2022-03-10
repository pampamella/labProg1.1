
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escreverDisciplinas.h"
#include "disciplinasMetodos.h"


void main(){
    Disciplinas *lista = NULL;
    inserirDisciplina(&lista,10000,"matdisc","veloso",30);
    inserirDisciplina(&lista,10001,"sistdig","rotava",30);
    escreverDisciplinas(&lista);
}


