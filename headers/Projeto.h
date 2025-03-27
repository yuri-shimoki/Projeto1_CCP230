#pragma once

#define MAXIMO_DE_TAREFAS 100

typedef struct
{
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct
{
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

int criarTarefa(ListaDeTarefas* lt);
int deletarTarefa(ListaDeTarefas* lt);
int listarTarefas(ListaDeTarefas* lt);
int modificarTarefa(ListaDeTarefas* lt);

int carregarTarefas(ListaDeTarefas* lt, char* nomes);
int salvarTarefas(ListaDeTarefas* lt, char* nome);
void exibeMenu(void);

