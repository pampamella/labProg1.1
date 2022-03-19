#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtros.h"


void main(){
    Disciplinas *disciplinas = NULL;
    Disciplinas *disciplinasSalvas;
    inserirDisciplina(&disciplinas,10000,"matdisc","veloso",20);
    inserirDisciplina(&disciplinas,10001,"sistdig","rotava",41);
    inserirDisciplina(&disciplinas,10009,"fentrans","gabriel",17);
    escreverDisciplinas(&disciplinas);
    disciplinasSalvas = lerDisciplinas();
    printf("\n---------Lista de Disciplinas -----------\n");
    printDisciplinas(&disciplinasSalvas);
    Periodos *periodos=NULL;
    inserirPeriodo(&periodos, 1, "2018.2");
    inserirPeriodo(&periodos, 2, "2019.1");
    inserirPeriodo(&periodos, 3, "2019.2");
    escreverPeriodos(&periodos);
    Periodos *periodosSalvos;
    periodosSalvos = lerPeriodos();
    printf("\n---------Lista de Periodos -----------\n");
    printPeriodos(&periodosSalvos);
    listaDiscPer *disciplinasPeriodos = NULL;
    inserirDiscPer(&disciplinasPeriodos, 10000, 3);
    inserirDiscPer(&disciplinasPeriodos, 10009, 2);
    inserirDiscPer(&disciplinasPeriodos, 10001, 2);
    printf("\n---------Filtro por Periodo -----------\n");
    disciplinasPorPeriodo(disciplinasPeriodos, 2, &disciplinasSalvas);

}


