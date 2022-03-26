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

Periodos *lerPeriodos(){
    FILE *arquivo;
    arquivo = fopen("periodos.txt","r");
    int codigo;
    char descricao[10];
    char identificador;
    Periodos *lista = NULL;
    while(!feof(arquivo)){
        fscanf(arquivo,"%d\n %s\n %c\n",&codigo,&descricao, &identificador);
        if(strcmp(&identificador,"*")){};
        inserirPeriodo(&lista,codigo,descricao);
    }
    fclose(arquivo);
    return lista;
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
        fprintf(arquivo,"%c",'*');
        fputs("\n",arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    return 1;
}

void printPeriodos(Periodos **lista){
    int i = 1;
    Periodos *aux = *lista;
    while(aux){
        printf("No: %d | Codigo: %d | Descricao: %s \n",i,aux->codigo,aux->descricao);
        i++;
        aux = (aux)->proximo;
    }
    free(aux);
}

void printPeriodo(Periodos **periodo){
    Periodos *aux = *periodo;
    printf(" Codigo: %d | Descricao: %s \n",aux->codigo,aux->descricao);  
}