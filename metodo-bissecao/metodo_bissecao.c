#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct intervalo{
    int n;
    double an;
    double bn;
    double fan;
    double fbn;
    double pm;
    double fpm;
    double modfpm;
    double ba;
};
typedef struct intervalo I;

double f(double x){
    double y = pow(x, 2) - 2;
    return y;
}

int bolzano(double a, double b){
    double fa = f(a);
    double fb = f(b);

    double mul = f(a)*f(b);
    if (mul < 0){
        printf("Existe raiz de f no intervalo dado.\n");
        return 1;
    }
    else if (mul == 0)
        printf("a ou b sao raizes de f.");
    else
        printf("Nao eh possivel dizer se ha raiz no intervalo dado. Tente novamente.\n");
    return 0;
}

void bisessao(I* i, double e, FILE* a){
    i->fan = f(i->an);
    i->fbn = f(i->bn);
    int n = 0;
    while(fabs((i->bn) - (i->an)) > e){
        i->pm = (i->bn + i->an)/2;
        i->fpm = f(i->pm);
        fprintf(a,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", n, i->an, i->bn, i->fan, i->fbn, i->pm, i->fpm, fabs(i->pm),i->bn - i->an);
        if(fabs(i->fpm) < e){
            printf("Ponto medio %lf eh solucao\n", i->pm);
            break;
        }
        if(i->fan * i->fpm < 0){
            i->bn = i->pm;
            i->fbn = i->fpm;
        }
        else{
            i->an = i->pm;
            i->fan = i->fpm;
        }
        n++;
    }
    printf("O ponto medio %lf eh solucao %lf\n", i->pm, i->fpm);
}

int main(void){
    FILE* arquivo;
    arquivo = fopen("dados.csv", "w");
    fprintf(arquivo, "n,an,bn,f(an),f(bn),pm,f(pm),mod(f(pm)),b-a\n");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    I* intervalo = (I*)malloc(sizeof(I));
    int ret;
    double e;
    do{
        printf("Digite a precissao desejada: ");
        scanf(" %lf", &e);
        printf("Digite um intervalo de numeros inteiros (ex.: [0;2] digite 0 2): ");
        scanf(" %lf %lf", &(intervalo->an), &(intervalo->bn));
        ret = bolzano(intervalo->an, intervalo->bn);
    }while(ret != 1);
    bisessao(intervalo, e, arquivo);    

    fclose(arquivo);
    printf("Dados gravados com sucesso em dados.csv\n");
    free(intervalo);

    return 0;
}