/*
Método de Newton Raphson (das Tangentes) para zeros de funções, por Daiane Dias Vieira
Métodos Numéricos e Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
Para executar:
    gcc secante.c bolzano.c -o s
    ./n
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "bolzano.h"

void secante(double x0, double x1, double e, FILE* arq){
    double xProx, xAtual = x1, xAnt = x0, fxAtual, fxAnt, fxProx;
    bool laco = true;
    int n = 0;
    do{
        fxAtual = f(xAtual);
        fxAnt = f(xAnt);
        xProx = xAtual - (fxAtual*(xAtual - xAnt))/(fxAtual - fxAnt);
        fxProx = f(xProx);
        fprintf(arq,"%.15lf,%.15lf,%.15lf,%.15lf,%.15lf\n", xAnt, xAtual, xProx, fxAnt,fxAtual, fxProx);
        if(fabs(xAtual - xAnt) > e && fabs(fxProx) > e){
            xAnt = xAtual;
            xAtual = xProx;
        }
        else{
            laco = false;
        }
        n++;
    }while(laco);

    printf("Ponto %.15lf eh solucao %.15lf.\n%d iteracoes foram necessarias\n", xProx, fxProx, n-1);
}

int main(void){
    FILE* arq;
    arq = fopen("dados_secante.csv", "w");
    fprintf(arq, "an,bn,fan,fbn,x,fx\n");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    double e, x0, x1;
    printf("Digite a precisao desejada: ");
    scanf(" %lf", &e);
    printf("Digite os valores x0 e x1 (ex.: 0 3): ");
    scanf(" %lf %lf", &x0, &x1);

    secante(x0, x1, e, arq);

    fclose(arq);
    return 0;
}