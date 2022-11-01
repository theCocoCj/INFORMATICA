#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

void scambioInt(float *x, float *y) {

    float temp = *y;

    *y = *x;

    *x = temp;
}

int trovaMin(float v[], int dim) {
    int min=v[0];
    for(int k=1; k<dim; k++) {
        if(min>v[k]) {
            min=v[k];
        }
    }
    return min;
}

int trovaMax(float v[], int dim) {
    int max=v[0];
    for(int k=1; k<dim; k++) {
        if(max>v[k]) {
            max=v[k];
        }
    }
    return max;
}
void caricaVettFloat(float v[], int dim) {

    for(int k= 0; k< dim; k++) {

        printf("inserisci l'elemento [%d]: ", k);

        scanf("%.3f", &v[k]);
    }
}

void bubbleSort1Decrescente(float vett[], int n) {

    int k, sup, contConfronti=0, contScambio=0;

    for (sup = n-1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (vett[k] < vett[k+1])
                scambioInt(&vett[k], &vett[k+1]);
        }
    }
}

void controlla(float vett[], float Min, float Max, int dim) {
    if(Min==vett[dim]) {
        if(Max==vett[0] && Min==vett[dim-1]) {
            printf("Corretto");
        } else {
            printf("sbagliato");
        }
    }
}

int main() {
    float vett[NMAX];
    float Min, Max;
    caricaVettFloat(vett, NMAX);
    Min=trovaMin(vett, NMAX);
    Max=trovaMax(vett, NMAX);
    printf("MIN=%f\n", Min);
    printf("MAX=%f\n", Max);
    bubbleSort1Decrescente(vett, NMAX);
    controlla(vett,Min, Max, NMAX);

}
