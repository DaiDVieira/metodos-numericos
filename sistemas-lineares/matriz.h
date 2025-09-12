#ifndef MATRIZ_H
#define MATRIZ_H

void leDimensaoMatriz(int* lin, int* col);
double** alocaMatriz(int lin, int col);
double** inicializaMatrizComZero(double** m, int lin, int col);
double* alocaVetor(int n);
double** preencheMatrizEscalonada(int lin, int col);
double* preencheVetor(int lin, double* v, char c);
double* inicializaVetorComZero(int lin, double* v);
void liberaMatriz(double** A, int lin);
double** preencheMatrizA(double** A, int lin, int col);

#endif