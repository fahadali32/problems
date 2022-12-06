#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<string.h>

#ifdef _WIN32
  #define clear "cls"
#else 
  #define clear "clear"
#endif

struct person{
  char *fname;
  char *lname;
  char *adress;
  char *course_name;
  int roll;
  int cgpa;
};

void addStudent(){
  char another;
  FILE *fp;
  struct person info;
  do
  {
    int cgpa,roll;
    char *fname,*lname,*adress,*course_name;
    fname = (char *)malloc(sizeof(char *));
    lname = (char *)malloc(sizeof(char *));
    adress = (char *)malloc(sizeof(char *));
    course_name = (char *)malloc(sizeof(char *));

    system(clear);
    printf("\t.....Add student.....\n\n");
    
    printf("Enter First Name: ");
    scanf("%s",fname);
    info.fname = fname;
    //strcpy(info.fname,fname);
    printf("Enter Last Name: ");
    scanf("%s",lname);
    info.lname = lname;
    printf("Enter Adress: ");
    scanf("%s",adress);
    info.adress = adress;    
    printf("Enter Course Name: ");
    scanf("%s",course_name);
    info.course_name = course_name;    
    printf("Enter Roll: ");
    scanf("%d",&roll);
    info.roll = 1;
    printf("Enter CGPA: ");
    scanf("%d",&cgpa);
    info.cgpa = cgpa;

    fp = fopen("./data.csv","w");
    fprintf(fp,"%s","Fahad,");
    fprintf(fp,"%d %s",1,",");
    fprintf(fp,"%d %s",100,",");
    fprintf(fp,"%s","Ali");
    fclose(fp);

    printf("Add another student (y/n)");
    scanf("%s",&another);  
  } while (another=='y'||another=='Y');
  
}

void show(){
  char another;
  struct person data;
  do
  {
    system(clear);
    printf("%d",data.roll);
    printf("Add another student (y/n)");
    scanf("%s",&another);
  } while (another=='y'||another=='Y');

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
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        show();
        break;
      case 6:
        exit;
      default:
        printf("Please select the right option\n");
        break;
    }
  } while (option != 6);
  
  
  return 0;
}
