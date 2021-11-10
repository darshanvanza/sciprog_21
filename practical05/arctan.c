#include<stdio.h>
#include<math.h>

//function declaration for arctanh1 & arctanh2
double arctanh1(const double x, const double delta);
double arctanh2(const double x);


//main function
int main(){
	
	//variable declaration
	double prec,n;
				
	//taking run time value from user for Precision
	printf("Enter a real positive number for Maclaurin series precision : ");
	scanf("%lf",&prec);
								
	//variable declaration
	double begin,end;
								
	//taking limits from user at run time
	printf("Enter start and end limits for x in (begin,end) format : ");
	scanf("%lf,%lf",&begin,&end);
									
	//finding how many number of times our loops should work
	n=((fabs(begin)+fabs(end))/prec)+1;
													
	//array size must be same as the number of times loop works
	int asize=n;

	//variables of array declaration
	double arctan1[asize];
	double arctan2[asize];
		
	//counter variables
	double i;
	int j=0;
	
	//loop for finding difference in results between Maclaurin series and natural logarithms 						
	for(i=begin;i<=end;i+=prec)
	{
	arctan1[j]=arctanh1(i,prec); //Macalurin series function call
	arctan2[j]=arctanh2(i);  //natural logaithm function call
	printf("The difference between arctan1[%.3lf] and arctan2[%.3lf] is : %.10lf. \n",i,i,fabs(arctan1[j]-arctan2[j]));
	j++;
												
	}
																					
	return 0;
}

//function definition of arctanh1 (Maclaurin series)
double arctanh1(const double x, const double delta){
	
	//local variable declaration
	double arctan=0;
	double element;
	int n=0;

	//implementing formula 
	do{
		
		double val=2*n + 1;
		element=pow(x,val)/val;
		arctan+=element;
		n++;
	}while(fabs(element)>=delta);
	
	//returning calculated value
	return arctan;
}

//function definition of arctanh2 (natural logarithm)
double arctanh2(const double x){
	return (log(1+x)-log(1-x))/2;
}
