#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LUNG 20
#define NPROVE 10

typedef char stringa[LUNG];

typedef struct dati {
    stringa nome;
    int punteggi[NPROVE];
    int totale;
} Concorrente;

void leggiDati(Concorrente vettProve[],char nomeFile[], int n) {
    int cont = 0;
    FILE *fp;

    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("il file non esiste!n");
    } else {
        cont = 0;
        while(cont < n && (fscanf(fp, "%s ",vettProve[cont].nome)) != EOF) {
            vettProve[cont].totale=0;
            for(int k=0; k<n ; k++) {
                fscanf(fp, " %d", &vettProve[cont].punteggi[k]);
                vettProve[cont].totale+=vettProve[cont].punteggi[k];
            }
            cont++;
        }
    }
    fclose(fp);
}

void leggiVin(Concorrente vettProve[], int n) {
    int vinc=vettProve[0].punteggi[0];
    for(int k=1; k < n ; k++) {
        for(int c=1; c < n-1; c++) {
            if(vettProve[c].punteggi[k]>=vinc) {
                vinc=c;
            }
        }
        printf("prova %d: %s %d\n",k+1,vettProve[vinc].nome,vettProve[vinc].punteggi[vinc]);
    }
}

void stampaDat(Concorrente vettProve[], int n) {
    for(int c=0; c<n; c++) {
        printf("%s ",vettProve[c].nome);
        for(int k=0; k<n; k++) {
            printf("%d ",vettProve[c].punteggi[k]);
        }
        printf("\n");
    }
}

void stampaTot(Concorrente vettProve[], int n) {
    for(int c=0; c<n; c++) {
        printf("Il totale dei punti di %s e' %d ",vettProve[c].nome,vettProve[c].totale);
        printf("\n");
    }
}


int main() {
    stringa nomeFile;
    Concorrente vettProve[NPROVE];

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);

    leggiDati(vettProve, nomeFile, NPROVE);
    stampaDat(vettProve, NPROVE);
    printf("\n");
    stampaTot(vettProve, NPROVE);
    printf("\n");
    leggiVin(vettProve, NPROVE);
}
