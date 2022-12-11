#include <stdio.h>
#include <stdlib.h>

// structure to store data
struct person {
char fname[20];
char lname[20];
int roll;
float cgpa;
};

int compare(const void *a, const void *b)
{
// typecast void pointers to struct pointers
struct person *p1 = (struct person*)a;
struct person *p2 = (struct person*)b;


// compare cgpa of two students
return (p1->roll - p2->roll);
}

int main()
{
FILE *fp;
struct person *stud;
int i, n;


// // open file in append mode
// fp = fopen("students.bin", "ab");
// if (fp == NULL)
// {
//     printf("Error opening file!\n");
//     exit(1);
// }

// // input number of students
// printf("Enter number of students: ");
// scanf("%d", &n);

// // allocate memory for n students using dynamic memory allocation
// stud = (struct person*)malloc(n * sizeof(struct person));

// // input data for each student
// for (i = 0; i < n; i++)
// {
//     printf("Enter data for student %d\n", i + 1);
//     printf("Enter first name: ");
//     scanf("%s", (stud + i)->fname);
//     printf("Enter last name: ");
//     scanf("%s", (stud + i)->lname);
//     printf("Enter roll number: ");
//     scanf("%d", &(stud + i)->roll);
//     printf("Enter CGPA: ");
//     scanf("%f", &(stud + i)->cgpa);
// }

// // write data to file in append mode
// fwrite(stud, sizeof(struct person), n, fp);

// // close file
// fclose(fp);

// open file in read mode
fp = fopen("students.bin", "rb");
if (fp == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

// read data from file
fread(stud, sizeof(struct person), n, fp);

// sort data based on cgpa using qsort function
qsort(stud, n, sizeof(struct person), compare);

// print sorted data
system("clear");
printf("Sorted data:\n");
for (i = 0; i < n; i++)
{
    printf("First Name: %s\n", (stud + i)->fname);
    printf("Last Name: %s\n", (stud + i)->lname);
    printf("Roll Number: %d\n", (stud + i)->roll);
    printf("CGPA: %.2f\n", (stud + i)->cgpa);
}

// free allocated memory
//free(stud);

// close file
fclose(fp);

return 0;
}




