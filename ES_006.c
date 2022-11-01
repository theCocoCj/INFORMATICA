#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LUNG_MAX 100


bool isVocale(char c){
    bool vocale;
    if(c =='a'||c=='e'||c=='i'||c=='o'||c=='u') {
        vocale = true;
    } else {
        vocale = false;
    }
    return vocale;
}

void eliminaVocali(char sIn[]){
    char sOut[LUNG_MAX];
    int j=0;
    for(int k=0; sIn[k]!='\0'; k++){
        if(isVocale(sIn[k])==false){
            sOut[j]=sIn[k];
            j++;
        }
    }
    sOut[j]='\0';
    strcpy(sIn, sOut);
}

int main() {
    char sIn[LUNG_MAX];
    printf("Inserisci la parola:");
    fflush(stdin);
    gets(sIn);
    eliminaVocali(sIn);
    printf("%s", sIn);
}

