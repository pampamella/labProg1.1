#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtros.h"

void opcoesMenuInicial(){
    printf("\n ------MENU INICIAL------ \n1 - Interagir com a entidade Aluno\n2 - Interagir com a entidade Disciplina\n3 - Interagir com a entidade Periodo\n0 - Sair do sistema\n\nOpcao: ");
}

void opcoesMenuAluno(){
    printf("\n ------MENU ALUNO------ \n1 - Matricular novo aluno \n2 - Ver a lista de alunos matriculados\n3 - Buscar aluno por codigo de matricula\n4 - Buscar Alunos por Disciplina e Periodo\n5 - Buscar Alunos por Periodo\n6 - Adicionar disciplina em um aluno\n7 - Remover disciplina de um aluno\n8 - Remover aluno\n0 - Voltar para menu anterior\n\nOpcao:");
}

void opcoesMenuDisciplina(){
    printf("\n------MENU DISCIPLINA------ \n1 - Cadastrar nova disciplina\n2 - Ver a lista de disciplinas cadastradas\n3 - Buscar disciplina por codigo\n4 - Buscar Disciplinas por Aluno e Periodo\n5 - Remover disciplina\n0 - Voltar para menu anterior\n\nOpcao:");
}

void opcoesMenuPeriodo(){
    printf("\n------MENU PERIODO------ \n1 - Cadastrar novo periodo\n2 - Ver a lista de periodos cadastrados\n3 - Buscar periodo por codigo\n4 - Remover periodo\n0 - Voltar para menu anterior\n\nOpcao:");
}
