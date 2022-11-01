#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NMAX 10
#define MIN 36
#define MAX 126

int leggiDati() {
    float dato;
    scanf("%f", &dato);
    printf("\n");
    return dato;
}

int stringaCas(int vett[],int massimo, int minimo, int dim) {
    srand(time(NULL));
    int xV;//n numeri casuali

    for(int k = 0; k < dim-1; k++) {

        xV = (massimo - minimo) + 1;
        vett[k] = rand () % xV + minimo;
        //printf("%c", vett[k]);
    }
    vett[dim-1]='\0';
}

/*void stampaString(int v[], int dim) {
    for(int k= 0; k< dim; k++) {
        printf("%c", v[k]);
    }
}
*/

int main() {
    int n;

    printf("Inserisci la lunghezza della stringa:");
    n=leggiDati();
    int vett[n];
    stringaCas(vett,MAX,MIN, n);
    //stampaString(vett, n);
    printf("%s", vett);
}
