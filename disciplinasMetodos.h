#include <stdlib.h>
#include <stdio.h>

Disciplinas *buscarDiscEndereco(Disciplinas *inicio, int valor){
    while(inicio){
        if(valor==inicio->codigo){
            return inicio;
        }
        inicio=inicio->proximo;
    }
    return NULL;
}

void inserirDisciplina(Disciplinas **pInicio, int codigo, char *nome, char *professor, int creditos){
    if(buscarDiscEndereco(*pInicio, codigo)){
        printf("\nDisciplina ja cadastrada");
    }
    else{
        Disciplinas *novoElemento =(Disciplinas*)malloc(sizeof(Disciplinas));
        novoElemento->codigo=codigo;
        strcpy(novoElemento->nome, nome);
        strcpy(novoElemento->professor, professor);
        novoElemento->creditos=creditos;
        novoElemento->proximo=*pInicio;
        *pInicio = novoElemento;
    }
}

void removerDisciplina(Disciplinas **pInicio, int valor){
    Disciplinas *endereco = buscarDiscEndereco(*pInicio, valor);
    if(endereco){
        Disciplinas *aux = *pInicio, *anterior = NULL;
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
        printf("\nDisciplina nao existe");
    }
}