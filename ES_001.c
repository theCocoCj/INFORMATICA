#include <stdio.h>
#include <stdlib.h>

#define NMAX 11

int leggiDati() {
    float dato;
    scanf("%f", &dato);
    printf("\n");
    return dato;
}

void caricaVett(int v[],int x, int dim) {

    for(int k= 0; k< dim; k++) {
            v[k]=x*k;
    }
}

void visualizzaVett(int v[], int dim) {

    for(int k= 0; k< dim; k++) {
        printf("%d\t", v[k]);
    }
}

int main() {
    int x;
    int vett[NMAX];
    printf("Inserisci un numero:");
    x=leggiDati();
    caricaVett(vett, x, NMAX);
    visualizzaVett(vett,NMAX);
}
