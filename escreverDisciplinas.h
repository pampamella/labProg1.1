#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

int escreverDisciplinas(Disciplinas **lista){
    FILE *arquivo;
    Disciplinas *aux = *lista;
    arquivo = fopen("disciplinas.txt","w");
    if(!arquivo){
        printf("Erro de leitura");
        return 0;
    }
    while(aux){
        printf("a");
        fprintf(arquivo,"%d",aux->codigo);
        fputs("\n",arquivo);
        fputs(aux->nome,arquivo);
        fputs("\n",arquivo);
        fputs(aux->professor,arquivo);
        fputs("\n",arquivo);
        fprintf(arquivo,"%d",aux->creditos);
        fputs("\n",arquivo);
        fprintf(arquivo,"%c",'x');
        fputs("\n",arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    return 1;
}