#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store data
struct person {
  char fname[256];
  char lname[256];
  char adress[256];
  char course_name[256];
  int roll;
  float cgpa;
};

int main() {
    // Create a structure variable to store data
    struct person data;

    // Open a file in append mode
   //  FILE *file = fopen("data.txt", "a");
   //  if (file == NULL) {
   //      printf("Error opening file!\n");
   //      exit(1);
   //  }

   //  // Read data from the user
   //  printf("Enter name: ");
   //  scanf("%s", data.fname);
   //  printf("Enter age: ");
   //  scanf("%d", &data.roll);
   //  printf("Enter height: ");
   //  scanf("%f", &data.cgpa);

   //  // Append the data to the file
   //  fwrite(&data, sizeof(struct Data), 1, file);

   //  // Close the file
   //  fclose(file);
    FILE *file;
    // Open the file in read mode
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the data from the file and store it in an array
   //  int temp_num = 0;
   //  while (fread(&data, sizeof(struct person), 1, file)) {
   //      temp_num++;
   //  }
   //  printf("%d",temp_num);
    
   //struct person data_array[100];
   
   // allocate memory for n students using dynamic memory allocation
    //struct person *data_array = (struct person*)malloc(5 * sizeof(struct person));
   fseek(file, sizeof(struct person)-1, SEEK_END);
   int n = ftell(file) / sizeof(struct person);
    
   struct person data_array[100];
    printf("%d",n);
    int num_data = 0;
    while (fread(&data_array[num_data], sizeof(struct person), 1, file)) {
        num_data++;
    }

    // Sort the data using a simple bubble sort algorithm
    int i, j;
    for (i = 0; i < num_data - 1; i++) {
        for (j = 0; j < num_data - i - 1; j++) {
            if (data_array[j].roll > data_array[j + 1].roll) {
                // Swap the data
                struct person temp = data_array[j];
                data_array[j] = data_array[j + 1];
                data_array[j + 1] = temp;
            }
        }
    }

    // Print the sorted data
    for (i = 0; i < num_data; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", data_array[i].fname, data_array[i].roll, data_array[i].cgpa);
    }

    // Close the file
    fclose(file);

    return 0;
}
