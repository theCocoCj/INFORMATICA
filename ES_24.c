#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NPAROLE 100
#define LUNG 20
#define NCAR 24

bool isCarattere(char arr[], char c) {
    bool ret = false;
    int k = 0;
    while(ret == false && k < NCAR)
        if(arr[k] == c)
            return true;
        else
            k ++;

    return false;
}

void stampaParole(char vett[][LUNG], int lung, int nparole){
    for(int k=0; k<nparole; k++){
        printf("%d parola:%s", k+1,vett[k][lung]);
    }
}

int main() {
    char vettPar[NPAROLE][LUNG + 1];
    int k = 0, cc = 0;
    char c;
    char carSpec[] = {',', ' ', '(', ')','.', ':', ';', '!','?', '\'', '\"', '[',']', '\n', '{', '}','<', '>', '=', '+','-', '*', '/', '_'};

    FILE* fp = fopen("file.txt", "r");

    if(fp == NULL) {
        printf("il file non esiste\n");
        fclose(fp);
        return 0;
    }

    bool ok = true;

    while(cc < NPAROLE && fscanf(fp, "%c", &c) != EOF) {
        if(isCarattere(carSpec, c)&& ok == false) {
            vettPar[k++][cc] = '\0';
            cc = 0;
            ok = true;
        } else if(cc < LUNG){
            vettPar[k][cc++] = c;
            ok = false;
        }else{
            vettPar[k][LUNG] = '\0';
            ok = true;
        }

    printf("le parole sono %d\n", k);

    stampaParole(vettPar, LUNG, NPAROLE);

        if(ok == true)
        k ++;

    for(int i = 0; i < k; i ++) {
        vettPar[k][0] = vettPar[i][0] - 'a' + 'A';
        printf("%s ", vettPar[i]);
    }

    fclose(fp);

    return 0;
    }
}

/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NCARMAX 18
#define NPAR 100
#define LUNG 20

bool isCarattere(char carattere,char vettCar[], int dim){
    for(int k=0; k<dim; k++){
        if(carattere==vettCar[k]){
            return true;
        }
    }
    return false;
}

void leggiFile(char vett[], int n, char vettChar[]) {
    FILE *fp;

    char c;
    fp = fopen("numeri.dat", "r");
    if (fp == NULL) {
        printf("Il file non esiste!\n");
    } else {
        for(int k=0; k<n; k++) {
            fscanf(fp, "%c ", &c);
            if(isCarattere(c,vettChar, n)==false){
                vett[]
            }else{

            }
        }

    }
    fclose(fp);

}

int main() {
    char parola[NPAR][LUNG];
    char vettChar[]={',',';','.',':','-','_','[',']','+','*','#','^','?','!','"','|','/',' ', '\n'};
    leggiFile(vettChar, NCARMAX);
}
*/
