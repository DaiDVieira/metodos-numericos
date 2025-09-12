#include <stdio.h>
#include <stdlib.h>

void leDimensaoMatriz(int* lin, int* col){
    printf("Digite a dimensao da matriz A.\nLinhas: ");
    scanf(" %d", lin);
    printf("Colunas: ");
    scanf(" %d", col);
}

double** alocaMatriz(int lin, int col){
    double** m = (double**) malloc(lin * sizeof(double*));
    if(m != NULL){
        for(int i = 0; i < lin; i++){
            m[i] = (double*) malloc(col * sizeof(double));
            if(m[i] == NULL){
                printf("Erro ao alocar linha %d da matriz.\n", i);
                exit(1);
            }
        }
        return m;
    }
    printf("Erro ao alocar matriz.\n");
    exit(1);
}

double** inicializaMatrizComZero(double** m, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            m[i][j] = 0;
        }
    }
    return m;
}

double* alocaVetor(int n){
    return (double*) malloc(n * sizeof(double));
}

double** preencheMatrizEscalonada(int lin, int col){
    double** A = alocaMatriz(lin, col);
    A = inicializaMatrizComZero(A, lin, col);
    printf("\nDigite os valores das linhas da matriz A (zeros abaixo da diagonal principal nao sao necessarios):\n");
    for(int i = 0; i < lin; i++){
        printf("Linha %d:\n", i+1);
        for(int j = i; j < col; j++){
            printf("A[%d][%d]: ", i+1, j+1);
            scanf(" %lf", &A[i][j]);
        }
    }
    return A;
}

double* preencheVetorB(int lin, double* b){
    printf("\nDigite os valores do vetor b\n");
    for(int i = 0; i < lin; i++){
        printf("b%d: ", i+1);
        scanf(" %lf", &b[i]);
    }
    return b;
}

void liberaMatriz(double** A, int lin){
    for(int i = 0; i < lin; i++){
        free(A[i]);
    }
    free(A);
}

//Eliminação Gaussina

double** preencheMatrizA(double** A, int lin, int col){
    printf("\nDigite os valores das linhas da matriz A:\n");
    for(int i = 0; i < lin; i++){
        printf("Linha %d:\n", i+1);
        for(int j = 0; j < col-1; j++){
            printf("A[%d][%d]: ", i+1, j+1);
            scanf(" %lf", &A[i][j]);
        }
        printf("\n");
    }
    return A;
}

double** preencheMatrizAmpliada(double** A, int lin, int col){
    A = preencheMatrizA(A, lin, col);
    printf("\nDigite os valores do vetor b\n");
    for(int i = 0; i < lin; i++){
        printf("b%d: ", i+1);
        scanf(" %lf", &A[i][col-1]);
    }
    return A;
}

void imprimeMatrizGaussiana(double** A, int lin, int col){
    printf("Matriz A escalonada e vetor b usando o metodo da Eliminacao Gaussiana:\n");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(j == col - 1)
                printf(" | ");
            printf("%.8lf ", A[i][j]);
        }
        printf("\n");
    }
}