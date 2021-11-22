//header files
#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

//function declaration
int getlines(char filename[MAX_FILE_NAME]);

//main function
int main(){
	
	//local variable declaration
	FILE* f;  //pointer of FILE to open, close and manipulate file
	char filename[MAX_FILE_NAME];

	printf("Enter file name : \n");
	scanf("%s",&filename);  //getting filename from user
	
	//file open
	f=fopen(filename,"r");
	int n=getlines(filename);  //function call to read lines from file
	
	int i;
	int** magicSquare = malloc(n*sizeof(int*));  //memory allocation for number of rows
	
	for(i=0;i<n;i++){
		magicSquare[i]=malloc(n*sizeof(int));  //memory allocation for elements per row
	}
	
	int j;
	
	//reading matrix elements from file
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(f,"%d",&magicSquare[i][j]);  //reading file
			printf("Element of row = %d, column = %d of square matrix  is : %d\n",i+1,j+1, magicSquare[i][j]);  //print element
		}
	}
	
	
	//checking square is magic or not using function call from header file
	printf("The square %s magic. \n",isMagicSquare(magicSquare,n)?"is":"is NOT");  //function call

	//free up space	
	for(i=0;i<n;i++){
		free(magicSquare[i]);
	}
	free(magicSquare);
	
	
	fclose(f);  //file close
}

//function definition
int getlines(char filename[MAX_FILE_NAME]){

	//local variable declaration
	FILE* fp;  //FILE pointer to open,close and manipulate file
	fp = fopen(filename,"r");  //file open
	
	int ch_read;
	int count = 0;
	
	//reading file data
	while((ch_read=fgetc(fp)) != EOF){
		if(ch_read=='\n'){
			count++;  //number of lines read
		}
	}
	
	printf("Number of lines %d\n",count);
	fclose(fp);  //file close
	return count;	
}
