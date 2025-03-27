#include "stdio.h"
#include "string.h"

#include "Projeto.h"

int criarTarefa(ListaDeTarefas* lt)
{
    if (lt->qtd >= MAXIMO_DE_TAREFAS)
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

int modificarTarefa(ListaDeTarefas* lt)
{
    if (lt->qtd == 0)
        return 1;

    int pos;
    printf("Digite a posicao da tarefa a ser modificada: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= lt->qtd)
        return 2;

    int campo;
    printf("Digite qual campo da tarefa voce deseja modificar.\n0 - Prioridade\n1 - Descricao\n2 - Categoria\nDigite um numero de 0 a 2: ");
    scanf("%d", &campo);

    if (campo < 0 || campo >= 3)
        return 3;

    switch (campo)
    {
        case 0:
            printf("Digite a nova prioridade da tarefa: ");
            scanf("%d", &lt->tarefas[pos].prioridade);
            break;
        case 1:
            printf("Digite a nova descricao da tarefa: ");
            scanf(" %299[^\n]", &lt->tarefas[pos].descricao);
            break;
        case 2:
            printf("Digite a nova categoria da tarefa: ");
            scanf(" %99[^\n]", &lt->tarefas[pos].categoria);
            break;
    }

    return 0;
}

int deletarTodasAsTarefas(ListaDeTarefas* lt)
{
    int resposta;
    printf("Voce tem certeza que deseja deletar todas as tarefas? Este processo nao e reversivel e ira apagar todas as tarefas da lista.\n0 - Sim\n1 - Nao\nDigite um numero de 0 a 1: ");
    scanf("%d", &resposta);

    if (resposta < 0 || resposta >= 2)
        return 1;

    if (resposta == 0)
        lt->qtd = 0;

    return 0;
}

int 

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
    printf("---=== Menu ===---\n1. Criar tarefa\n2. Deletar tarefa\n3. Listar tarefas\n4. Modificar tarefa\n5. Deletar todas as tarefas.\n0. Sair\nDigite um numero (0-5): ");
}