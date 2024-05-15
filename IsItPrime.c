#include <stdio.h>
#include <math.h>

int primeChecker(int number, int whyWeAreDoingThisRecursive){
    if(whyWeAreDoingThisRecursive == 1){
        return 1;
    }
    else{
        if(number%whyWeAreDoingThisRecursive==0){
            return 0;
        }
        else{
            return primeChecker(number,whyWeAreDoingThisRecursive-1);
        }
            //Why we don't have a boolean type in C?
            return 3;
    }
}

int power_raiser(int base, int power)
{
	int ans = 1;
if(power == 2)
	ans = base*base;
else
	ans = power_raiser(base,power-1)*base;
return ans;
}


int main(void){

    int number;
    printf("Enter the integer you want to check is it Prime or Not.");
    scanf("%d",&number);
    printf(primeChecker(number,number-1)==1 ? "The number is Prime." : "The number is not Prime.");

    printf("\n Enter the number you want to raise to the power of 5.");
    scanf("%d",&number);
    printf("The result is %d \n",power_raiser(number,5));

    return 0;
}