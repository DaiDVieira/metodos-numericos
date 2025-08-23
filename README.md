**SOBRE OS ARQUIVOS**

Os arquivos no corrente diretório implementam os algoritmos dos métodos da bisseção e da falsa posição, além do teorema de bolzano. São eles:
- daiane_bolzano.c: implemetação do teorema de bolzano e definição da função f(x) = x^2 - 2, que pode ser alterada
- daiane_bolzano.h: arquivo cabeçalho para o teorema de bolzano e definição da função f(x) = x^2 - 2
- daiane_falsa_posicao.c: implementação do método da falsa posição. Gera um arquivo chamado "dados_falsa_posicao.csv" com os valores dos pontos (a, f(a)), (b, f(b)) e (x, f(x))
- daiane_bissecao.c: implementação do método da bissessão. Gera um arquivo chamado "dados_bissecao.csv" com os valores dos pontos (a, f(a)), (b, f(b)) e (pm, f(pm))
- graficos_bissecao_falsa_posicao.pdf: imagens dos gráficos obtidos com cada método usando três casos de teste

**COMO EXECUTAR**

<ins>- Método da bisseção:</ins>
```
    gcc bissecao.c bolzano.c -o b
    ./b
```

<ins>- Método da falsa posição:</ins>
```
    gcc falsa_posicao.c bolzano.c -o f
    ./f
```