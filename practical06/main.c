#include<stdio.h>

//main function
int main(){

	//variable declaration	
	int n=5,p=3,q=4;
	double a[n][p],b[p][q],c[n][q]; //3 matrices of 2 dimensional
	
	//loop variables
	int i,j,k;
	
	//putting all values of matrix C to zero
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			c[i][j]=0.0;
			
		}
	}

	//creation of matrix A	
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			a[i][j]=i+j;
			
		}
	}
	
	//creation of matrix B
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			b[i][j]=i-j;
			
		}
	}
	
	//calling function from another C file matmult.c
	matmult(n,p,q,a,b,c);
	
	//printing matrix A
	printf("Matrix A is : \n");
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			printf("%4.0f",a[i][j]);
			
		}
		printf("\n");
	}
	
	//printing matrix B
	printf("Matrix B is : \n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			printf("%4.0f",b[i][j]);
			
		}
		printf("\n");
	}


	//printing matrix C after multiplying matrices A and B	
	printf("Matrix C after multiplication of matrices A and B is : \n");
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			printf("%4.0f",c[i][j]);
			
		}
		printf("\n");
	}
	
	
	
	return 0;
	
}
