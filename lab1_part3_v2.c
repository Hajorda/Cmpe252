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
void circularShiftFromLeftToRight(int arr[], int n);

// Let n be the minimum of n1 and n2 where n1 and n2 are the number of elements in
// arr1 and arr2, respectively.
// Compare corresponding elements of arr1 and arr2 at each of the first n positions.
//
// If arr1 and arr2 has the same value in each position:
// Return 0 if n1 == n2
// Return 1 if n1 > n2
// Return -1 if n1 < n2
//
// If arr1 has a larger value than arr2 considering the first position from the
// beginning at which arr1 and arr2 have a different value:
// Return 1
//
// If arr1 has a smaller value than arr2 considering the first position from the
// beginning at which arr1 and arr2 have a different value:
// Return -1
int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2);

// Circularly shift elements of arr from left to right until sequence of values in
// arr becomes the smallest considering all sequence of values obtained by circularly
// shifting elements in arr.
void circularShiftUntilMinArr(int arr[], int n);
int findMax(const int arr[], int n);

int main()
{
    int arr[SIZE];
    int n;
    readInput(arr, &n);
    printf("Array elements:");
    printNumbers(arr, n);
    circularShiftUntilMinArr(arr, n);
    printf("\nAfter circularShiftUntilMinArr:\n");
    printf("Array elements:");
    printNumbers(arr, n);

    int maxElement = findMax(arr, n);
    printf("Maximum element of the array: %d\n", maxElement);

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

  
    

}

void printNumbers(const int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        printf("  %d", arr[i]);
    }
    printf("\n");
}

void circularShiftFromLeftToRight(int arr[], int n) {
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2) {
    int min = (n1 < n2) ? n1 : n2;
    for (int i = 0; i < min; i++) {
        if (arr1[i] > arr2[i]) return 1;
        else if (arr1[i] < arr2[i]) return -1;
    }
    if (n1 == n2) return 0;
    else if (n1 > n2) return 1;
    else return -1;
}

void circularShiftUntilMinArr(int arr[], int n) {
    int minArr[SIZE];
    for (int i = 0; i < n; i++) {
        minArr[i] = arr[i];
    }
    for (int i = 1; i < n; i++) {
        circularShiftFromLeftToRight(arr, n);
        if (compareTwoArrays(arr, minArr, n, n) == -1) {
            for (int j = 0; j < n; j++) {
                minArr[j] = arr[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = minArr[i];
    }
}

int findMax(const int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}