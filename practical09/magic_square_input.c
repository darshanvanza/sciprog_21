
//header files
#include<stdio.h>
#include<stdlib.h>
#include "magic_square.h"

//main function
int main(){
	
	//local variable declaration
	int n;
	printf("Enter the square side : \n");
	scanf("%d",&n);  //getting input from user about the matrix size
	
	int i;
	int** magicSquare = malloc(n*sizeof(int));  //memory allocation for number of rows
	
	for(i=0;i<n;i++){
		magicSquare[i]=malloc(n*sizeof(int));  //memorry allocation for number of intergers per row
	}
	
	int j;
	
	//getting elements of matrix from user
	for(i=0;i<n;i++){
		printf("Enter %d row elements seperated by space or linebreaks\n",i+1);
		for(j=0;j<n;j++){
			scanf("%d",&magicSquare[i][j]);  //ith row and jth column element
		}
	}
	
	//check matrix is magic or not with function call from header file
	printf("The square %s magic. \n",isMagicSquare(magicSquare,n)?"is":"is NOT");  //function call
	
	//free pointer
	for(i=0;i<n;i++){
		free(magicSquare[i]);
	}
	free(magicSquare);
}

