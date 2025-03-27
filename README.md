# Projeto em C de CCP230 (parte 1)

## Integrantes

- Yuri da Silva Shimoki (RA: 24.224.002-6)

## Problemas Corrigidos

- **Formatação do Código:** o código original encontrava-se sem nenhuma forma de formatação, faltando, especialmente, em identações e espaçamentos entre certos elementos sintáticos (como entre o operador de atribuição =, o valor e a variável sendo atribuída).
- **Erros de Digitação:** certas partes do código apresentavam erros de digitação. Entre esses erros havia:
        - **Falta de ; (ponto e vírgula):** uma linha de código não possuia um ; (ponto e vírgula) quando deveria.
        - **Inclusão de .h com o nome errado:** uma inclusão de cabeçalho incluia o arquivo "projeto.h", enquanto que o arquivo original se chamava "Projeto.h", capitalizado.
        - **Falta de um operador & ("endereço de"):** uma das linhas de código passava por valor, como argumento de uma função, uma struct do tipo ListaDeTarefas, enquanto que a definição original da função requisitava um valor do tipo ListaDeTarefas* (um ponteiro para uma struct ListaDeTarefas).
        - **Struct com o nome incorreto:** a struct ListaDeTarefas havia sido erroneamente escrita como ListaDeTarefa, com o sinalizador de plural faltando. O resto do código referenciava a struct ListaDeTarefas, enquanto na definição original estava ListaDeTarefa.
- **Erros de lógica:** a lógica de algumas partes do código foi corrigida. Por exemplo, em um certo trecho do código, um código de erro era retornado de uma função, e, dependendo do valor desse código, um certo texto era imprimido na tela. No código original, uma das verificações do valor desse código imprimia uma mensagem de erro quando o código representava execução bem-sucedida, o que caracteriza um erro lógico. Erros desse tipo foram corrigidos, e agora a lógica do programa está como se espera. 
- **Estrutura de Arquivos:** todos os arquivos do projeto se encontravam na mesma pasta raiz. Agora, os arquivos de cabeçalho se encontram na pasta headers/ e os arquivos de código C se encontram na pasta src/. O arquivo README.md se encontra na pasta raiz.

## Funcionalidades novas

3 funcionalidades novas foram adicionadas ao programa:
- **Modificar uma tarefa da lista:** o usuário agora pode modificar a prioridade, categoria ou descrição de uma das tarefas da lista.
- **Deletar todas as tarefas da lista:** o usuário agora pode deletar todas as tarefas da lista de uma vez só.
- **Ordenar lista pela prioridade das tarefas:** o usuário agora pode ordenar as tarefas na lista pela ordem decrescente de prioridade.

## Compilação e execução

Para compilar o código utilizando o GCC, abra o terminal, vá para a pasta raiz do projeto e digite no terminal a linha de comando a seguir:

```gcc -I headers -Ofast src/*.c -o projeto```

O resultado será um executável chamado `projeto.exe`. Assumindo que você ainda esteja na pasta raiz, você pode executá-lo no terminal escrevendo o comando:

```.\projeto.exe```

No Windows, ou:

```./projeto```

No Linux.
