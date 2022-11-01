#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RMAX 11
#define CMAX 11

void tavolaPer(int mat[][CMAX], int riga, int colonna) {
    int cont1, cont, risultato;
    cont=0;
    while (cont<=riga) {
        cont1=0;
        while (cont1<=colonna) {
            mat[cont][cont1]=cont*cont1;
            cont1 ++;
        }
        cont=cont+1;
    }
}

void stampaMat(int mat[][CMAX], int riga, int colonna){
    for(int k=0;k<riga;k++){
        for(int j=0;j<colonna;j++){
            printf("%4d", mat[k][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[RMAX][CMAX];
    tavolaPer(mat, RMAX, CMAX);
    printf("TAVOLA PERIODICA:\n");
    stampaMat(mat, RMAX,CMAX);
}

