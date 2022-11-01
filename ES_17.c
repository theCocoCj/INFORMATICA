#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUNG 20
#define DIM 4

typedef char stringa[LUNG];

typedef struct dati {
    stringa nome;
    int goalFatt;
    int goalSub;
} DatiSquad;

void caricaStruct(DatiSquad campionato[], int n) {
    char nomeFile[LUNG];
    int cont = 0;

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);

    FILE *fp;

    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("Il file non esiste!n");
    } else {
        cont = 0;
        while(cont < n && (fscanf(fp, "%s",campionato[cont].nome)) != EOF) {
            fscanf(fp, "%d %d", &campionato[cont].goalFatt, &campionato[cont].goalSub);
            cont++;
        }
    }
    fclose(fp);
}

void controllaGoal(DatiSquad campionato[], int n) {
    for(int k=0; k<n; k++) {
        if(campionato[k].goalFatt > campionato[k].goalSub) {
            printf("La squadra %s ha fatto piu' goal di quelli subiti\n",campionato[k].nome);
        } else {
            printf("La squadra %s ha fatto meno goal di quelli subiti\n",campionato[k].nome);
        }
    }
}

void stampaStruct(DatiSquad campionato[], int n) {
    for(int k=0; k<n; k++) {
        printf("%s %d %d\n",campionato[k].nome, campionato[k].goalFatt, campionato[k].goalSub);
    }
}

int ricerca(DatiSquad campionato[], int n, stringa nome) {
    bool trovato=false;
    int k=0;
    while(trovato==false && k<n) {
        if(strcmp(nome,campionato[k].nome)==0) {
            trovato=true;
        }else{
        k++;
    }
    }
    return k;
}

void stampaDat(DatiSquad campionato[], int posi) {
    if(posi==true) {
        printf("%s %d %d\n",campionato[posi].nome, campionato[posi].goalFatt, campionato[posi].goalSub);
    } else {
        printf("La squadra non esiste");
    }
}

int main() {
    DatiSquad campionato[DIM];
    int pos=0;
    stringa nomeRic;

    caricaStruct(campionato, DIM);
    controllaGoal(campionato, DIM);
    printf("\n");
    stampaStruct(campionato, DIM);
    printf("\n");
    printf("Inserisci il nome da ricercare:");
    fflush(stdin);
    scanf("%s",nomeRic);
    pos=ricerca(campionato, DIM, nomeRic);
    stampaDat(campionato,pos);
    printf("\n");
}
