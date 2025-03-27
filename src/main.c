#include "stdio.h"
#include "stdlib.h"

#include "Projeto.h"

int main(void)
{
    ListaDeTarefas lt;
    lt.qtd = 0;

    char* arquivo = "tarefas";
    int codigo, opcao;

    codigo = carregarTarefas(&lt, arquivo);

    if (codigo != 0)
        printf("Nao foi encontrado uma lista de tarefas pre-existente.\n");

    do
    {
        exibeMenu();
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            break;
        }
        else if (opcao == 1)
        {
            codigo = criarTarefa(&lt);
            if (codigo == 1)
                printf("Erro ao criar tarefa: Sem espaco disponivel. Delete uma tarefa para liberar espaco.\n\n");
            else if (codigo == 2)
                printf("O valor da prioridade nao pode ser um numero negativo.\n\n");
        }
        else if (opcao == 2)
        {
            codigo = deletarTarefa(&lt);

            if (codigo == 1)
                printf("Nao ha tarefas para serem deletadas.\n\n");
            else if (codigo == 2)
                printf("A posicao digitada nao corresponde a uma tarefa existente.\n\n");
        }
        else if (opcao == 3)
        {
            codigo = listarTarefas(&lt);
            if (codigo == 1)
                printf("A lista de tarefas esta vazia.\n\n");
        }
        else if (opcao == 4)
        {
            codigo = modificarTarefa(&lt);
            if (codigo == 1)
                printf("Nao ha tarefas para serem modificadas.\n\n");
            else if (codigo == 2)
                printf("A posicao digitada nao corresponde a uma tarefa existente.\n\n");
            else if (codigo == 3)
                printf("O numero de campo digitado nao e um numero de 0 a 2.\n\n");
            else if (codigo == 4)
                printf("O valor da prioridade nao pode ser um numero negativo.\n\n");
        }
        else if (opcao == 5)
        {
            codigo = deletarTodasAsTarefas(&lt);
            if (codigo == 1)
                printf("O numero digitado nao e um numero de 0 a 1.\n\n");
        }
        else if (opcao == 6)
        {
            codigo = ordenarTarefas(&lt);
            if (codigo == 1)
                printf("Nao ha tarefas o suficiente para serem ordenadas.\n\n");
        }
        else
            printf("Opcao invalida.\n\n");

    } while (opcao != 0);

    codigo = salvarTarefas(&lt, arquivo);
    if (codigo == 1)
        printf("Erro: A lista de tarefas nao pode ser salva.");
}
