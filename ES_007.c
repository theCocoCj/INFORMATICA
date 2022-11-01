#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int leggiDati() {
    float dato;
    scanf("%f", &dato);
    printf("\n");
    return dato;
}

void POT2(float *n){
    *n= *n * *n;
}

int main() {
    float x;
    printf("Inserisci il valore da elevare:");
    x=leggiDati();
    POT2(&x);
    printf("%f", x);
}
