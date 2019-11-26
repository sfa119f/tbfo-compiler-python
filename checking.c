#include <stdio.h>
#include <stdlib.h>

void print_tokeninput(){
	for(int i=0; i<kolIn; i++){
		for(int j=1; j<tokenIn[i][0]; j++){
			printf("%d ", tokenIn[i][j]);
		}
		printf("\n\n");
	}
    for(int i=0; i<kolIn; i++){
		for(int j=1; j<tokenIn[i][0]; j++){
			printf("%s", parsingIn[i][j]);
		}
		printf("\n\n");
	}
}

void print_grammar(){
	for(int i=0; i<nSimTerm; i++){
		for(int j=1; j<atoi(grammar[i][0]); j++){
			printf("%s ", grammar[i][j]);
		}
		printf("\n");
	}
}
