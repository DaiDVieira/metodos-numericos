#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "bolzano.h"

float f(float x){
    return pow(x, 2) - 2;
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