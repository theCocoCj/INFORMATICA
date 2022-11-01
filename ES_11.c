#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RMAX 5
#define CMAX 6
#define LUNG 20

void caricaMatrice(int mat[][CMAX], int dim) {
    int x;
    for(int r=0; r<dim; r++) {
        for(int c=0; c<dim; c++) {
            printf("inserisci il numero nella posizione %d-%d:",r, c);
            scanf("%d", &x);
            mat[r][c]=x;
        }
    }

}

void visualizzaMatrice(int mat[][CMAX], int dim) {
    for(int r=0; r<dim; r++) {
        for(int c=0; c<dim; c++) {
            printf("%3d",mat[r][c]);
        }
        printf("\n");
    }
}

int calcolaPrincipale(int mat[][CMAX], int dim) {
    int somma=0;
    for(int k=0; k<dim; k++) {
        somma += mat[k][k];
    }
    return somma;
}

int calcolaSecondaria(int mat[][CMAX], int dim) {
    int somma=0;
    for(int k=0; k<dim; k++) {
                somma += mat[k][dim-1-k];
    }
    return somma;
}

void stampaSomma(int pri, int sec) {
    printf("DIAGONALE PRINCIPALE:%d\n", pri);
    printf("DIAGONALE SECONDARIA:%d\n", sec);
}


int main() {
    int matrice[RMAX][CMAX], n;
    int principale, secondaria;

    printf("Inserisci la grandezza della matrice:");
    scanf("%d", &n);

    caricaMatrice(matrice,n);
    visualizzaMatrice(matrice,n);
    principale=calcolaPrincipale(matrice,n);
    secondaria=calcolaSecondaria(matrice,n);
    stampaSomma(principale, secondaria);
}

