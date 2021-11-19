//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
int iterativeGCD(int,int);
int recursiveGCD(int,int);

//main function
int main(){

	//local variable declaration
	int a,b,error;
	
	printf("input two positive integers : \n");
	error = scanf("%d %d",&a,&b);	 	//taking two inputs from user for which two numbers they want to find GCD
	
	//checking if user has entered two numbers or not
	if(error != 2){
		printf("Please try again\n");
		return 1;
	}

	//checking if user has entered both numbers as positive integers or not	
	if(a<=0 || b<=0){
		printf("Numbers are not positive !!\n Please input positive numbers");
		return 1;
	}
	
	//function calls inside printf statement	
	printf("GCD value of (%d,%d) by iterative GCD is %d \n",a, b, iterativeGCD(a,b));  //printing result by iterative GCD
	printf("GCD value of (%d,%d) by recursive GCD is %d \n",a,b, recursiveGCD(a,b));  //printing result by recursive GCD
	
	//return statement
	return 0;
	
}

//iterativeGCD function definition 
int iterativeGCD(int a,int b){

	//local variables declaration
	int exchange_value;

	//loop to find the GCD value of two numbers
	while(b!=0){
		exchange_value=b;
		b=a%b;
		a=exchange_value;
	}

	//returning calculated GCD value
	return a;
	
}

//recursiveGCD function definition
int recursiveGCD(int a,int b){

	//conditional statement to check and call the function again
	if(b==0)
		return a;
	else
		return recursiveGCD(b,a%b);  //self function call 
}
