//header files
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//all functions declaration
int factorial(int);
double compute_polynomial(int, int);

//main function
int main(){
	
	//local variable declaration
	int order_polynomial;
	int x=1;
	
	printf("Enter the order of polynomial you want : ");
	scanf("%d",&order_polynomial);   //taking input from user for order of polynomial
	
	//creating pointer for polynomial array
	double* polynomial_array;
	int polynomial_array_size=order_polynomial+1;  //total polynomial array size
	polynomial_array=(double*) malloc(polynomial_array_size * sizeof(double));  //allocating memory to polynomial array
	
	//loop variable
	int i;
	
	//loop to find polynomial 
	for(i=0;i<polynomial_array_size;i++){
		polynomial_array[i]=compute_polynomial(i,x);   //function call
		printf("f[%d] = %.20f\n",i,polynomial_array[i]);
	}
	
	//finding e^1
	printf("e1 = %.20f\n",exp(1));
	
	//finding difference
	for(i=0;i<polynomial_array_size;i++){
		printf("Difference in value for term %d is %.20f\n",i,exp(1)-polynomial_array[i]);
	}

	//free the pointer	
	free(polynomial_array);
	polynomial_array=NULL;
	
	
	
	return 0;
}

//function definition to find factorial of a number
int factorial(int n){

	int fact=1;   //local variable to count factorial

	//conditional statements to call function recursively 
	if(n==0)
		return fact;
	else if(n==1)
		return fact;
	else{
		fact=n*factorial(n-1);   //self function call
	}
	return fact;	
}

//function definition to compute polynomial
double compute_polynomial(int n,int x){

	//local variable declaration
	int i;
	double sum=0.0;
	
	//loop to find sum of polynomial
	for(i=0;i<=n;i++){
		sum += (double)pow(x,i)/factorial(i);
	}
	return sum;
	
}


/* when we take polynomial of higher order say 34 or more we are getting result as Infinity and reason behind this is that, here we are returning integer value 
 * in factorial function so when we do 34! its integer value is 0 in C language so 1/34! becomes Infinity. If you return double rather than integer than you 
 * will get value 1.0000000000000000000 (many times 0) for 1/34!. Its based on C architecture and even difference between e^1 and polynomial, some of the values * are negative which is because of how C stores values in memory for variables but as we increase the order of polynomial, we are getting smaller difference.*/  
