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

void calcola(int vett[],int vettP[], int vettD[], int dim, int *kp, int *kd) {
    *kd=0, *kp=0;
    for(int k=0; k<dim; k++) {
        if(k%2==0) {
            if(vett[k]%2!=0) {
                vettD[*kd]=vett[k];
                *kd+=1;
            }
        } else {
            if(vett[k]%2==0) {
                vettP[*kp]=vett[k];
                *kp+=1;
            }
        }
    }
}

int main() {
    int x;
    int vett[]= {1,2,3,4,5,6,7,8,9,10};
    int vettP[NMAX], vettD[NMAX];
    int kp,kd;
    //caricaVett(vett, NMAX);
    visualizzaVett(vett,NMAX);
    printf("\n");
    calcola(vett, vettP, vettD, NMAX, &kp, &kd);
    printf("PARI IN DISPARI:\n");
    visualizzaVett(vettP,kp);
    printf("\n");
    printf("DISPARI IN PARI:\n");

    visualizzaVett(vettD,kd);

}
