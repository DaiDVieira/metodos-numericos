/*
Teorema de Bolzano - Arquivo complementar, por Daiane Dias Vieira
Métodos Numéricos e Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "bolzano.h"

double f(double x){
    return pow(x, 2) - 2;
}

double derivadaDeF(double x){
    return 2*x;
}

bool bolzano(double a, double b){
    double fa = f(a);
    double fb = f(b);
    double mul = f(a)*f(b);
    if (mul < 0){
        printf("Existe raiz de f no intervalo dado.\n");
        return true;
    }
    else if (mul == 0)
        printf("a ou b sao raizes de f.\n");
    else
        printf("Nao eh possivel dizer se ha raiz no intervalo dado. Tente novamente.\n");
    return false;
}