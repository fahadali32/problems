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
  int code;
  int mobile;
  float amount;
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
    printf("Enter code Name: ");
    scanf("%d",&info.code);
    printf("Enter Mobile Number: ");
    scanf("%d",&info.mobile);
    printf("Enter amount: ");
    scanf("%f",&info.amount);
    
    fp = fopen("./milk.csv","a");
    
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
    int code,found = 0;
    do{
      system(clear);
      fp=fopen("./milk.csv","rb");
      fp1=fopen("./milk_temp.csv","a");
      
      if (fp == NULL)
      {
        fprintf(stderr,"can't open file\n");
        exit(0);
      }
      printf("Enter the code: ");
      scanf("%d",&code);
      while(fread(&info,sizeof(struct person),1,fp)){
        if (info.code != code)
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
        printf("Enter the code name: ");
        scanf("%d",&up.code);
        printf("Enter the mobile: ");
        scanf("%d",&up.mobile);
        printf("Enter the amount: ");
        scanf("%f",&up.amount);

        fwrite(&up,sizeof(struct person),1,fp1);
        remove("./milk.csv");
        rename("./milk_temp.csv","./milk.csv");
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
    int code,found = 0;
    do{
      system(clear);
      fp=fopen("./milk.csv","rb");
      fp1=fopen("./milk_temp.csv","a");
      
      if (fp == NULL)
      {
        fprintf(stderr,"can't open file\n");
        exit(0);
      }
      printf("Enter the mobile: ");
      scanf("%d",&code);

      while(fread(&info,sizeof(struct person),1,fp)){
        if (info.code != code)
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
      
      if (info.code < 0)
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
      
      
      
      
      
      remove("./milk.csv");
      rename("./milk_temp.csv","./milk.csv");
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
    int code;
    do{
      system(clear);
      fp=fopen("./milk.csv","rb");
      if (fp == NULL)
      {
        fprintf(stderr,"can't open file\n");
        exit(0);
      }
      printf("Enter the code: ");
      scanf("%d",&code);
      while(fread(&info,sizeof(struct person),1,fp)){
        if (info.code == code)
        {
          found = 1;
          printf("\t\tName: %s %s \n",info.fname,info.lname);
          printf("\t\tAdress: %s\n",info.adress);
          printf("\t\tcode: %d\n",info.code);
          printf("\t\tmobile: %d\n",info.mobile);
          printf("\t\tamount:%.2f\n",info.amount);
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
      fp=fopen("./milk.csv","rb");
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
              if (data_array[j].mobile > data_array[j + 1].mobile) {
                  struct person temp = data_array[j];
                  data_array[j] = data_array[j + 1];
                  data_array[j + 1] = temp;
              }
          }
      }

      for (i = 0; i < num_data; i++) {
        printf("\t\tName  : %s %s\n",data_array[i].fname,data_array[i].lname);
        printf("\t\tAdress: %s\n",data_array[i].adress);
        printf("\t\tcode: %d\n",data_array[i].code);
        printf("\t\tmobile  : %d\n",data_array[i].mobile);
        printf("\t\tamount  :%.2f\n",data_array[i].amount);
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
    char *message = "\tMilk Management System\n"
                  "1.Add Member\n"
                  "2.Update Member Data\n"
                  "3.Delete Member Record\n"
                  "4.Search Member Data\n"
                  "5.Show All Members\n"
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
