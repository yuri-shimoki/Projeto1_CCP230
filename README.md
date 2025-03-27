# Projeto em C de CCP230 (parte 1)

## Integrantes

- Yuri da Silva Shimoki (RA: 24.224.002-6)

## Problemas Corrigidos

- *Formatação do Código:* o código original encontrava-se sem nenhuma forma de formatação, faltando, especialmente, em identações e espaçamentos entre certos elementos sintáticos (como entre o operador de atribuição =, o valor e a variável sendo atribuída).
- *Erros de Digitação:* certas partes do código apresentavam erros de digitação. Entre esses erros havia:
        - *Falta de ; (ponto e vírgula):* uma linha de código não possuia um ; (ponto e vírgula) quando deveria.
        - *Inclusão de .h com o nome errado:* uma inclusão de cabeçalho incluia o arquivo "projeto.h", enquanto que o arquivo original se chamava "Projeto.h", capitalizado.
        - *Falta de um operador & ("endereço de"):* uma das linhas de código passava por valor, como argumento de uma função, uma struct do tipo ListaDeTarefas, enquanto que a definição original da função requisitava um valor do tipo ListaDeTarefas* (um ponteiro para uma struct ListaDeTarefas).
        - *Struct com o nome incorreto:* a struct ListaDeTarefas havia sido erroneamente escrita como ListaDeTarefa, com o sinalizador de plural faltando. O resto do código referenciava a struct ListaDeTarefas, enquanto na definição original estava ListaDeTarefa.
- *Estrutura de Arquivos:* todos os arquivos do projeto se encontravam na mesma pasta raiz. Agora, os arquivos de cabeçalho se encontram na pasta headers/ e os arquivos de código C se encontram na pasta src/. O arquivo README.md se encontra na pasta raiz.

## Funcionalidades novas



## Compilação e execução

