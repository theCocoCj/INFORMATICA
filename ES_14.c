#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RMAX 6
#define CMAX 5
#define LUNG 20

int caricaMatrice(int mat[][CMAX], int riga, int colo) {
    char nomeFile[LUNG];
    int x;
    int r=0;

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);

    FILE *fp = fopen(nomeFile, "r");

    if(fp != NULL) {
        while(r<riga && fscanf(fp,"%d", &x)!=EOF) {
            mat[r][0] = x;
            for(int c=1; c < colo; c++) {
                fscanf(fp,"%d",&x);
                mat[r][c] = x;
            }
        r++;
        }
    } else {
        printf("Il file non esiste");
    }
    return r;
}

void visualizzaMatrice(int mat[][CMAX], int riga, int colo) {
    for(int r=0; r<riga; r++) {
        for(int c=0; c < colo; c++) {
            printf("%3d",mat[r][c]);
        }
        printf("\n");
    }
}

int controllaSimmetria(int mat[][CMAX], int riga, int colo) {
    int c=0;
    int r=0;
    int contSimm=0;
    while(r<riga) {
        while(c<colo/2) {
            if(mat[r][c]==mat[r][colo-c-1]) {
                contSimm++;
            }
            r++;
        }
        c++;
    }
    return contSimm;
}

int main() {
    int matrice[RMAX][CMAX];
    int nr=caricaMatrice(matrice, RMAX, CMAX);
    visualizzaMatrice(matrice, nr, CMAX);
    printf("%d",controllaSimmetria(matrice, nr, CMAX));
}

