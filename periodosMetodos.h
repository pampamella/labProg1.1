#include <stdlib.h>
#include <stdio.h>
#include "defines.h"

Periodos *buscarPeriodoEndereco(Periodos *inicio, int valor){
    while(inicio){
        if(valor==inicio->codigo){
            return inicio;
        }
        inicio=inicio->proximo;
    }
    return NULL;
}

void inserirPeriodo(Periodos **pInicio, int codigo, char *descricao){
    if(buscarPeriodoEndereco(*pInicio, codigo)){
        printf("\n Periodo ja cadastrado");
    }
    else{
        Periodos *novoElemento =(Periodos*)malloc(sizeof(Periodos));
        novoElemento->codigo=codigo;
        strcpy(novoElemento->descricao, descricao);
        novoElemento->proximo=*pInicio;
        *pInicio = novoElemento;
    }
}

void removerPeriodo(Periodos **pInicio, int valor){
    Periodos *endereco = buscarPeriodoEndereco(*pInicio, valor);
    if(endereco){
        Periodos *aux = *pInicio, *anterior = NULL;
        while(aux){
            if(valor == aux-> codigo){
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
        printf("\n Periodo nao existe");
    }
}

int escreverPeriodos(Periodos **lista){
    FILE *arquivo;
    Periodos *aux = *lista;
    arquivo = fopen("periodos.txt","w");
    if(!arquivo){
        printf("Erro de leitura");
        return 0;
    }
    while(aux){
        fprintf(arquivo,"%d",aux->codigo);
        fputs("\n",arquivo);
        fputs(aux->descricao,arquivo);
        fputs("\n",arquivo);
        fprintf(arquivo,"%c",'x');
        fputs("\n",arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    return 1;
}