#include <stdio.h>
#include <math.h>

 double h(double x){
    // 5x^3-2x^2+3
    return 5*pow(x,3)-2*pow(x,2)+3;
  }

  double g(double x){
    //x^4-3x^2-8
    return pow(x,4)-3*pow(x,2)-8;
  }

	double bisect(double xleft, double xright, double epsilon, double f(double fargs)){

  }

int main() {
    int i1,i2,tolerance;

    printf("Enter İnterval Endpoints.");
    scanf("%d %d", &i1, &i2);
  
    printf("Enter Tolerance");
    scanf("%d",&tolerance);

    
 

  return 0;
}