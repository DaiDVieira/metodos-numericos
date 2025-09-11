#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

double* resolveSistema(double** A, int n, double* b){
    double* x = alocaVetor(n);
    x[n-1] = b[n-1]/A[n-1][n-1];
    for(int i = n-2; i >= 0; i--){
        double soma = 0;
        for(int j = i+1; j < n; j++){
            soma = soma + (A[i][j] * x[j]);
        }
        x[i] = (b[i] - soma)/A[i][i];
    }
    return x;
}

void imprimeSolucao(double* x, int n){
    printf("Solucao do sistema linear:\n");
    for(int i = 0; i < n; i++){
        printf("%.3lf ", x[i]);
    }
}

int main(void){
    int lin, col;
    leDimensaoMatriz(&lin, &col);

    double** A = preencheMatrizEscalonada(lin, col);
    double* b = preencheVetorB(lin);
    double* x = resolveSistema(A, lin, b);
    imprimeSolucao(x, lin);

    liberaEstruturas(A, lin, b);
    free(x);

    return 0;
}