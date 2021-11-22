//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
void hanoi(int, int, int, int);

//main functtion
void main(){

	//local variable declaration
	int n;

	printf("Enter number of disks : \n");
	scanf("%d",&n);  //user input for how many disk
  
	printf("Tower of hanoi solution for %d disks : \n",n);
	hanoi(n,1,3,2);	//function call
}

//function definition
void hanoi(int n,int source, int dest, int mid){
	
	//condition check for recursive function call
	if(n==1){
		//move disk from rod 1 to rod 3
		printf("Moved disk %d from %d to %d\n",n,source,dest);
	}
	
	else{
		//move n-1 disks from rod 1 to rod 2
		hanoi(n-1,source,mid,dest); //recursive function call

		printf("Moved disk %d from %d to %d\n",n,source,dest);

		//move n-1 disks from rod 2 to rod 3
		hanoi(n-1,mid,dest,source);
	}
	
}
