#include <stdio.h>
#include <stdlib.h>

void CetakTokenList(){ //mencetak token list
    FILE *fTkn;
    fTkn = fopen("TokenList.csv", "w");
    fprintf(fTkn, " Token ; Simbol/Terminal\n");
    for(int i=0; i<nSimTerm; i++){
        fprintf(fTkn, " %d ; %s \n", arraySimTerm[i].tok, arraySimTerm[i].Aph);
    }
    fclose(fTkn);
}

void CetakCYKTab(){ //mencetak tabel CYK
    FILE *fCYK;
    fCYK = fopen("CYK_Tab.csv", "w");
    for(int i=0; i<nTab; i++){
        int k=0;
        for(int j=nTab-i-1; j<nTab; j++){
            fprintf(fCYK, " %s;", tabCYK[k][j]);
            k++;
        }
        fprintf(fCYK, " * \n");
    }
    /*
    for(int i=0; i<kolIn; i++){
        for(int j=1; j<atoi(parsingIn[i][0]); j++){
            fprintf(fCYK, " %s ;", parsingIn[i][j]);
        }
    }
    fprintf(fCYK, " * \n");
    */
}
