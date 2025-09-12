#ifndef _MATRIZ_H_
#define _MATRIZ_H_

void leDimensaoMatriz(int* lin, int* col);
double** alocaMatriz(int lin, int col);
double** inicializaMatrizComZero(double** m, int lin, int col);
double* alocaVetor(int n);
double** preencheMatrizEscalonada(int lin, int col);
double* preencheVetorB(int lin, double* b);
void liberaMatriz(double** A, int lin);
double** preencheMatrizA(double** A, int lin, int col);
double** preencheMatrizAmpliada(double** A, int lin, int col);
void imprimeMatrizGaussiana(double** A, int lin, int col);

#endif