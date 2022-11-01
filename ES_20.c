#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUNG 20
#define NMAX 8

typedef char stringa[LUNG];

typedef struct data {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct dati {
    stringa descrizione;
    int qta;
    Data data;
} DatiAli;

void caricaStruct(DatiAli alimenti[], stringa nomeFile, int dim) {
    int cont=0;
    FILE *fp;

    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("il file non esiste!");
    } else {
        cont = 0;
        while(cont < dim && (fscanf(fp, "%s", alimenti[cont].descrizione)) != EOF) {
            fscanf(fp, " %d %d/%d/%d",&alimenti[cont].qta,&alimenti[cont].data.anno,&alimenti[cont].data.mese,&alimenti[cont].data.giorno);
            cont ++;
        }
    }
    fclose(fp);
}

void stampaStruct(DatiAli alimenti[], int dim) {
    for(int cont=0; cont<dim; cont++) {
        printf("%s %d %d/%d/%d\n",alimenti[cont].descrizione,alimenti[cont].qta,alimenti[cont].data.giorno,alimenti[cont].data.mese,alimenti[cont].data.anno);
    }
}
void controllaScad(DatiAli alimenti[], int giorno, int mese, int anno, int dim) {
    FILE *fp;

    fp=fopen("SCADUTI.DAT", "w");
    if( fp==NULL ) {
        printf("Il file non e' stato aperto correttamente!");
    } else {
        bool scaduto;
        for(int k=0; k<dim; k++) {
            scaduto=false;
            if(alimenti[k].data.anno<=anno) {
                scaduto=true;
            } else if(alimenti[k].data.anno=anno) {
                if(alimenti[k].data.mese<=mese) {
                    scaduto=true;
                } else if(alimenti[k].data.mese<=mese) {
                    if(alimenti[k].data.giorno>giorno) {
                        scaduto=true;

                        //fprintf(fp,"%s %d %d/%d/%d\n",alimenti[k].descrizione,alimenti[k].qta,alimenti[k].data.giorno,alimenti[k].data.mese,alimenti[k].data.anno);
                        //printf("%s scaduto\n",alimenti[k].descrizione );
                    }
                }
            }

        }
    }
    fclose(fp);
}




/*void ordinaAlimenti(DatiAli alimenti[], int n) {
    int k, sup;
    stringa temp;
    int tempN;

    for (sup = n-1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (strcmp(alimenti[k].descrizione,alimenti[k+1].descrizione) < 0){

                temp = alimenti[k].descrizione;

            alimenti[k].descrizione = alimenti[k+1].descrizione;

            alimenti[k+1].descrizione = temp;
        }
    }
}
}
*/
int main() {
    DatiAli alimenti[NMAX];
    stringa nomeFile;
    int anno, mese, giorno;

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);
    printf("\n");
    caricaStruct(alimenti, nomeFile, NMAX);
    stampaStruct(alimenti, NMAX);
    printf("Inserisci la data di oggi nel seguente modo:AAAA/MM/GG\n");
    scanf("%d/%d/%d",&anno,&mese,&giorno);
    controllaScad(alimenti, giorno, mese, anno, NMAX);
    //stampaStruct(alimenti, NMAX);
}


