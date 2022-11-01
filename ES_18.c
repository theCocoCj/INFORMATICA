#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUNG 20
#define DIM 10
#define NMAX 7

typedef char stringa[LUNG];

typedef struct dati {
    stringa nome;
    float valori[NMAX];
} DatiBors;

int caricaStruct(DatiBors borse[], int n, int dim2) {
    char nomeFile[LUNG];
    int cont = 0;

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);
    printf("\n");

    FILE *fp;

    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("Il file non esiste!n");
    } else {
        cont = 0;
        while(cont < n && (fscanf(fp, "%s ",borse[cont].nome)) != EOF) {
            for(int k=0; k<dim2; k++) {
                fscanf(fp, "%f ", &borse[cont].valori[k]);
            }
            cont++;
        }
    }
    fclose(fp);
    return cont;
}

void stampaDat(DatiBors borse[], int n, int dim2) {
    for(int c=0; c<n; c++) {
        printf("%s ",borse[c].nome);
        for(int k=0; k<dim2; k++) {
            printf("%.2f ",borse[c].valori[k]);
        }
        printf("\n");
    }
}

int verificaCalo(DatiBors borse[], int n, int dim2) {
    int cont=0;
    for(int c=0; c<n; c++) {
        for(int k=1; k<dim2-1; k++) {
            if(((borse[c].valori[k]-borse[c].valori[k+1])/borse[c].valori[k])*100 >= 10) {
                cont++;
                printf("Calo del %.2f PERCENTO per le azioni di: %s \n",((borse[c].valori[k+1]-borse[c].valori[k])/borse[c].valori[k])*100, borse[c].nome);
                //printf("%d", cont);
            }
            //printf("%d", cont);
        }
    }
    return cont;
}

int main() {
    DatiBors borse[DIM];
    stringa nomeRic;

    int nAzioni=0, contCali;


    nAzioni = caricaStruct(borse, DIM, NMAX);
    stampaDat(borse, nAzioni, NMAX);
    printf("\n");
    contCali=verificaCalo(borse, nAzioni, NMAX);
    printf("Le azioni che hanno avuto un calo superiore al 10 PERCENTO sono:%d\n", contCali);

}

