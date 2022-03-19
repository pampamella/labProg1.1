#include <stdlib.h>
#include <stdio.h>
#include "alunosMetodos.h"

void disciplinasPorPeriodo(listaDiscPer *inicio, int codigoPeriodo, Disciplinas **inicioDisciplinas){
    while(inicio) {
        Disciplinas *disciplinasFiltradas;
        if(codigoPeriodo == inicio-> codigoPeriodo){
            printf("\nCodigo Periodo: %d", codigoPeriodo);
            disciplinasFiltradas = buscarDiscEndereco(*inicioDisciplinas, inicio->codigoDisciplina);
            printf("\nDisciplina:  %s", disciplinasFiltradas->nome);
        }
        inicio=inicio-> proximo;
    }
}
