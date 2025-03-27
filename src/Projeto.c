#include "stdio.h"
#include "string.h"

#include "Projeto.h"

int criarTarefa(ListaDeTarefas* lt)
{
    if (lt->qtd >= TOTAL_TAREFAS)
        return 1;
    
	Tarefa* t = &lt->tarefas[lt->qtd];

    printf("Digite a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);

    printf("Digite a categoria da tarefa: ");
    scanf(" %99[^\n]", t->categoria);

    printf("Digite a descricao da tarefa: ");
    scanf(" %299[^\n]", t->descricao);

    lt->qtd++;

    return 0;
}

int deletarTarefa(ListaDeTarefas* lt)
{
    if (lt->qtd == 0)
        return 1;
   
    int pos;
    printf("Digite a posicao da tarefa que deseja deletar: ");
    scanf("%d", &pos);
    
    if (pos < 0 || pos >= lt->qtd)
        return 2;
    
    for (; pos < lt->qtd - 1; pos++)
    {
        lt->tarefas[pos].prioridade = lt->tarefas[pos+1].prioridade; 
        strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao); 
        strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);
    }
    
    lt->qtd--;
    return 0;
}

int listarTarefas(ListaDeTarefas* lt)
{
    if (lt->qtd == 0)
        return 1;

    for(int i = 0; i < lt->qtd; i++)
        printf("- Tarefa #%d -\nPrioridade: %d\nCategoria: %s\nDescricao: %s\n\n",
            i, lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].descricao);

    return 0;
}

int carregarTarefas(ListaDeTarefas* lt, char* nome)
{
    FILE* fp = fopen(nome, "rb");
    if (fp == NULL)
        return 1;
    
    fread(lt, sizeof(ListaDeTarefas), 1, fp);
    fclose(fp);

    return 0;
}

int salvarTarefas(ListaDeTarefas* lt, char* nome)
{
    FILE* fp = fopen(nome, "wb");

    if (fp == NULL)
        return 1;
    
    fwrite(lt, sizeof(ListaDeTarefas), 1, fp);
    fclose(fp);

    return 0;
}

void exibeMenu(void)
{
    printf("---=== Menu ===---\n1. Criar tarefa\n2. Deletar tarefa\n3. Listar tarefas\n0. Sair\n");
}