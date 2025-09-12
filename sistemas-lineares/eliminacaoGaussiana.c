/*
Método da Eliminação Gaussiana para sistemas lineares, por Daiane D. Vieira
Métodos Numéricos Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
Para executar:
    gcc eliminacaoGaussiana.c matriz.c -o s
    ./s
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

double** eliminacaoGaussiana(double** A, int lin, int col){
    double m;
    for(int  j = 0; j < lin-1; j++){
        for(int  i = j+1; i < lin; i++){
            m = A[i][j]/A[j][j]; //calcula multiplicador
            for(int k = j; k < col + 1; k++){
                A[i][k] = A[i][k] - (m * A[j][k]); 
            }
        }
    }
    return A;
}

int main(void){
    int lin, col;
    leDimensaoMatriz(&lin, &col);
    col++; //adiciona coluna do vetor b para matriz ampliada

    double** A = alocaMatriz(lin, col);
    A = preencheMatrizAmpliada(A, lin, col);

    A = eliminacaoGaussiana(A, lin, col);
    imprimeMatrizGaussiana(A, lin, col);

    liberaMatriz(A, lin);

    return 0;
}