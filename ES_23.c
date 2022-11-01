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

    fp=fopen("risultati.dat", "a");
    float somma, ValMedio=0;
    if( fp==NULL ) {
        printf("Il file non e' stato aperto correttamente!");
    } else {
        for(int k=0;k<n;k++){
            somma+=vett[k];
        }
        ValMedio=somma/NMAX;
        fprintf(fp,"risultato=%.2f\n",ValMedio);
    }

}

void salvaValMassimo(float vett[], int n) {
    FILE *fp;

    fp=fopen("risultati.dat", "a");
    float somma, ValMedio=0;
    if( fp==NULL ) {
        printf("Il file non e' stato aperto correttamente!");
    } else {
        int massimo=vett[0];
                for(int k=1;k<n;k++){
            if(massimo<=vett[k]){
                massimo=vett[k];
            }
                }
        fprintf(fp,"massimo=%.2f\n",massimo);
    }

}

int main() {
    float vett[NMAX];

    leggiFile(vett, NMAX);
    stampaDat(vett, NMAX);
    salvaValMedio(vett, NMAX);
    salvaValMassimo(vett, NMAX);
}
