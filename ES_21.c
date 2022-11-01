#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NMOSTR 3
#define LUNG 20
typedef char stringa[LUNG];

typedef struct dati {
    stringa nome;
    int vita;
    int forza;
} Mostro;

void setVita(Mostro nMostri[]){
    int vita;
    do{
    printf("Inserisci la vita del mostro:");
    scanf("%d", &vita);
    }while(vita<=5 && vita>=10);
}

void setForza(Mostro nMostri[]){
    int forza;
    do{
    printf("Inserisci la forza del mostro:");
    scanf("%d", &forza);
    }while(forza<=5 && forza>=10);
}

void 

int main() {
    Mostro nMostri[NMOSTR];

}