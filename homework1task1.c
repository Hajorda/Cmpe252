#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 250

float myAtof(char *string, char *error);

int main() {
    char string[SIZE];      // Array declaration.
        float floatNum1;
        float floatNum2;
        char operation;
        int errorState = 0;
        char stringNum1[SIZE];
        char stringNum2[SIZE];

        printf("Enter arithmetic operation: \n");
        fgets(string, SIZE, stdin); // Using fgets to read input line
        
        if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
      

         if (strlen(string) == 1 && (string[0] == '+' || string[0] == '-' || string[0] == '*' || string[0] == '/')) {
            printf("0.00 %c 0.00 = 0.00\n", string[0]);
            return 0;
        }
    
        
        if (strlen(string) < 3) {
            printf("Invalid operator type!\n");
            return 1;
        }
       
        // example input 1.04 + 1203.43
        int i = 0;
        while (string[i] >= '0' && string[i] <= '9' || string[i] == '.') {
            stringNum1[i] = string[i];
            //fprintf(stdout, "stringNum1[%d]: %c\n", i, stringNum1[i]);
            i++;
            if (!(string[i] >= '0' && string[i] <= '9' || string[i] == '.')) {
                //fprintf(stdout, "patladı!\n");
                //fprintf(stdout, "string[i]: %c\n", string[i+1]);
                break;
            }
        }
        //fprintf(stdout, "stringNum1: \"%s\" \n", stringNum1);
        floatNum1 = myAtof(stringNum1, &errorState);
       
        if (errorState) {
            printf("Error: Invalid input!\n");
            return 1;
        }

       // Loop for finding operator
        while (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/') {
            //fprintf(stdout, "string[i]: %c\n", string[i]);
            i++;
        }
        operation = string[i];

      // fprintf(stdout, "operation: %c\n", operation);
        i++;
        if (string[i] == ' ') {
            i++;
        }
        //i moves to the next number
         while (1) {
            //fprintf(stdout, "string[i]: %c\n", string[i]);
            if (string[i] >= '0' && string[i] <= '9' || string[i] == '.') {
                break;
            } else {
                break;
            }
   
         }
        
        int j = 0;
        //fprintf(stdout, "i: %d\n", i);
        while (string[i] >= '0' && string[i] <= '9' || string[i] == '.') {
            stringNum2[j] = string[i];
            //fprintf(stdout, "stringNum2[%d]: %c\n", j, stringNum2[j]);
            i++;
            j++;
            if (!(string[i] >= '0' && string[i] <= '9' || string[i] == '.')) {
               // fprintf(stdout, "patladı!\n");
                break;
            }
        }
        //fprintf(stdout, "stringNum2: %s\n", stringNum2);
        floatNum2 = myAtof(stringNum2, &errorState);
        if (errorState) {
            printf("Error: Invalid input!\n");
            return 1;
        }



        //fprintf(stdout, "floatNum1: %f\n", floatNum1);
        //fprintf(stdout, "floatNum2: %f\n", floatNum2);
       // fprintf(stdout, "operation: %c\n", operation);






        switch (operation) {
            case '+':
                printf("%.2f + %.2f = %.2f\n", floatNum1, floatNum2, floatNum1 + floatNum2);
                break;
            case '-':
                printf("%.2f - %.2f = %.2f\n", floatNum1, floatNum2, floatNum1 - floatNum2);
                break;
            case '*':
                printf("%.2f * %.2f = %.2f\n", floatNum1, floatNum2, floatNum1 * floatNum2);
                break;
            case '/':
                if (floatNum2 != 0) {
                    printf("%.2f / %.2f = %.2f\n", floatNum1, floatNum2, floatNum1 / floatNum2);
                } else {
                    printf("Cannot divided into 0.\n");
                }
                break;
            default:
                printf("Error: Invalid operator type!\n");
                break;
        }

        return 0;

        }

    float myAtof(char* string, char* error) {
        float result = 0.0;
        int dF = 0;
    float decimalPart = 0.0;
    float divisor = 10.0;
    int i = 0;
    int negative = 0; // Flag to indicate if the number is negative

    // Check for negative sign at the beginning of the string
    if (string[0] == '-') {
        negative = 1;
        i = 1; // Skip the negative sign
    }

    while (string[i] != '\0') {
        if (dF == 1) {
            while (string[i] != '\0') {
                if (string[i] >= '0' && string[i] <= '9') {
                    decimalPart += (string[i] - '0') / divisor;
                    divisor *= 10;
                } else {
                    *error = 1;
                    return 0.0;
                }
                i++;
            }
        } else {
            if (string[i] >= '0' && string[i] <= '9') {
                result = result * 10 + (string[i] - '0');
            } else if (string[i] == '.') {
                if (dF) {
                    *error = 1;
                    return 0.0;
                }
                dF = 1;
            } else {
                *error = 1;
                return 0.0;
            }
            i++;
        }
    }

    if (negative) {
        result = -result; // Convert the result to negative if negative flag is set
    }

    if (!dF) {
        return result;
    }

    return result + decimalPart;
}
