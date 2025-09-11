/*
Método da Falsa Posição (das Cordas) para zeros de funções, por Daiane Dias Vieira
Métodos Numéricos e Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
Para executar:
    gcc falsaPosicao.c bolzano.c -o f
    ./f
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "bolzano.h"

void falsaPosicao(double a, double b, double e, FILE *arq){
    double fa = f(a);
    double fb = f(b);
    double x, fx;
    int n = 0; //número de iterações
    while(fabs(b-a) > e){
        x = ((a*fb) - (b*fa))/(fb - fa);
        n++;
        fx = f(x);
        fprintf(arq,"%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf\n", a, b, fa, fb, x, fx);
        if(fabs(fx) < e)
            break;
        else if((fa*fx) < 0){
            b = x;
            fb = fx;
        }
        else{
            a = x;
            fa = fx;
        }
    }
    printf("Ponto %.15lf eh solucao %.15lf.\n%d iteracoes foram necessarias\n", x, fx, n);
}

int main(void){
    FILE* arq;
    arq = fopen("dados_falsa_posicao.csv", "w");
    fprintf(arq, "an,bn,fan,fbn,x,fx\n");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    double e, a, b;
    printf("Digite a precisao desejada: ");
    scanf(" %lf", &e);
    printf("Digite um intervalo [a, b] (ex.: 0 3): ");
    scanf(" %lf %lf", &a, &b);
    while(!bolzano(a, b)){
        printf("Digite um novo intervalo [a, b] (ex.: 0 3): ");
        scanf(" %lf %lf", &a, &b);
    }
    falsaPosicao(a, b, e, arq);

    fclose(arq);
    return 0;
}