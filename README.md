# Métodos Numéricos

O corrente diretório contém os algoritmos implementados em linguagem C para a disciplina de Métodos Numéricos Computacionais. Os tópicos abordados estão organizados nos subdiretórios:

[Zeros de Funções](/zeros-de-funcoes/)

[Sistemas Lineares](/sistemas-lineares/)

**Sobre Arquivos Compartilhados**

Alguns arquivos são utilizados por mais de um algoritmo. São eles:
- bolzano.*: Implementação do teorema de bolzano e definição da função f(x) = x^2 - 2, que pode ser alterada
- matriz.*: Implementações de manipulação de matrizes

**Dados Gerados para Zeros de Funções**

Os algoritmos de zeros de funções geram arquivos CSV para armazenamento de dados para posterior geração de gráficos em uma linguagem R. São eles:

- bissecao.c: "dados_bissecao.csv" (a, f(a)), (b, f(b)) e (pm, f(pm))
- falsaPosicao.c: "dados_falsa_posicao.csv" (a, f(a)), (b, f(b)) e (x, f(x))
- newtonRaphson.c: "dados_newton_raphson.csv" (xAnt, xProx, fxAnt, fxProx)
- secante.c: "dados_secante.csv" (an, bn, fan, fbn, x, fx)

## Como executar

### Zeros de Funções
- Método da Bisseção: 
```
    gcc bissecao.c bolzano.c -o b
    ./b
```

- Método da Falsa Posição (das Cordas):
```
    gcc falsaPosicao.c bolzano.c -o f
    ./f
```

- Método da Newton-Raphson (das Tangentes):
```
    gcc newtonRaphson.c bolzano.c -o n
    ./n
```

- Método das Secantes:
```
    gcc secante.c bolzano.c -o s
    ./s
```

### Solução de Sistemas Lineares

- Retrosubstituição:
```
    gcc retrosubstituicao.c matriz.c -o s
    ./s
```

- Eliminação Gaussiana:
```
    gcc eliminacaoGaussiana.c matriz.c -o s
    ./s
```

- Fatoração LU:

- Método Iterativo de Gauss Jacobi:
