#include <stdio.h>
#include <stdlib.h>

int main(void){
    int lin, col;
    leDimensaoMatriz(&lin, &col);

    double** A = preencheMatrizCompleta(lin, col);
    double* b = preencheVetorB(lin);
    A = preencheMatrizAmpliada(A, b, lin, col);

    A = eliminacaoGaussiana(A, lin, col);
    imprimeMatrizGaussiana(A, lin, col);

    liberaEstruturas(A, lin, b);
    return 0;
}