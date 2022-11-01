#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RMAX 5
#define CMAX 6
#define LUNG 20

void caricaMatrice(int mat[][CMAX], int riga, int colo) {
    char nomeFile[LUNG];
    int x;

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);

    FILE *fp = fopen(nomeFile, "r");

    if(fp != NULL) {
        for(int r=0; r<riga; r++) {
            for(int c=0; c < colo; c++) {
                fscanf(fp,"%d",&x);
                mat[r][c] = x;
            }
        }
    } else {
        printf("Il file non esiste");
    }

}

void visualizzaMatrice(int mat[][CMAX], int riga, int colo) {
    for(int r=0; r<riga; r++) {
        for(int c=0; c < colo; c++) {
            printf("%3d",mat[r][c]);
        }
        printf("\n");
    }
}

void calcolaRiga(int mat[][CMAX],int colonna[], int riga, int colo) {
    int c, r, sommaRiga;

    for(r = 0; r < colo; r++) {
        sommaRiga=0;
        for(c = 0; c < riga; c++) {
            //printf("DEB%d\n", sommaRiga);
            sommaRiga=sommaRiga+mat[c][r];
        }
        colonna[r]=sommaRiga;
    }
}

void visualizzaRiga(int colonna[], int riga) {
    for(int k=0; k<riga; k++) {
        printf("riga[%d]=%d\n",k, colonna[k]);
    }
}

int main() {
    int matrice[RMAX][CMAX];
    int colonna[RMAX];

    caricaMatrice(matrice, RMAX, CMAX);
    visualizzaMatrice(matrice, RMAX, CMAX);
    calcolaRiga(matrice,colonna, RMAX, CMAX);
    printf("\n");
    visualizzaRiga(colonna, RMAX);
}
