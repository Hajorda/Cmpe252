#include <stdio.h>
#include <math.h>

int primeChecker(int number, int whyWeAreDoingThisRecursive){
    if(whyWeAreDoingThisRecursive == 2){
        return 1;
    }
    else{
        if(number%whyWeAreDoingThisRecursive==0){
            return 0;
        }
        else{
            return primeChecker(number,whyWeAreDoingThisRecursive-1);
        }
        
            return 3;
    }
}

int main(void){

    int number;
    printf("Enter the integer you want to check is it Prime or Not.");
    scanf("%d",&number);
    printf(primeChecker(number,number-1)==1 ? "The number is Prime." : "The number is not Prime.");


    return 0;
}