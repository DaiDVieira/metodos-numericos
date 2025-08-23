**SOBRE OS ARQUIVOS**

Os arquivos no corrente diretório contém os algoritmos implementados na disciplina de Métodos Numéricos Computacionais. São eles:
- bolzano.c: implemetação do teorema de bolzano e definição da função f(x) = x^2 - 2, que pode ser alterada
- bolzano.h: arquivo cabeçalho para o teorema de bolzano e definição da função f(x) = x^2 - 2
- falsa_posicao.c: implementação do método da falsa posição. Gera um arquivo chamado "dados_falsa_posicao.csv" com os valores dos pontos (a, f(a)), (b, f(b)) e (x, f(x))
- bissecao.c: implementação do método da bissessão. Gera um arquivo chamado "dados_bissecao.csv" com os valores dos pontos (a, f(a)), (b, f(b)) e (pm, f(pm))

**COMO EXECUTAR**

- Método da bisseção:
```
    gcc bissecao.c bolzano.c -o b
    ./b
```

- Método da falsa posição:
```
    gcc falsa_posicao.c bolzano.c -o f
    ./f
```