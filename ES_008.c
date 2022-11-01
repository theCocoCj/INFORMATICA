#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LUNG_MAX 100


bool isVocale(char c) {
    bool vocale;
    if(c =='a'||c=='e'||c=='i'||c=='o'||c=='u') {
        vocale = true;
    } else {
        vocale = false;
    }
    return vocale;
}

bool VocaliDispari(char str[]) {
    int j=0;
    bool dispari=false;
    for(int k=0; str[k]!='\0'; k++) {
        if(isVocale(str[k])==true) {
            j++;
        }
    }
    if(j%2 != 0){
        dispari=true;
    }else{
        dispari=false;
    }
    return dispari;
}

int main() {
    char sIn[LUNG_MAX];
    printf("Inserisci la parola:");
    fflush(stdin);
    gets(sIn);
    if(VocaliDispari(sIn)==true) {
        printf("Il numero delle vocali presenti nella stringa e' dispari");
    } else {
        printf("Il numero delle vocali presenti nella stringa NON e' dispari");
    }
}
