/*
Método da Eliminação Gaussiana para sistemas lineares, por Daiane D. Vieira
Métodos Numéricos Computacionais - MTM224
Ciência da Computação, Universidade Federal de Santa Maria (UFSM)
Santa Maria, 2025
Para executar:
    gcc gauss.c matriz.c -o s
    ./s
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

double** eliminacaoGaussiana(double** A, int lin, int col){
    double m;
    for(int  j = 0; j < lin-1; j++){
        for(int  i = j+1; i < lin; i++){
            m = A[i][j]/A[j][j]; //calcula multiplicador
            for(int k = j; k < col; k++){
                A[i][k] = A[i][k] - (m * A[j][k]); 
            }
        }
    }
    return A;
}

double** preencheMatrizAmpliada(double** A, int lin, int col){
    A = preencheMatrizA(A, lin, col-1);
    printf("\nDigite os valores do vetor b\n");
    for(int i = 0; i < lin; i++){
        printf("b%d: ", i+1);
        scanf(" %lf", &A[i][col-1]);
    }
    return A;
}

void imprimeMatrizGaussiana(double** A, int lin, int col){
    printf("\nMatriz A escalonada e vetor b usando o metodo da Eliminacao Gaussiana:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(fabs(A[i][j]) < 1e-15) 
                A[i][j] = 0.0;
            if(j == col - 1)
                printf(" | ");
            printf("%.15lf ", A[i][j]);
        }
        printf("\n");
    }
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