#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


void main(){
    int opcaoMenuInicial=1, opcaoAluno=1, opcaoPeriodo=1, opcaoDisciplina=1, opcaoDiscPer=1;
    int codigoAluno, codigoPeriodo, codigoDisciplina, creditos;
    char nomeAluno[50], nomeDisciplina[50], professor[50], cpf[11], periodo[10];
    Periodos *resultadoPeriodo,*periodosSalvos;
    periodosSalvos = lerPeriodos();
    Disciplinas *resultadoDisciplina, *disciplinasSalvas;
    disciplinasSalvas = lerDisciplinas();
    Alunos *resultadoAluno, *alunosSalvos;
    alunosSalvos=lerAlunos();
    listaDiscPer *listaDisciplinaPeriodo=NULL;

    while(opcaoMenuInicial){
        opcoesMenuInicial();
        scanf("%d", &opcaoMenuInicial);
        if(opcaoMenuInicial == 1){ //MENU ALUNO
            while(opcaoAluno){
                opcoesMenuAluno();
                scanf("%d", &opcaoAluno);
                if(opcaoAluno==1){
                    printf("\n----Matricula novo aluno----\n");
                    printf("\nInsira o codigo do novo aluno (ex: 12345): ");
                    scanf("%d", &codigoAluno);
                    fflush(stdin);
                    printf("\nInsira o nome do aluno: ");
                    scanf("%[^'\n']s", nomeAluno);
                    printf("\nInsira o cpf do aluno (ex: 04099439089): ");
                    scanf("%s", cpf);
                    printf("\nDADOS INSERIDOS %d %s %s", codigoAluno, nomeAluno, cpf);
                    printf("\n----Disciplinas cadastradas no sistema----\n");
                    printDisciplinas(&disciplinasSalvas);
                    printf("\nInsira o codigo de uma disciplina do novo aluno: ");
                    scanf("%d", &codigoDisciplina);
                    printf("\n----Periodos cadastrados no sistema----\n");
                    printPeriodos(&periodosSalvos);
                    printf("\nInsira o codigo do periodo para esta disciplina: ");
                    scanf("%d", &codigoPeriodo);
                    inserirDiscPer(&listaDisciplinaPeriodo,codigoDisciplina, codigoPeriodo);
                    while(opcaoDiscPer){
                        printf("\nDeseja cadastrar mais disciplinas para esse aluno? \n1 - Sim\n0 - Nao\n\nOpcao: ");
                        scanf("%d", &opcaoDiscPer);
                        if(opcaoDiscPer){
                            printf("\nInsira o codigo de uma disciplina do novo aluno: ");
                            scanf("%d", &codigoDisciplina);
                            printf("\nInsira o codigo do periodo para esta disciplina: ");
                            scanf("%d", &codigoPeriodo);
                            inserirDiscPer(&listaDisciplinaPeriodo,codigoDisciplina, codigoPeriodo);
                        }
                    }
                    inserirAluno(&alunosSalvos, codigoAluno, nomeAluno, cpf, listaDisciplinaPeriodo);
                    escreverAlunos(&alunosSalvos);
                    opcaoDiscPer=1;
                }
                else if(opcaoAluno==2){
                    printf("\n----Alunos matriculados no sistema----\n");
                    printAlunos(&alunosSalvos);

                }
                else if(opcaoAluno==3){
                    printf("\n----Busca de aluno----\n");
                    printf("\nInsira o codigo de matricula do aluno que deseja buscar: ");
                    scanf("%d", &codigoAluno);
                    resultadoAluno=buscarAlunoEndereco(alunosSalvos, codigoAluno);
                    if(resultadoAluno){
                        printAluno(&resultadoAluno);
                    }
                    else{
                        printf("\nAluno nao encontrado!");
                    }
                }
                else if(opcaoAluno==4){
                    printf("\n ----Busca de alunos por disciplina e periodo----\n");
                    printf("\nAs disciplinas disponiveis sao: \n");
                    printDisciplinas(&disciplinasSalvas);
                    printf("\nInsira o codigo da disciplina que deseja filtrar: ");
                    scanf("%d", &codigoDisciplina);
                    printf("\nOs periodos disponiveis sao: \n");
                    printPeriodos(&periodosSalvos);
                    printf("\nInsira o codigo do periodo que deseja filtrar: ");
                    scanf("%d", &codigoPeriodo);
                    printf("\n----Alunos cadastrados na disciplina e periodo escolhidos----\n");
                    //invocar resultado da busca de alunos por disciplina e periodo
                }
                else if(opcaoAluno==5){
                    printf("\n aaaaaaa 5\n");
                    //dps faço esse

                }
                else if(opcaoAluno==6){
                    printf("\n----Remocao de aluno----\n");
                    printf("\n----Alunos matriculados no sistema atualmente----\n");
                    printAlunos(&alunosSalvos);
                    printf("\nInsira o codigo de matricula do aluno que deseja remover: ");
                    scanf("%d", &codigoAluno);
                    removerAluno(&alunosSalvos, codigoAluno);
                    printf("\nAluno %d removido!", codigoAluno);
                    printf("\n----Alunos matriculados no sistema atualmente (atualizado) ----\n");
                    printAlunos(&alunosSalvos);

                }
                else if(opcaoAluno==0){
                    printf("\n>>Menu anterior\n");
                }
                else {
                    printf("\n---Insira um dos valores das opcoes!---\n");
                }
            }
            opcaoAluno=1;
        }
        else if (opcaoMenuInicial==2){ //MENU DISCIPLINA
            while(opcaoDisciplina){
                opcoesMenuDisciplina();
                scanf("%d", &opcaoDisciplina);
                if(opcaoDisciplina==1){
                    printf("\n----Cadastro nova disciplina----\n");
                    printf("\nInsira o codigo da nova disciplina (ex: 1234):  ");
                    scanf("%d", &codigoDisciplina);
                    fflush(stdin);
                    printf("\nInsira o nome da disciplina: ");
                    scanf("%[^'\n']s", nomeDisciplina);
                    fflush(stdin);
                    printf("\nInsira o nome do professor: ");
                    scanf("%[^'\n']s", professor);
                    printf("\nInsira a quantidade de creditos (ex: 30): ");
                    scanf("%d", &creditos);
                    printf("\nDADOS INSERIDOS %d %s %s %d", codigoDisciplina, nomeDisciplina, professor, creditos);
                    inserirDisciplina(&disciplinasSalvas, codigoDisciplina, nomeDisciplina, professor, creditos);
                    escreverDisciplinas(&disciplinasSalvas);
                }
                else if(opcaoDisciplina==2){
                    printf("\n----Disciplinas cadastradas no sistema----\n");
                    printDisciplinas(&disciplinasSalvas);

                }
                else if(opcaoDisciplina==3){
                    printf("\n----Busca de disciplina----\n");
                    printf("\nInsira o codigo da disciplina que deseja buscar: ");
                    scanf("%d", &codigoDisciplina);
                    resultadoDisciplina=buscarDiscEndereco(disciplinasSalvas, codigoDisciplina);
                    if(resultadoDisciplina){
                        printDisciplina(&resultadoDisciplina);
                    }
                    else{
                        printf("\nDisciplina nao encontrada!");
                    }
                }
                else if(opcaoDisciplina==4){
                    printf("\n ----Busca de disciplinas por aluno e periodo----\n");
                    printf("\nOs alunos matriculados sao: \n");
                    printAlunos(&alunosSalvos);
                    printf("\nInsira o codigo do aluno que deseja fitrar: ");
                    scanf("%d", &codigoAluno);
                    printf("\nOs periodos disponiveis sao: \n");
                    printPeriodos(&periodosSalvos);
                    printf("\nInsira o codigo do periodo que deseja filtrar: ");
                    scanf("%d", &codigoPeriodo);
                    printf("\n----Disciplinas cadastrados por aluno e periodo escolhidos----\n");
                    //invocar resultado da busca de alunos por disciplina e periodo
                }
                else if(opcaoDisciplina==5){
                    printf("\n----Remocao de disciplina----\n");
                    printf("\n----Disciplinas cadastradas no sistema atualmente----\n");
                    printDisciplinas(&disciplinasSalvas);
                    printf("\nInsira o codigo da disciplina que deseja remover: ");
                    scanf("%d", &codigoDisciplina);
                    removerDisciplina(&disciplinasSalvas, codigoDisciplina);
                    escreverDisciplinas(&disciplinasSalvas);
                    printf("\nDisciplina %d removido!", codigoDisciplina);
                    printf("\n----Disciplinas cadastradas no sistema atualmente (atualizado) ----\n");
                    disciplinasSalvas=lerDisciplinas();
                    printDisciplinas(&disciplinasSalvas);
                }
                else if(opcaoDisciplina==0){
                    printf("\n>>Menu anterior\n");
                }
                else {
                    printf("\n---Insira um dos valores das opcoes!---\n");
                }
            }
            opcaoDisciplina=1;
        }
        else if (opcaoMenuInicial==3){ //MENU PERIODO
            while(opcaoPeriodo){
                opcoesMenuPeriodo();
                scanf("%d", &opcaoPeriodo);
                if(opcaoPeriodo==1){
                    printf("\n----Cadastro novo periodo----\n");
                    printf("\n\nInsira o novo periodo (ex: segundo periodo de 2018: 2018.2): ");
                    scanf("%s", periodo);
                    fflush(stdin);
                    printf("\nInsira o codigo do periodo (ex: se 2018.2, insere 20182):");
                    scanf("%d", &codigoPeriodo);
                    printf("\nDADOS INSERIDOS  %s %d", periodo, codigoPeriodo);
                    inserirPeriodo(&periodosSalvos, codigoPeriodo, periodo);
                    escreverPeriodos(&periodosSalvos);
                }
                else if(opcaoPeriodo==2){
                    printf("\n----Periodos cadastrados no sistema----\n");
                    printPeriodos(&periodosSalvos);

                }
                else if(opcaoPeriodo==3){
                    printf("\n----Busca de periodo----\n");
                    printf("\nInsira o codigo do periodo que deseja buscar: ");
                    scanf("%d", &codigoPeriodo);
                    resultadoPeriodo=buscarPeriodoEndereco(periodosSalvos, codigoPeriodo);
                    if(resultadoPeriodo){
                        printPeriodo(&resultadoPeriodo);
                    }
                    else{
                        printf("\nPeriodo nao encontrado!");
                    }
                }
                else if(opcaoPeriodo==4){
                    printf("\n----Remocao de periodo----\n");
                    printf("\n----Periodos cadastrados no sistema atualmente----\n");
                    printPeriodos(&periodosSalvos);
                    printf("\nInsira o codigo do periodo que deseja remover: ");
                    scanf("%d", &codigoPeriodo);
                    removerPeriodo(&periodosSalvos,codigoPeriodo);
                    escreverPeriodos(&periodosSalvos);
                    printf("\nPeriodo %d removido!", codigoPeriodo);
                    printf("\n----Periodos cadastrados no sistema atualmente (atualizado) ----\n");
                    periodosSalvos=lerPeriodos();
                    printPeriodos(&periodosSalvos);

                }
                else if(opcaoPeriodo==0){
                    printf("\n>>Menu anterior\n");
                }
                else {
                    printf("\n---Insira um dos valores das opcoes!---\n");
                }
            }
            opcaoPeriodo=1;
        }
        else if(opcaoMenuInicial==0){
            printf("\n-------Sistema encerrado------\n");
            break;
        }
        else{
            printf("\n---Insira um dos valores das opcoes!---\n");
        }

    }
    
  
    // Disciplinas *disciplinas = NULL;
    // Disciplinas *disciplinasSalvas;
    // inserirDisciplina(&disciplinas,10000,"matdisc","veloso",20);
    // inserirDisciplina(&disciplinas,10001,"sistdig","rotava",41);
    // inserirDisciplina(&disciplinas,10009,"fentrans","gabriel",17);
    // escreverDisciplinas(&disciplinas);
    // disciplinasSalvas = lerDisciplinas();
    // printf("\n---------Lista de Disciplinas -----------\n");
    // printDisciplinas(&disciplinasSalvas);
    // Periodos *periodos=NULL;
    // inserirPeriodo(&periodos, 1, "2018.2");
    // inserirPeriodo(&periodos, 2, "2019.1");
    // inserirPeriodo(&periodos, 3, "2019.2");
    // escreverPeriodos(&periodos);
    // Periodos *periodosSalvos;
    // periodosSalvos = lerPeriodos();
    // printf("\n---------Lista de Periodos -----------\n");
    // printPeriodos(&periodosSalvos);
    // listaDiscPer *disciplinasPeriodos = NULL;
    // inserirDiscPer(&disciplinasPeriodos, 10000, 3);
    // inserirDiscPer(&disciplinasPeriodos, 10009, 2);
    // inserirDiscPer(&disciplinasPeriodos, 10001, 2);
    // printf("\n---------Filtro por Periodo -----------\n");
    // disciplinasPorPeriodo(disciplinasPeriodos, 2, &disciplinasSalvas);

}


