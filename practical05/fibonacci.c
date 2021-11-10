#include<stdio.h>
#include<math.h>

//function declaration
void fibonacci(int *p1,int *p2);

//main function
int main(){
	
	//variable declaration
	int n1=0, n2=1;
	int n,i;
	int *p1, *p2;

	//taking value from user at run time 	
	printf("Enter how many values do you want to see in fibanacci series :\n");
	scanf("%d", &n);
	
	//making pointers point to the variables by giving variables addresses to pointers
	p1 = &n1;
	p2 = &n2;
	
	//printing first element of fibonacci series
	printf("Fibonacci series upto %d values is :\n",n);
	printf("%d",*p1);
	
	//finding and printing from index 1 to n-2 elements of fibonacci series by calling function
	for(i=1;i<n-1;i++){
		fibonacci(p1,p2);   //function call
		printf("%3d",*p1);		
	}

	//printing last element	
	printf("%3d\n",*p2);
		
	return 0;
}

//funcion definition
void fibonacci(int *p1, int *p2){
	
	//local variable declaration	
	int next;
	
	//counting next number of series
	next= *p1 + *p2;
	
	//exchanging values
	*p1=*p2;
	*p2=next;
}
