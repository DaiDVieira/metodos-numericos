/*
Método da Bisseção para zeros de funções, por Daiane Dias Vieira
Métodos Numéricos e Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
Para executar:
    gcc daiane_bissecao.c daiane_bolzano.c -o b
    ./b
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "daiane_bolzano.h"

int numeroIteracoes(double a, double b, double e){
    double n = (log10(fabs(b - a)) - log10(e))/log10(2);
    return (int)ceil(n);
}

void bissecao(double a, double b, double e, FILE *arq){
    double fa = f(a);
    double fb = f(b);
    double pm, fpm;
    while(fabs(b-a) > e){
        pm = (b+a)/2;
        fpm = f(pm);
        fprintf(arq,"%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf\n", a, b, fa, fb, pm, fpm);
        if(fabs(fpm) < e){
            break;
        }
        if((fa * fpm) < 0){
            b = pm;
            fb = fpm;
        }
        else{
            a = pm;
            fa = fpm;
        }
    }
    printf("Ponto medio %.15lf eh solucao %.15lf.\n", pm, fpm);
}

int main(void){
    FILE* arq;
    arq = fopen("dados_bissecao.csv", "w");
    fprintf(arq, "an,bn,fan,fbn,pm,fpm\n");
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
    printf("Ao menos %d iteracoes serao necessarias.\n", numeroIteracoes(a, b, e));
    bissecao(a, b, e, arq);    

    fclose(arq);
    return 0;
}