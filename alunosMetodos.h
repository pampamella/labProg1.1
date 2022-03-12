#include <stdlib.h>
#include <stdio.h>
#include "disciplinaPeriodoMetodos.h"

Alunos *buscarAlunoEndereco(Alunos *inicio, int valor){
    while(inicio){
        if(valor==inicio->codigo){
            return inicio;
        }
        inicio=inicio->proximo;
    }
    return NULL;
}

void inserirAluno(Alunos **pInicio, int codigo, char *nome, float cpf, listaDiscPer *listaDiscPer){
    if(buscarAlunoEndereco(*pInicio, codigo)){
        printf("\n Aluno ja cadastrado");
    }
    else{
        Alunos *novoElemento =(Alunos*)malloc(sizeof(Alunos));
        novoElemento->codigo=codigo;
        strcpy(novoElemento->nome, nome);
        novoElemento->cpf=cpf;
        novoElemento->lista=listaDiscPer;
        novoElemento->proximo=*pInicio;
        *pInicio = novoElemento;
    }
}

void removerAluno(Alunos **pInicio, int valor){
    Alunos *endereco = buscarAlunoEndereco(*pInicio, valor);
    if(endereco){
        Alunos *aux = *pInicio, *anterior = NULL;
        while(aux){
            if(valor == aux-> codigo){
                break;
            }
            anterior=aux;
            aux = aux-> proximo;  
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
        printf("\n Aluno nao existe");
    }
}