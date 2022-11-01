#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int leggiDati() {
    float dato;
    scanf("%f", &dato);
    printf("\n");
    return dato;
}

void caricaVett(int v[], int dim) {
    for(int k= 0; k< dim; k++) {

        printf("inserisci l'elemento [%d]: ", k);

        scanf("%d", &v[k]);
    }

}

void visualizzaVett(int v[], int dim) {

    for(int k= 0; k< dim; k++) {

        printf("%d\t", v[k]);
    }
}

void calcola(int vett[], int dim,int *pari,int *dispari){
    *dispari=0;
    *pari=0;
    for(int k=0; k<dim; k++){
        if(k%2==0){
            *pari=*pari+vett[k];
        }else{
            *dispari=*dispari+vett[k];
        }
    }
}

int main() {
    int x;
    int vett[NMAX];
    int pari, dispari;
    caricaVett(vett, NMAX);
    visualizzaVett(vett,NMAX);
    calcola(vett, NMAX, &pari, &dispari);
    printf("PARI=%d\t DISPARI=%d", pari, dispari);

}

