#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "boolean.h"

void combine(char a[STR_SIZE], char b[STR_SIZE], int *c){
    int nA=0, nB=0;
	char tmp[MX_SIZE], sA[MX_SIZE], sB[MX_SIZE];
	char tA[MX_SIZE][STR_SIZE], tB[MX_SIZE][STR_SIZE], *token;

    strcpy(sA,a);
    strcpy(sB,b);

    token = strtok(sA," ");
    while (token!=NULL){
        strcpy(tA[nA],token);
        nA++;
        token = strtok(NULL, " ");
    }
    token = strtok(sB," ");
    while (token!=NULL){
        strcpy(tB[nB],token);
        nB++;
        token = strtok(NULL, " ");
    }
    if(nA>0 && nB>0){
        for(int i=0; i<nA; i++){
            for(int j=0; j<nB; j++){
                strcpy(tmp, "");
				sprintf(tmp, "%s %s ", tA[i], tB[j]);
				strcpy(row[*c], tmp);
				(*c)++;
            }
        }
    }
    else if (nB == 0) {
		for(int i=0; i<nA; i++) {
			strcpy(tmp, "");
			sprintf(tmp, "%s ", tA[i]);
			strcpy(row[*c], tmp);
			(*c)++;
		}
	}
    else if (nA == 0) {
		for (int i=0; i<nB; i++) {
			strcpy(tmp, "");
			sprintf(tmp, "%s ", tB[i]);
			strcpy(row[*c], tmp);
			(*c)++;
		}
	}
}

void MakeCYK(){
    char temp[STR_SIZE], cpy[STR_SIZE];
    nTab=0;
    for(int i=0; i<kolIn; i++){
        for(int j=1; j<tokenIn[i][0]; j++){
            strcpy(cpy, "");
            for(int k=0; k<nSimTerm; k++){
                sprintf(temp, "%d ", tokenIn[i][j]);
                for(int l=2; l<atoi(grammar[k][0]); l++){
                    if(strcmp(temp, grammar[k][l])==0){
                        strcat(cpy, grammar[k][1]);
                        strcat(cpy, " ");
                    }
                }
            }
            strcpy(tabCYK[nTab][nTab], cpy);
            nTab++;
        }
    }
    for(int i=1; i<nTab; i++){
        char a[STR_SIZE], b[STR_SIZE], jwbn[MX_SIZE];
        int count;
        strcpy(temp, "");
        memset(row, 0, sizeof row);
        for(int j=i; j<nTab; j++){
            count=0;
            for(int k=j-i; k<j; k++){
                strcpy(jwbn, "");
                strcpy(a, tabCYK[j-i][k]);
                strcpy(b, tabCYK[k+1][j]);
                combine(a,b,&count);
            }
            strcpy(jwbn, "");
            for(int k=0; k<nSimTerm; k++){
                for(int l=2; l<atoi(grammar[k][0]); l++){
                    for(int m=0; m<count; m++){
                         if(strcmp(row[m], grammar[k][l])==0){
                             boolean isExist=false;
                             char exist[100], ans[2];
                             strcpy(exist, "");
                             for(int n=0; n<strlen(jwbn); n++){
                                 if(jwbn[n] != ' '){
                                     sprintf(ans, "%c", jwbn[n]);
                                     strcat(exist, ans);
                                 }
                                 else{
                                     if(strcmp(exist, grammar[k][1])==0) isExist=true;
                                     strcpy(exist, "");
                                 }
                            }
                            if(!isExist){
                                strcat(jwbn, grammar[k][1]);
                                strcat(jwbn, " ");
                            }
                         }
                    }
                }
            }
            strcpy(tabCYK[j-i][j], jwbn);
        }
    }
}