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