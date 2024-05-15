#include <stdio.h>
#define SIZE 500

// reads numbers from the standard input into arr,
// and stores the number of read elements in the memory cell pointed to by nPtr
void readInput(int arr[], int *nPtr);

// prints the elements in arr[0..(n-1)]
void printNumbers(const int arr[], int n);

// Circularly shift elements of arr from left to right where last element of arr is
// shifted the first position of arr.
// Size of arr is n.
void circularShiftFromRightToLeft(int arr[], int n);


int main()
{
    int arr[SIZE];
    int n;
    readInput(arr, &n);
    printNumbers(arr, n);
    circularShiftFromRightToLeft(arr, n);
    printf("\nAfter one circular shift from right to left:\n");
    printf("Array elements:");
    printNumbers(arr, n);
    return 0;
}

void readInput(int arr[], int *nPtr){
    // reads numbers from the standard input into arr, and stores the number of elements read in the memory cell pointed to by nPtr
    int i = 0;
    char string[SIZE];
    printf("Enter the number of elements: \n");
    scanf("%d", nPtr);
    printf("Enter %d elements: \n", *nPtr);
    
    for (i = 0; i < *nPtr; i++){
        //printf("Enter %d. element: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    nPtr = arr;

    //Prints the array
    printf("Array elements:");
    for (i = 0; i < *nPtr; i++){
        printf("  %d ", arr[i]);
    }
    

}

void printNumbers(const int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        printf("  %d", arr[i]);
    }
    printf("\n");
}

void circularShiftFromRightToLeft(int arr[], int n)
{
    if (n <= 1) // No need to shift if array has 0 or 1 element
        return;

    int temp = arr[n - 1]; 

   
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp; 
    }

