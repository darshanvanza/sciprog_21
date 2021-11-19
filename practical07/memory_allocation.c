//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
int* allocatearray(int);
void fillwithones(int* , int);
void printarray(int* , int);
void freearray(int*);

//main function
int main(){

	//pointer and local variable declaration
	int* array_of_integers;
	int n;
	
	printf("Enter the number of elements in array : ");
	scanf("%d",&n);   //taking inputs from user
	

	array_of_integers=allocatearray(n);  //function call to allocate memory to pointer
	fillwithones(array_of_integers,n);  //function call to fill all the values of pointer with 1
	printarray(array_of_integers,n);  //function call to print values of pointer
	freearray(array_of_integers);  //function call to free up space allocated to pointer
	array_of_integers=NULL;
	return 0;
}

//function definition
int* allocatearray(int n){

	int* array_of_integers;
	array_of_integers=(int*) malloc(n*sizeof(int));  //allocating memory to pointer
	
	printf("Array of size %d allocated.\n",n);
	
	return array_of_integers;
}

//function definition to fill values with 1
void fillwithones(int* array_of_integers, int n){
	int i;
	for(i=0;i<n;i++){
		*array_of_integers=1;  //assigning all values to be 1
		array_of_integers++;
		
	}
}

//function deinition to print pointer values
void printarray(int* array_of_integers, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", *array_of_integers);
		array_of_integers++;		
	}
	printf("\n");
	
}

//function definition to freeup space allocated to pointer
void freearray(int* array_of_integers){
	free(array_of_integers);
	printf("Array freed. \n");
}
