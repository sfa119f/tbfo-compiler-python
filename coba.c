#include <stdio.h>

int main(){
    FILE *fptr;
    fptr = fopen("test.txt","r");
    int ch = getc(fptr);
    while(ch!=EOF){
        putchar(ch);
        ch = getc(fptr);
    }
    if (feof(fptr)){
        printf("\n End of file reached."); 
    }
    else{
        printf("\n Something went wrong."); 
    }
    fclose(fptr);
}