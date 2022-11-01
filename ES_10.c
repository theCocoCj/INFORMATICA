#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RMAX 5
#define CMAX 6
#define LUNG 20

void caricaMatVett(int mat[RMAX][CMAX], int righe, int colonna, int vett[]) {
    int c, r, x, sommaColonna;
    char nomeFile[LUNG];

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);

    FILE *fp = fopen(nomeFile, "r");

    if(fp != NULL) {
        for(c=0; c<colonna; c++) {
            sommaColonna=0;
            for(r=0; r < righe; r++) {
                fscanf(fp,"%d",&x);
                mat[r][c] = x;
                sommaColonna=sommaColonna+mat[r][c];
            }
            printf("La somma totale della colonna %d e': %d\n",c, sommaColonna);
            vett[c]=sommaColonna;
        }
    } else {
        printf("Il file non esiste");
    }

}
void visualizzaMatrice(int mat[RMAX][CMAX], int righe, int colonna) {
    for(int r=0; r<righe; r++) {
        for(int c=0; c < colonna; c++) {
            printf("%6d",mat[r][c]);
        }
        printf("\n");
    }
}

void visualizzaVettore(int vett[], int colonna) {
    for(int k=0; k<colonna; k++) {
        printf("%6d\n", vett[k]);
    }
}

int main() {
    int matrice[RMAX][CMAX];
    int vettSomma[RMAX];

    caricaMatVett(matrice, RMAX, CMAX, vettSomma);
    printf("\n");
    visualizzaMatrice(matrice, RMAX, CMAX);
    printf("\n");
    visualizzaVettore(vettSomma, CMAX);
}

