#include<stdio.h>
#include <string.h>
#include<stdlib.h>


#ifdef _WIN32
  #define clear "cls"
#else 
  #define clear "clear"
#endif
#define MAX_STR_LEN 256

struct person{
  char fname[256];
  char lname[256];
  char adress[256];
  char course_name[256];
  int roll;
  float cgpa;
};

int found = 0;

void addStudent(){
  char another;
  FILE *fp;
  struct person info;
  do
  {
    int header = 0;
    
    system(clear);
    printf("\t.....Add student.....\n\n");
    
    printf("Enter First Name: ");
    scanf("%s",info.fname);
    
    printf("Enter Last Name: ");
    scanf("%s",info.lname);
    printf("Enter Adress: ");
    scanf("%s",info.adress);
    printf("Enter Course Name: ");
    scanf("%s",info.course_name);
    printf("Enter Roll: ");
    scanf("%d",&info.roll);
    printf("Enter CGPA: ");
    scanf("%f",&info.cgpa);
    
    fp = fopen("./data.csv","a");
    
    fwrite(&info, sizeof(struct person), 1, fp); 
    fclose(fp);
    if (fp == NULL) 
    {
      printf("Can't open the file\n");
    }else
    {
      printf("Record stored successfuly\n");
    }
    
    printf("Add another student (y/n)");
    scanf("%s",&another);  
  } while (another=='y'||another=='Y');
  
}

void updateStudent(){
    FILE *fp,*fp1;
    struct person info;
    char another;
    int roll,found = 0;
    do{
      system(clear);
      fp=fopen("./data.csv","rb");
      fp1=fopen("./temp.csv","a");
      
      if (fp == NULL)
      {
        fprintf(stderr,"can't open file\n");
        exit(0);
      }
      printf("Enter the roll: ");
      scanf("%d",&roll);
      while(fread(&info,sizeof(struct person),1,fp)){
        if (info.roll != roll)
        {
          fwrite(&info,sizeof(struct person),1,fp1);
        } else
        {
          found = 1;
        }
        
      }
      
      if (found == 1)
      {
        struct person up;
      
        printf("Enter the first name: ");
        scanf("%s",up.fname);
        printf("Enter the last name: ");
        scanf("%s",up.lname);
        printf("Enter the adress: ");
        scanf("%s",up.adress);
        printf("Enter the course name: ");
        scanf("%s",up.course_name);
        printf("Enter the roll: ");
        scanf("%d",&up.roll);
        printf("Enter the cgpa: ");
        scanf("%f",&up.cgpa);

        fwrite(&up,sizeof(struct person),1,fp1);
        remove("./data.csv");
        rename("./temp.csv","./data.csv");
        fclose(fp);
        fclose(fp1);
      }
      else
      {
        printf("Record not found\n");
      }
      
      
      printf("Wana go back (y/n)");
      scanf("%s",&another); 
    }
    while (another=='n'||another=='N');
     
}

void deleteStudent(){
    FILE *fp,*fp1;
    struct person info;
    char another;
    int roll,found = 0;
    do{
      system(clear);
      fp=fopen("./data.csv","rb");
      fp1=fopen("./temp.csv","a");
      
      if (fp == NULL)
      {
        fprintf(stderr,"can't open file\n");
        exit(0);
      }
      printf("Enter the roll: ");
      scanf("%d",&roll);

      while(fread(&info,sizeof(struct person),1,fp)){
        if (info.roll != roll)
        {
          found = 1;
          fwrite(&info,sizeof(struct person),1,fp1);
          found = 0;
        }
        else
        {
          printf("Record deleted successfully\n");
          found = -1;
        }
        
      }
      
      if (info.roll < 0)
      {
        printf("Record not exists\n");
      }
      
      if (found == 1)
      {
        printf("Student record not found\n");
      }else if (found == -1)
      {
        /* code */
      }
      else
      {
        printf("Record not exists\n");
      }
      
      
      
      
      
      remove("./data.csv");
      rename("./temp.csv","./data.csv");
      fclose(fp);
      fclose(fp1);

      printf("Wana go back (y/n)");
      scanf("%s",&another); 
    }
    while (another=='n'||another=='N');
     
}

void search(){
    FILE *fp;
    struct person info;
    char another;
    int roll;
    do{
      system(clear);
      fp=fopen("./data.csv","rb");
      if (fp == NULL)
      {
        fprintf(stderr,"can't open file\n");
        exit(0);
      }
      printf("Enter the roll: ");
      scanf("%d",&roll);
      while(fread(&info,sizeof(struct person),1,fp)){
        if (info.roll == roll)
        {
          found = 1;
          printf("\t\tName: %s %s \n",info.fname,info.lname);
          printf("\t\tAdress: %s\n",info.adress);
          printf("\t\tCourse: %s\n",info.course_name);
          printf("\t\tRoll: %d\n",info.roll);
          printf("\t\tCGPA:%.2f\n",info.cgpa);
          printf("\n"); 
        }
      }
      if (!found)
      {
        printf("Student record not found\n");
      }
      
      fclose(fp);
      printf("Wana go back (y/n)");
      scanf("%s",&another); 
    }
    while (another=='n'||another=='N');
     
}


void display(){
    char another;
    FILE *fp;
    struct person info;
    
    do
    {
      fp=fopen("./data.csv","rb");
      system(clear);
      
      printf("\t\t\t\t___STUDENTS RECORD___\n\n\n");
      if(fp==NULL){   
          fprintf(stderr,"can't open file\n");
          exit(0);
      }else{
          //printf("");
      }
      struct person data_array[sizeof(struct person)];
      int num_data = 0;
      while (fread(&data_array[num_data], sizeof(struct person), 1, fp)) {
          num_data++;
      }

      int i, j;
      for (i = 0; i < num_data - 1; i++) {
          for (j = 0; j < num_data - i - 1; j++) {
              if (data_array[j].roll > data_array[j + 1].roll) {
                  struct person temp = data_array[j];
                  data_array[j] = data_array[j + 1];
                  data_array[j + 1] = temp;
              }
          }
      }

      for (i = 0; i < num_data; i++) {
        printf("\t\tName  : %s %s\n",data_array[i].fname,data_array[i].lname);
        printf("\t\tAdress: %s\n",data_array[i].adress);
        printf("\t\tCourse: %s\n",data_array[i].course_name);
        printf("\t\tRoll  : %d\n",data_array[i].roll);
        printf("\t\tCGPA  :%.2f\n",data_array[i].cgpa);
        printf("\n");
        
      } 
      
      fclose(fp);
      
      printf("Wana go back (y/n)");
      scanf("%s",&another); 
    } while (another=='n'||another=='N');
        
  }

int main(){
  system(clear);
  int option;
  do
  {
    char *message = "\tStudent Management Student\n"
                  "1.Add Students\n"
                  "2.Update Students Data\n"
                  "3.Delete Students Record\n"
                  "4.Search Students Data\n"
                  "5.Show All Students\n"
                  "6.Exit\n";                  
    printf("%s",message);

    printf("\nPlease select the option: ");
    scanf("%d",&option);
    
    switch (option) {
      case 1:
        system(clear);
        addStudent();
        system(clear);
        break;
      case 2:
        system(clear);
        updateStudent();
        system(clear);
        break;
      case 3:
        system(clear);
        deleteStudent();
        system(clear);
        break;
      case 4:
        system(clear);
        search();
        system(clear);
        break;
      case 5:
        system(clear);
        display();
        system(clear);
        break;
      case 6:
        exit(1);
      default:
        printf("Please select the right option\n");
        break;
    }
  } while (option != 6);
  
  
  return 0;
}
