/*
Teorema de Bolzano - Arquivo complementar, por Daiane Dias Vieira
Métodos Numéricos e Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "daiane_bolzano.h"

float f(float x){
    return pow(x, 3) - sin(x);
}

bool bolzano(float a, float b){
    float fa = f(a);
    float fb = f(b);
    float mul = f(a)*f(b);
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