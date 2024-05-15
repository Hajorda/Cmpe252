#define SIZE 1000
#include <stdio.h>

    void readInput(int arr[], int *nPtr){
    // reads numbers from the standard input into arr, and stores the number of elements read in the memory cell pointed to by nPtr
    int i = 0;
    char string[SIZE];
    printf("Enter the number of elements: \n");
    scanf("%d", nPtr);
    printf("Enter %d elements: ", *nPtr);
    
    for (i = 0; i < *nPtr; i++){
        //printf("Enter %d. element: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    nPtr = arr;
    // 

}
void printNumbers(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
void swap(int *xPtr, int *yPtr) { 
    // swaps the numbers pointed to by xPtr and yPtr in the array
    int temp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = temp;
  
}


int main(int argc, char const *argv[])
{
    int arr[SIZE];
    int n;

    readInput(arr,&n);
   printNumbers(arr, n);


    return 0;
}
