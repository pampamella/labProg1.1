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
    float cpf;
    struct listaDisciplinaPeriodo *lista;
    struct alunos *anterior;
    struct alunos *proximo;

}Alunos;

typedef struct periodos{
    char descricao[10];
    int codigo;
    struct periodos *anterior;
    struct periodos *proximo;
}Periodos;