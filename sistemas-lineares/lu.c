#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void imprimeMatrizesLU(double** A, int lin, int col){
    printf("A fatoracao LU gerou as matrizes:\nL:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(i == j)
                printf("1.0000 ");
            else if(j > i)
                printf("0.0000 ");
            else
                printf("%.4lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("U:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(j >= i)
                printf("%.4lf ", A[i][j]);
            else
                printf("0.0000 ");
        }
        printf("\n");
    }
}

double** metodoDeGaussLU(double** A, int lin, int col){
    double m;
    for(int  j = 0; j < lin-1; j++){
        for(int  i = j+1; i < lin; i++){
            m = A[i][j]/A[j][j]; //calcula multiplicador
            for(int k = j; k < col; k++){
                A[i][k] = A[i][k] - (m * A[j][k]); 
                A[i][j] = m; //guarda multiplicador em A
            }
        }
    }
    return A;
}

int main(void){
    int lin, col;
    leDimensaoMatriz(&lin, &col);

    double** A = alocaMatriz(lin, col);
    A = preencheMatrizA(A, lin, col);
    double* b = alocaVetor(lin);
    b = preencheVetor(lin, b, "b");

    A = metodoDeGaussLU(A, lin, col);
    imprimeMatrizesLU(A, lin, col);

    liberaMatriz(A, lin);
    free(b);
    return 0;
}