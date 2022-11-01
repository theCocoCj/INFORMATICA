#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/* 
25. Sia dato il file GARE.TXT così costituito (da creare e riempire):

mario rossi 25 (minuti impiegati a portare a termine la gara) INVIO
luca verdi 17 INVIO
loris bianchi 32 INVIO
Produrre in output l’atleta (cognome, nome) che ha impiegato meno tempo a portare
a termine la gara.
*/

#define LUNG 20
#define NPERSONE 3

typedef char stringa[LUNG];

typedef struct dati {
    stringa nome[LUNG];
    stringa cognome[LUNG];
    int tempo;
} Concorrente;

//leggo file e carico la struttura 
void leggiFile(Concorrente nPers[], int n) {
    FILE *fp;

    fp = fopen("GARE.txt", "r");
    if (fp == NULL) {
        printf("Il file non esiste!\n");
        //return -1;
    } else {
        int cont=0;
        while(cont < n && fscanf(fp,"%s", nPers[cont].nome)!=EOF){
            fscanf(fp,"%s %d", nPers[cont].cognome, &nPers[cont].tempo);
            cont++;
        }

    }
    //return;
    fclose(fp);
}

int controllaTempo(Concorrente nPers[], int n){
    int k, indice=0;
    int minimo=nPers[0].tempo;
    for(k=1; k<n; k++){
        if(nPers[k].tempo<=minimo){
            minimo=nPers[k].tempo;
            indice = k;
        }
    }
return indice;
}

void stampaVin(Concorrente nPers[],int indice){
    printf("Il vincitore e' %s %s con tempo %d",nPers[indice].nome, nPers[indice].cognome, nPers[indice].tempo);
}

int main() {
    Concorrente nPers[NPERSONE];
    int vinc;

    leggiFile(nPers,NPERSONE);

    for(int k=0;k<NPERSONE;k++){
        printf("%s %s %d\n",nPers[k].nome, nPers[k].cognome, nPers[k].tempo);
    }
    
    vinc=controllaTempo(nPers,NPERSONE);
    stampaVin(nPers,vinc);
    return 0;
}
