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

void alunosPorPeriodo(Alunos **inicioAlunos,int codigoPeriodo,Periodos **listaPeriodos){
    Periodos *auxPeriodos = *listaPeriodos;
    Alunos *auxAlunos = *inicioAlunos;
    char nome[50];
    while(auxPeriodos){
        if((auxPeriodos)->codigo==codigoPeriodo){
            strcpy(nome,(auxPeriodos)->descricao);
            break;
        }
        auxPeriodos = (auxPeriodos)->proximo;
    }
    printf("Alunos no periodo %s:\n",nome);
    while(auxAlunos){
        listaDiscPer *auxDiscPer = (*inicioAlunos)->lista;
        while(auxDiscPer){
            if(auxDiscPer->codigoPeriodo == codigoPeriodo){
                printf("%s\n",(*inicioAlunos)->nome);
                break;
            }
            auxDiscPer=auxDiscPer->proximo;
        }
        auxAlunos = (auxAlunos)->proximo;
    }
}
