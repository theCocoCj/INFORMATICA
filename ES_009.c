#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int leggiDati() {
    float dato;
    scanf("%f", &dato);
    printf("\n");
    return dato;
}
void INVERTI(int numero) {
    int resto=0,cont=0, invertito=0;
    do {
        if(cont=0) {
            resto=numero%10;
            numero=numero/10;
            invertito=resto;
            cont++;
        } else {

            resto=numero%10;
            numero=numero/10;
            invertito=(invertito*10)+resto;        }
    } while(numero!=0);
    printf("%d", invertito);
}

void INVERTI2(int *num){

}

int main() {
    int numero;
    printf("Inserisci un numero di almeno due cifre:");
    numero=leggiDati();
    INVERTI(numero);

}
