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
    Periodos *auxPeriodos = *listaPeriodos;
    Alunos *auxAlunos = *inicioAlunos;
    Disciplinas *auxDisciplinas = *inicioDisciplinas;
    char nomePeriodo[50];
    char nomeDisciplina[50];
    while(auxPeriodos){
        if((auxPeriodos)->codigo==codigoPeriodo){
            strcpy(nomePeriodo,(auxPeriodos)->descricao);
            break;
        }
        auxPeriodos = (auxPeriodos)->proximo;
    }
    while(auxDisciplinas){
        if((auxDisciplinas)->codigo==codigoDisciplina){
            strcpy(nomeDisciplina,(auxDisciplinas)->nome);
            break;
        }
        auxDisciplinas = (auxDisciplinas)->proximo;
    }
    printf("Alunos na disciplina %s no periodo %s:\n",nomeDisciplina,nomePeriodo);
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
    Periodos *auxPeriodos = *listaPeriodos;
    Alunos *auxAlunos = *inicioAlunos;
    Disciplinas *auxDisciplinas = *inicioDisciplinas;
    char nomePeriodo[50];
    char nomeDisciplina[50];
    char nomeAluno[50];
    while(auxPeriodos){
        if((auxPeriodos)->codigo==codigoPeriodo){
            strcpy(nomePeriodo,(auxPeriodos)->descricao);
            break;
        }
        auxPeriodos = (auxPeriodos)->proximo;
    }
    while(auxAlunos){
        if((auxAlunos)->codigo==codigoAluno){
            strcpy(nomeAluno,(auxAlunos)->nome);
            break;
        }
        auxAlunos = (auxAlunos)->proximo;
    }
    printf("Disciplinas do aluno %s no periodo %s:\n",nomeAluno,nomePeriodo);
    listaDiscPer *auxDiscPer = (auxAlunos)->lista;
    while(auxDiscPer){
        if(auxDiscPer->codigoPeriodo == codigoPeriodo){
            printf("%s\n",(buscarDiscEndereco(*inicioDisciplinas,auxDiscPer->codigoDisciplina))->nome);
        }
        auxDiscPer=auxDiscPer->proximo;
        }
}
