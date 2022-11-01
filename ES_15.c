#include <stdio.h>
#include <stdbool.h>

#define NR 5
#define NC 6
#define LUNG 100

int caricaMatrice(int mat[][NC], int riga, int colo) {
    char nomeFile[LUNG];
    int x;

    printf("Inserisci il nome del file:");
    scanf("%s", nomeFile);

    FILE *fp = fopen(nomeFile, "r");
    int r=0;
    if(fp != NULL) {

        while(r<riga&&fscanf(fp,"%d",&x)!=EOF) {
            mat[r][0] = x;
            for(int c=1; c < colo; c++) {
                fscanf(fp,"%d",&x);
                mat[r][c] = x;
            }
            r++;
        }
    } else {
        printf("Il file non esiste");
    }
    return r;
}

void visualizzaMatrice(int mat[][NC], int riga, int colo) {
    for(int r=0; r<riga; r++) {
        for(int c=0; c < colo; c++) {
            printf("%3d",mat[r][c]);
        }
        printf("\n");
    }
}

int simmetrici(int mat[][NC], int nr, int nc) {
    int r=0;
    int c=0;
    int sim=0;
    while(r<nr) {
        while(c<nc/2) {
            if(mat[r][c]==mat[r][nc-c-1]) {
                sim++;
            }
            c++;
        }
        r++;
    }
    return sim;
}

bool controlla(int nSimm) {
    bool ok=false;
    if(nSimm>0) {
        ok=true;
    }

    return ok;
}

int main() {
    int matrice[NR][NC];
    int simm;
    int nr = caricaMatrice(matrice,NR,NC);
    visualizzaMatrice(matrice,nr,NC);
    simm=simmetrici(matrice,nr,NC);

    if(controlla(simm)==true) {
        printf("Ci sono elementi simmetrici.\n");
        printf("Gli elementi simmetrici sono:%d",simm);

    }

}
