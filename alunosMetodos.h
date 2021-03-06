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

void inserirAluno(Alunos **pInicio, int codigo, char *nome, char *cpf, listaDiscPer *listaDiscPer){
    if(buscarAlunoEndereco(*pInicio, codigo)){
        printf("\n Aluno ja cadastrado");
    }
    else{
        Alunos *novoElemento =(Alunos*)malloc(sizeof(Alunos));
        novoElemento->codigo=codigo;
        strcpy(novoElemento->nome, nome);
        strcpy(novoElemento->cpf, cpf);
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

int escreverAlunos(Alunos **lista){
    FILE *arquivo;
    Alunos *aux = *lista;
    arquivo = fopen("alunos.txt","w");
    if(!arquivo){
        printf("Erro de leitura");
        return 0;
    }
    while(aux){
        fprintf(arquivo,"%d",aux->codigo);
        fputs("\n",arquivo);
        fputs(aux->cpf,arquivo);
        fputs("\n",arquivo);
        fputs(aux->nome,arquivo);
        fputs("\n",arquivo);
        escreverDiscPer(*(aux->lista),arquivo);
        fprintf(arquivo,"%d",0);
        fputs("\n",arquivo);
        fprintf(arquivo,"%d",0);
        fputs("\n",arquivo);
        fputs("*",arquivo);
        fputs("\n",arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    free(aux);
    return 1;
}

void printAlunos(Alunos **lista){
    Alunos *aux = *lista;
    while(aux){
        printf("Codigo: %d | CPF: %s | Nome: %s \n", aux->codigo, aux->cpf, aux->nome);
        printDiscPer(&(aux->lista));
        printf("\n");
        aux = (aux)->proximo;
    }
    free(aux);
}

void printAluno(Alunos **aluno){
    Alunos *aux = *aluno;
    printf("Codigo: %d | CPF: %s | Nome: %s \n", aux->codigo, aux->cpf, aux->nome);
    printDiscPer(&(aux->lista));
}

Alunos *lerAlunos(){
    FILE *arquivo;
    arquivo = fopen("alunos.txt","r");
    int codigo;
    char aux[50];
    char nome[50];
    char cpf[12];
    char identificador;
    listaDiscPer *lista = NULL;
    Alunos *listaAlunos = NULL;
    while(!feof(arquivo)){
        
        fscanf(arquivo,"%d\n%s\n", &codigo,&cpf);
        fgets (nome, 50, arquivo);
        fscanf(arquivo, "%c\n",  &identificador);
        if(strcmp(&identificador,"~")){
            lista = lerDiscPer(arquivo);            
        };
        nome[strcspn(nome, "\n")]=0;
        inserirAluno(&listaAlunos,codigo,nome,cpf,lista);
    }
    fclose(arquivo);
    return listaAlunos;
}

void inserirDisciplinaAluno(Alunos **listaAlunos,int codigoAluno, int codigoDisciplina, int codigoPeriodo){
    Alunos *auxAluno = buscarAlunoEndereco(*listaAlunos,codigoAluno);
    inserirDiscPer(&(auxAluno->lista),codigoDisciplina,codigoPeriodo);
}

void removerDisciplinaAluno(Alunos **listaAlunos,int codigoAluno, int codigoDisciplina){
    Alunos *auxAluno = buscarAlunoEndereco(*listaAlunos,codigoAluno);
    removerDiscPer(&(auxAluno->lista),codigoDisciplina);
}