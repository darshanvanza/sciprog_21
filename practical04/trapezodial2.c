#include<stdio.h>
#include<math.h>

// function declaration globally
float dtor(float dang);
float trapezodialcalc(int N, float tarr[N+1]);

int main(){
  
  //variable declaration
  int N=12, i;
  float tarr[N+1], deg, rad;
  
  //Calculating values of f(xi) from i=5 to 55 increading by 5 and storing it in array
  //finding degree to radian using user defined function dtor()
  for(i=0; i<=N; i++){
  deg=i*5.0;
  rad=dtor(deg);  // Calling dtor function as pass by value
  tarr[i]=tan(rad);
  printf("tarr[%d]=%f (f(x) at x=%d)\n",i,tarr[i],i);    
 }
  
  //finding area by trapezodial rule
  float area;
  area=trapezodialcalc(N, tarr); // Calling trapezodialcalc function as pass by value
   
  //Trapezodial result value
  printf("\nTrapezodial result: %f\n", area);
  
  //Actual value
  printf("Real Result: %f\n", log(2.0));
  
  return 0;
}


//function definitions

//function dtor
float dtor(float dang){
  return((M_PI*dang)/180.0);
} 

float trapezodialcalc(int N, float tarr[N+1]){
  
  // Declaring local variables
  int i;
  float area;
  
  // Calculating f(x0)+2*f(x1)+2*f(x2)+...+2*f(xn-1)+f(xn) 
  area=tarr[0]+tarr[N];
  for(i=1; i<N; i++){
   area=area+2.0*tarr[i];  
  }
                     
  //Multipling area by (f[N]-f[0])/2N after converting it into radians
  float mult_rad=dtor((60.0-0.0)/(2.0*N));
  area=mult_rad*area;
  return area;
}
