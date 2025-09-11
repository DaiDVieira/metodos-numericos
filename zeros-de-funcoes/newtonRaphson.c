/*
Método de Newton Raphson (das Tangentes) para zeros de funções, por Daiane Dias Vieira
Métodos Numéricos e Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
Para executar:
    gcc newtonRaphson.c bolzano.c -o n
    ./n
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "bolzano.h"

void newtonRaphson(double xAnt, double e, FILE* arq){
    double fxAtual, dxAtual, xProx, fxProx;
    int n = 0;
    bool laco = true;
    do{
        fxAtual = f(xAnt);
        dxAtual = derivadaDeF(xAnt);
        xProx = xAnt - (fxAtual/dxAtual);
        fxProx = f(xProx);

        fprintf(arq,"%.15lf,%.15lf,%.15lf,%.15lf\n", xAnt, xProx, fxAtual, fxProx);
        if(fabs(xProx - xAnt) > e && fabs(fxProx) > e)
            xAnt = xProx;
        else
            laco = false;
        n++;
    }while(laco);
    
    printf("Ponto %.15lf eh solucao %.15lf.\n%d iteracoes foram necessarias\n", xProx, fxProx, n-1);
}

int main(void){
    FILE* arq;
    arq = fopen("dados_newton_raphson.csv", "w");
    fprintf(arq, "xAnt,xProx,fxAnt,fxProx\n");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    double x0, e;
    printf("Digite a precisao desejada: ");
    scanf(" %lf", &e);
    printf("Digite um valor inicial para x: ");
    scanf(" %lf", &x0);
    newtonRaphson(x0, e, arq);

    fclose(arq);
    return 0;
}