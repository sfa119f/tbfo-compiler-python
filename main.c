//TUBES 2 TBFO IF2124 2019 - COMPILER BAHASA PYTHON

//Anggota Kelompok:
//Faris Fadhilah    // 13518026
//Iqbal Naufal      // 13518074
//Syarifuddin F A   // 13518095

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "strukturData.c"
#include "BacaOlahFile.c"
#include "CYK.c"
#include "TulisFile.c"
//#include "checking.c" //hanya untuk pengujian data

int main(){
    printf("\nProgram compiler bahasa python (.py)\n\n");

    BacaSimTermFile();  //baca file simbol dan terminal
    BacaCNFFile();      //baca file CNF
    BacaInputFile();    //baca file yang akan di-compile

    MakeCYK();          //pemrosesan menggunakan algoritma CYK

    CetakTokenList();   //mencetak ke file token list dari simbol dan terminal
    CetakCYKTab();      //mencetak ke file tabel CYK

    //cek apakah language terpenuhi atau tidak sesuai algoritma CYK
    boolean acc = false;
    char *top = strtok(tabCYK[0][nTab-1], " ");
    while(!acc && top!=NULL){
        if(strcmp(top, "0") == 0) acc=true;
        else top=strtok(NULL, " ");
    }
    if(acc) printf("\nCompile Success\n");
    else printf("\nCompile ERROR\n");
}