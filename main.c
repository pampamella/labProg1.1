#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunosMetodos.h"


void main(){
    Disciplinas *lista = NULL;
    Disciplinas *listaLeitura;
    Alunos *alunos = NULL;
    listaDiscPer *lista1 = NULL;
    listaDiscPer *lista2 = NULL;
    inserirDiscPer(&lista1,10001,2);
    inserirDiscPer(&lista1,10005,3);
    inserirDiscPer(&lista2,10009,6);
    inserirDiscPer(&lista2,10010,5);
    inserirAluno(&alunos, 20000, "eu", "16454054780",lista1);
    inserirAluno(&alunos, 20005, "vitor", "1111113330",lista2);
    escreverAlunos(&alunos);
}


