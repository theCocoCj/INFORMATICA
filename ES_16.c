#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define NR 2
#define NC 3

void min_max_medio(int mat[][NC], int nr, int nc, int *min, int *max, float *medio){

    *min = mat[0][0];
    *max = mat[0][0];

    int tot = 0;

    for (int r=0; r<nr; r++){
        for (int c=0; c<nc; c++){
            if(mat[r][c]<*min)
                *min = mat[r][c];
            if(mat[r][c]>*max)
                *max = mat[r][c];
            tot += mat[r][c];
        }
    }

    *medio = (float) tot / (nr*nc);
}

int main(){
    int data[NR][NC];

    int min,ind=0,c=0,nc=0;
    int max;
    float medio;
        FILE *fp;
    fp=fopen("matrice.txt","r");
    if(fp!=NULL) {
        ind = 0;
        while(ind < NR && fscanf(fp,"%d",&data[ind][0])!=EOF) {
            c = 1;
            while(c<NC && fscanf(fp,"%d",&data[ind][c])!=EOF ) {
                c++;
            }
            nc = c;
            ind++;

        }

    min_max_medio(data,ind,nc,&min,&max,&medio);

    printf("Il valore minimo e'%d, quello massimo e' %d, la media e' %.2f", min, max, medio);
}
}
