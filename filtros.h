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
    Alunos *auxAlunos = *inicioAlunos;
    printf("------ Alunos no periodo %s ------\n",(buscarPeriodoEndereco(*listaPeriodos,codigoPeriodo))->descricao);
    while(auxAlunos){
        listaDiscPer *auxDiscPer = (auxAlunos)->lista;
        while(auxDiscPer){
            if(auxDiscPer->codigoPeriodo == codigoPeriodo){
                printf("%s\n",(auxAlunos)->nome);
                break;
            }
            auxDiscPer=auxDiscPer->proximo;
        }
        auxAlunos = (auxAlunos)->proximo;
    }
}

void alunosPorDisciplinaPeriodo(Alunos **inicioAlunos,int codigoPeriodo,int codigoDisciplina,Periodos **listaPeriodos, Disciplinas **inicioDisciplinas){
    Alunos *auxAlunos = *inicioAlunos;
    printf("------ Alunos na disciplina %s no periodo %s ------\n",(buscarDiscEndereco(*inicioDisciplinas,codigoDisciplina))->nome,(buscarPeriodoEndereco(*listaPeriodos,codigoPeriodo))->descricao);
    while(auxAlunos){
        listaDiscPer *auxDiscPer = (auxAlunos)->lista;
        while(auxDiscPer){
            if((auxDiscPer->codigoPeriodo == codigoPeriodo) & (auxDiscPer->codigoDisciplina == codigoDisciplina)){
                printf("%s\n",(auxAlunos)->nome);
                break;
            }
            auxDiscPer=auxDiscPer->proximo;
        }
        auxAlunos = (auxAlunos)->proximo;
    }
}

void disciplinasPorAlunoPeriodo(Alunos **inicioAlunos,int codigoPeriodo,int codigoAluno,Periodos **listaPeriodos, Disciplinas **inicioDisciplinas){
    Alunos *auxAlunos = buscarAlunoEndereco(*inicioAlunos,codigoAluno);
    printf("------ Disciplinas do aluno %s no periodo %s ------\n",(buscarAlunoEndereco(*inicioAlunos,codigoAluno))->nome,(buscarPeriodoEndereco(*listaPeriodos,codigoPeriodo))->descricao);
    listaDiscPer *auxDiscPer = (auxAlunos)->lista;
    while(auxDiscPer){
        if(auxDiscPer->codigoPeriodo == codigoPeriodo){
            printf("%s\n",(buscarDiscEndereco(*inicioDisciplinas,auxDiscPer->codigoDisciplina))->nome);
        }
        auxDiscPer=auxDiscPer->proximo;
        }
}
