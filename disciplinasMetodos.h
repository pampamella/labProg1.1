#include <stdlib.h>
#include <stdio.h>
#include "periodosMetodos.h"

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

Disciplinas *lerDisciplinas(){
    FILE *arquivo;
    arquivo = fopen("disciplinas.txt","r");
    int codigo;
    char nome[50];
    char professor[50];
    int credito;
    char identificador;
    Disciplinas *lista = NULL;
    while(!feof(arquivo)){
        fscanf(arquivo,"%d\n %s\n %s\n %d\n %c\n",&codigo,&nome,&professor,&credito,&identificador);
        if(strcmp(&identificador,"*")){};
        inserirDisciplina(&lista,codigo,nome,professor,credito);
    }
    fclose(arquivo);
    return lista;
}

int escreverDisciplinas(Disciplinas **lista){
    FILE *arquivo;
    Disciplinas *aux = *lista;
    arquivo = fopen("disciplinas.txt","w");
    if(!arquivo){
        printf("Erro de leitura");
        return 0;
    }
    while(aux){
        fprintf(arquivo,"%d",aux->codigo);
        fputs("\n",arquivo);
        fputs(aux->nome,arquivo);
        fputs("\n",arquivo);
        fputs(aux->professor,arquivo);
        fputs("\n",arquivo);
        fprintf(arquivo,"%d",aux->creditos);
        fputs("\n",arquivo);
        fprintf(arquivo,"%c",'*');
        fputs("\n",arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    free(aux);
    return 1;
}

void printDisciplinas(Disciplinas **lista){
    int i = 1;
    Disciplinas *aux = *lista;
    while(aux){
        printf("No: %d | Codigo: %d | Nome: %s | Professor: %s | Creditos: %d \n",i,aux->codigo, aux->nome, aux->professor, aux->creditos);
        i++;
        aux = (aux)->proximo;
    }
    free(aux);
}

void printDisciplina(Disciplinas **disciplina){
    int i = 1;
    Disciplinas *aux = *disciplina;
    printf("No: %d | Codigo: %d | Nome: %s | Professor: %s | Creditos: %d \n",i,aux->codigo, aux->nome, aux->professor, aux->creditos);
    free(aux);
}
