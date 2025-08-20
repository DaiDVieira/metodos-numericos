#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "bolzano.h"

int numeroIteracoes(float a, float b, float e){
    float n = (log10(fabs(b - a)) - log10(e))/log10(2);
    return (int)ceil(n);
}

void bisessao(float a, float b, float e, FILE *arq){
    float fa = f(a);
    float fb = f(b);
    float pm, fpm;
    while(fabs(b-a) > e){
        pm = (b+a)/2;
        fpm = f(pm);
        fprintf(arq,"%lf,%lf,%lf,%lf,%lf,%lf\n", a, b, fa, fb, pm, fpm);
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
    printf("Ponto medio %f eh solucao %f.\n", pm, fpm);
}

int main(void){
    FILE* arq;
    arq = fopen("dados_bissecao.csv", "w");
    fprintf(arq, "an,bn,fan,fbn,pm,fpm\n");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    float e, a, b;
    printf("Digite a precisao desejada: ");
    scanf(" %f", &e);
    printf("Digite um intervalo (a b): ");
    scanf(" %f %f", &a, &b);
    while(!bolzano(a, b)){
        printf("Digite um novo intervalo (a, b): ");
        scanf(" %f %f", &a, &b);
    }
    printf("Ao menos %d iteracoes serao necessarias.\n", numeroIteracoes(a, b, e));
    bisessao(a, b, e, arq);    

    fclose(arq);
    return 0;
}