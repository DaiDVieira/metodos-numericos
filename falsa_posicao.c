#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "bolzano.h"

void falsaPosicao(float a, float b, float e, FILE *arq){
    float fa = f(a);
    float fb = f(b);
    float x, fx;
    int n = 0; //número de iterações
    while(fabs(b-a) > e){
        x = ((a*fb) - (b*fa))/(fb - fa);
        n++;
        fx = f(x);
        fprintf(arq,"%lf,%lf,%lf,%lf,%lf,%lf\n", a, b, fa, fb, x, fx);
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
    printf("Ponto %f eh solucao %f.\n%d iteracoes foram necessarias\n", x, fx, n);
}

int main(void){
    FILE* arq;
    arq = fopen("dados_falsa_posicao.csv", "w");
    fprintf(arq, "an,bn,fan,fbn,x,fx\n");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    float e, a, b;
    printf("Digite a precissao desejada: ");
    scanf(" %f", &e);
    printf("Digite um intervalo [a, b] (ex.: 0 3): ");
    scanf(" %f %f", &a, &b);
    while(!bolzano(a, b)){
        printf("Digite um novo intervalo [a, b] (ex.: 0 3): ");
        scanf(" %f %f", &a, &b);
    }
    falsaPosicao(a, b, e, arq);

    fclose(arq);
    return 0;
}