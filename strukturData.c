#define MX_SIZE  1000
#define STR_SIZE 500

typedef struct{
    char Aph[STR_SIZE];
    int tok;
}SimTerm;   //penyimpan simbol dan terminal

// Global Variable
int kolIn;          //jumlah baris file input
int nSimTerm;       //jumlah simbol dan terminal
int nTab;           //panjang tabel CYK
//char strInput[MX_SIZE][STR_SIZE];           //string file input per baris
char grammar[MX_SIZE][MX_SIZE][STR_SIZE];   //grammar dalam bentuk token
SimTerm arraySimTerm[MX_SIZE];              //penyimpan simbol dan terminal beserta tokennya
char parsingIn[MX_SIZE][MX_SIZE][STR_SIZE];
int tokenIn[MX_SIZE][MX_SIZE];              //input dlm bentuk token
char tabCYK[MX_SIZE][MX_SIZE][STR_SIZE];    //CYK tabel
char row[MX_SIZE][MX_SIZE];                 //menyimpanan sementara precomputed pasangan rules
