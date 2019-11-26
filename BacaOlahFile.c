#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "boolean.h"

int TknCek(char str[STR_SIZE]){ //Mengembalikan token dari str[] yang ada di arraySimTerm. 
//Jika tidak ada, maka mengembalikan -1

    int i=0;
    boolean temp=false;
    while(i<nSimTerm && !temp){
        if(strcmp(arraySimTerm[i].Aph, str) == 0) temp=true;
        else i++;
    }
    if(temp) return arraySimTerm[i].tok;
    else return -1;
}

void ParsInput(char z[STR_SIZE], int brs){ //memisah string panjang menjadi array of token
    char *tkn, simbol[1], str[STR_SIZE];

    tkn = strtok(z, " ");
    memset(parsingIn, 0, sizeof parsingIn); //set array agar kosong
    
    int idx=1;
    while(tkn!=NULL){
        strcpy(str, "");
        for(int i=0; i<strlen(tkn); i++){
            simbol[0]=tkn[i];
            if(!isalpha(tkn[i]) && !isdigit(tkn[i])){ //cek tkn[x] adalah sebuah simbol non numeric dan alfabet
                if(TknCek(simbol) == -1){
                    strcpy(parsingIn[brs][idx], "NotFound");
                    tokenIn[brs][idx] = -999; 
                }
                else{
                    strcpy(parsingIn[brs][idx], simbol);
                    tokenIn[brs][idx] = TknCek(simbol);
                }
                idx++;
            }
            else{
                strcat(str, simbol);
                //eksekusi jika di array setelahnya bkn numeric atau alfabet
                if(!isalpha(tkn[i+1]) && !isdigit(tkn[i+1])){
                    boolean isNum=true;
                    int x=0;
                    //cek apakah string number atau tidak
                    while(isNum && x<strlen(str)){
                        if(!isdigit(str[x])) isNum=false;
                        else x++;
                    }
                    if(isNum){ //string numeric
                        strcpy(parsingIn[brs][idx], "constant");
                        tokenIn[brs][idx] = TknCek("constant"); 
                    }
                    else{
                        if(TknCek(str) == -1){ //string kata
                            strcpy(parsingIn[brs][idx], "KATA");
                            tokenIn[brs][idx] = TknCek("KATA"); 
                        }
                        else{ //string key  
                            strcpy(parsingIn[brs][idx], str);
                            tokenIn[brs][idx] = TknCek(str);
                        }
                    }
                    idx++;
                }
            }
        }
        tkn=strtok(NULL, " ");
    }
    sprintf(parsingIn[brs][0], "%d", idx);
    tokenIn[brs][0]=idx; //jumlah kolom pd brs tsb
}

void CNFPars(char z[STR_SIZE], int brs){
    char *tkn, str[STR_SIZE], temp[STR_SIZE];

    tkn=strtok(z, " ");
    sprintf(grammar[brs][1], "%d", TknCek(tkn));
    tkn=strtok(NULL, " ");

    int idx=2;
    strcpy(str, "");
    while(tkn!=NULL){
        if(strcmp(tkn, "->") != 0){
            if(strcmp(tkn, "|") == 0){
                strcpy(grammar[brs][idx], str);
                strcpy(str, "");
                idx++;
            }
            else{
                sprintf(temp, "%d ", TknCek(tkn));
                strcat(str, temp);
            }
        }
        tkn=strtok(NULL, " ");
    }
    sprintf(grammar[brs][0], "%d", idx);
}

void BacaInputFile(){ //Membaca file yang akan di compile
    kolIn=0;
    char temp[STR_SIZE];
    char namaFile[100];
    printf("File yang akan di-compile :\n");
    gets(namaFile);
    FILE *fileIn = fopen(namaFile,"r");
    while(!feof(fileIn)){
        fgets(temp, STR_SIZE, fileIn);
        strtok(temp, "\n");
        ParsInput(temp, kolIn);
        kolIn++;
    }
    fclose(fileIn);
}

void BacaSimTermFile(){ //Membaca file simbol dan terminal
    int i=0;
    FILE *fileST = fopen("SimbolTerm.txt","r");
    while(!feof(fileST)){
        fgets(arraySimTerm[i].Aph, STR_SIZE, fileST);
        strtok(arraySimTerm[i].Aph, "\n");
        arraySimTerm[i].tok=i;
        i++;
    }
    nSimTerm=i;
    fclose(fileST);
}

void BacaCNFFile(){ //Membaca CNF
    int i=0;
    char temp[STR_SIZE];
    FILE *fileGram = fopen("CNF.txt","r");
    while(!feof(fileGram)){
        fgets(temp, STR_SIZE, fileGram);
        strtok(temp, "\n");
        strcat(temp, " |"); //Mark
        CNFPars(temp, i);
        i++;
    }
    fclose(fileGram);
}