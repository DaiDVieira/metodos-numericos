# Métodos Numéricos

Este diretório contém os algoritmos implementados em linguagem C para a disciplina de Métodos Numéricos Computacionais. Os tópicos abordados estão organizados nos subdiretórios:

[Zeros de Funções](/zeros-de-funcoes/)

[Sistemas Lineares](/sistemas-lineares/) [EM CONSTRUÇÃO]

**Arquivos Compartilhados**

Alguns arquivos são utilizados por mais de um algoritmo. São eles:
- bolzano.*: Implementação do teorema de bolzano e definição da função f(x) = x^2 - 2, que pode ser alterada
- matriz.*: Implementações de manipulação de matrizes

**Dados Gerados (Zeros de Funções)**

Os algoritmos de zeros de funções geram arquivos CSV para armazenamento de dados para posterior geração de gráficos em uma linguagem R. São eles:

- bissecao.c: "dados_bissecao.csv" (a, f(a)), (b, f(b)) e (pm, f(pm))
- falsaPosicao.c: "dados_falsa_posicao.csv" (a, f(a)), (b, f(b)) e (x, f(x))
- newtonRaphson.c: "dados_newton_raphson.csv" (xAnt, xProx, fxAnt, fxProx)
- secante.c: "dados_secante.csv" (an, bn, fan, fbn, x, fx)

## Como executar

### Zeros de Funções
Todos os métodos desta categoria utilizam o arquivo `bolzano.c`. Cada um contém instruções de compilação e execução no cabeçalho, mas, de forma genérica, podem ser executados com os comando abaixo:

```
    gcc <arquivo>.c bolzano.c -o <executavel>
    ./<executavel>
```

### Solução de Sistemas Lineares
Todos os métodos desta categoria utilizam o arquivo `matriz.c`. Cada um contém instruções de compilação e execução no cabeçalho, mas, de forma genérica, podem ser executados com os comando abaixo:

```
    gcc <arquivo>.c matriz.c -o <executavel>
    ./<executavel>
```