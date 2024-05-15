#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation
#include <string.h> // for string manipulation
#define MAX_STUDENTS 500


struct student {
    char name[50];
    char surname[50];
    char email[50];
    float duration;
};



int main() {

    // Open the file
    char *filename = "input1.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // Array to store student information
    struct student students[MAX_STUDENTS];
    int num_students = 0; // To keep track of the number of students

    // Reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp)) {
        // Initialize a new student structure for each line

        printf("!%s", buffer);
        
        struct student new_student;

        char *token;  
        char *name;
    /* get the first token */  
        token = strtok(buffer, ",");  
        //Separates Names and Surame
        name = strtok(token, " ");
        
        while(name != NULL) {  
            name = strtok(NULL, " ");
            if(name != NULL){
                strcat(new_student.name, " ");
                strcat(new_student.name, name);
            }
            else{
                //strcpy(new_student.surname, name);
            }
        }

        //strcpy(new_student.name, name);

   /* loop through the string to extract all other tokens */  
     while(token != NULL) {  
      printf("%s\n", token);

      token = strtok(NULL, ",");  
   }  

        // Store the new student in the array
        students[num_students] = new_student;
        num_students++;

        // Check if the array is full
        if (num_students >= MAX_STUDENTS) {
            printf("Maximum number of students reached. Exiting loop.\n");
            break;
        }
    }

    // Close the file
    fclose(fp);

    // Print out the student information (for testing)
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: %s %s %s\n", i, students[i].name, students[i].surname, students[i].email);
    }

    return 0;
}
