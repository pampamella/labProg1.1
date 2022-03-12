#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "alunosMetodos.h"


void main(){
    Disciplinas *lista = NULL;
    inserirDisciplina(&lista,10000,"matdisc","veloso",30);
    inserirDisciplina(&lista,10001,"sistdig","rotava",30);
    escreverDisciplinas(&lista);
    Periodos *periodos=NULL;
    inserirPeriodo(&periodos, 1, "2018.2");
    inserirPeriodo(&periodos, 2, "2019.1");
    escreverPeriodos(&periodos);
}


