#include <stdio.h>
#include <stdbool.h>
#include "matriz.h"

double* defineXInicial(double* x, int lin){
    int resp;
    printf("Escolha uma opção de entrada para o vetor x(0):\n1 - Digitar valores\n2 - Definir como nulo\n=> ");
    scanf(" %d", &resp);
    switch (resp)
    {
    case 1: x = preencheVetor(lin, x, "x");
        break;
    case 2: x = inicializaVetorComZero(lin, x);
        break;
    default: printf("Opcao invalida. Operacao cancelada.\n");
        exit(1);
        break;
    }
}

bool testeConvergencia(double** A, int lin, int col){
    bool teste;
    double* norma = alocaVetor(lin);
    norma = inicializaVetorComZero(lin, norma);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            norma[i] += A[i][j];
        }
    }
}

int main(void){
    int lin, col, NMAX;
    leDimensaoMatriz(&lin, &col);

    double** A = alocaMatriz(lin, col);
    A = preencheMatrizA(A, lin, col);
    double* b = alocaVetor(lin);
    b = preencheVetorB(lin, b);
    double* x = alocaVetor(lin);
    x = defineXInicial(x, lin);
    double e;
    printf("Digite a precisao desejada: ");
    scanf(" %lf", &e);
    printf("Digite o numero maximo de iteracoes: ");
    scanf(" %d", &NMAX);

    //teste de convergencia
    //construir matriz C e vetor g
    //aplicar algoritmo

    liberaMatriz(A, lin);
    free(b);
    return 0;
}