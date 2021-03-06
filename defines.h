#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct disciplinas{
    int codigo;
    char nome[50];
    char professor[50];
    int creditos;
    struct disciplinas *anterior;
    struct disciplinas *proximo;
}Disciplinas;

typedef struct listaDisciplinaPeriodo{
    int codigoDisciplina;
    int codigoPeriodo;
    struct listaDisciplinaPeriodo *anterior;
    struct listaDisciplinaPeriodo *proximo;
} listaDiscPer;

typedef struct alunos{
    int codigo;
    char nome[50];
    char cpf[12];
    struct listaDisciplinaPeriodo *lista;
    struct alunos *anterior;
    struct alunos *proximo;

}Alunos;

typedef struct periodos{
    int codigo;
    char descricao[10];
    struct periodos *anterior;
    struct periodos *proximo;
}Periodos;