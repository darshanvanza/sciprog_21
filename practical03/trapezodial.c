#include<stdio.h>
#include<math.h>

int main(){

//variable declaration 
int i,N=12;
float a=0.0,b_deg=60.0,b_rad;

//converting from degree to radian 
b_rad=(M_PI * b_deg)/180.0;


//summing first and last part of function
float area=tan(a)+tan(b_rad);

//loop for (N-2)=10 middle parts of function for finding area
for(i=5;i<60;i+=5)
{
	area=area+2*tan((M_PI*i)/180.0);	
}

float mult_rad;

//multiplication with (b-a)/2N and converting to radian and multiply result with area
mult_rad=M_PI*((b_deg-a)/(2*N))/180.0;
area=mult_rad*area;

//Trapezodial result from function 
printf("\nTrapezodial result = %f\n",area);

//log(2) result that should be compared with Trapezodial result
printf("\nReal result = %f\n",log(2.0));

return 0;
}

