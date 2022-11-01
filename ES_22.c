#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NMAX 20

void leggiFile(float vett[], int n) {
    FILE *fp;

    fp = fopen("numeri.dat", "r");
    if (fp == NULL) {
        printf("Il file non esiste!\n");
    } else {
        for(int k=0; k<n; k++) {
            fscanf(fp, "%f ", &vett[k]);
        }

    }
    fclose(fp);

}

void stampaDat(float vett[], int n) {
    for(int k=0; k<n; k++) {
        printf("%.2f ", vett[k]);
    }
}

void salvaValMedio(float vett[], int n) {
    FILE *fp;

    fp=fopen("risultati.dat", "w");
    float somma, ValMedio=0;
    if( fp==NULL ) {
        printf("Il file non e' stato aperto correttamente!");
    } else {
        for(int k=0;k<n;k++){
            somma+=vett[k];
        }
        ValMedio=somma/NMAX;
        fprintf(fp,"%.2f\n",ValMedio);
    }

}

int main() {
    float vett[NMAX];

    leggiFile(vett, NMAX);
    stampaDat(vett, NMAX);
    salvaValMedio(vett, NMAX);
}
