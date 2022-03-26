#include <stdlib.h>
#include <stdio.h>
#include "disciplinasMetodos.h"

listaDiscPer *buscarDiscPerEndereco(listaDiscPer *inicio, int valor){
    while(inicio){
        if(valor==inicio->codigoDisciplina){
            return inicio;
        }
        inicio=inicio->proximo;
    }
    return NULL;
}

void inserirDiscPer(listaDiscPer **pInicio, int codigoDisciplina, int codigoPeriodo){
    if(buscarDiscPerEndereco(*pInicio, codigoDisciplina)){
        printf("\n O par Disciplina-Periodo ja esta cadastrado");
    }
    else{
        listaDiscPer *novoElemento =(listaDiscPer*)malloc(sizeof(listaDiscPer));
        novoElemento->codigoDisciplina=codigoDisciplina;
        novoElemento->codigoPeriodo=codigoPeriodo;  
        novoElemento->proximo=*pInicio;
        *pInicio = novoElemento;
    }
}

void removerDiscPer(listaDiscPer **pInicio, int valor){
    listaDiscPer *endereco = buscarDiscPerEndereco(*pInicio, valor);
    if(endereco){
        listaDiscPer *aux = *pInicio, *anterior = NULL;
        while(aux){
            if(valor == aux-> codigoDisciplina){
                break;
            }
            anterior=aux;
            aux= aux-> proximo;  
        }
        if(aux) {
            if(anterior){
                anterior-> proximo = aux -> proximo;
            }
            else{
                *pInicio = aux-> proximo;
            }
            free(aux);
        }
    }
    else {
        printf("\nO par Disciplina-Periodo  nao existe");
    }
}

void escreverDiscPer(listaDiscPer lista, FILE *arquivo){
    listaDiscPer *aux = &lista;
    fprintf(arquivo,"%c",'~');
    fputs("\n",arquivo);
    while(aux){
        fprintf(arquivo,"%d",aux->codigoDisciplina);
        fputs("\n",arquivo);
        fprintf(arquivo,"%d",aux->codigoPeriodo);
        fputs("\n",arquivo);
        fprintf(arquivo,"%c",'-');
        fputs("\n",arquivo);
        aux = aux->proximo;
    }        
}

listaDiscPer *lerDiscPer(FILE *arquivo){
    int codigoDisciplina;
    int codigoPeriodo;
    char identificador = '-';
    listaDiscPer *lista = NULL;
    while(identificador != '*'){
        fscanf(arquivo,"%d\n%d\n",&codigoDisciplina,&codigoPeriodo);
        int aux = codigoPeriodo;
        fscanf(arquivo,"%s\n",&identificador);
        if(identificador != '*'){
            inserirDiscPer(&lista,codigoDisciplina,aux);
        }
    }
    return lista;
}

void printDiscPer(listaDiscPer **lista){
    int i = 1;
    listaDiscPer *aux = *lista;
    while(aux){
        printf("Disciplina: %d \n",i);
        printf("Codigo da Disciplina: %d\n",aux->codigoDisciplina);
        printf("Codigo do Periodo: %d \n",aux->codigoPeriodo);
        i++;
        aux = (aux)->proximo;
    }
    free(aux);
}