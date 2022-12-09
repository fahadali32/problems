#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char *name;
	int roll;
};

int main () {
   FILE *fp,*fp1;
   struct student *s1 = (struct student*)malloc(sizeof(struct student*));
   fp = fopen("file.txt","a");
   s1->name = (char *)malloc(sizeof(char *));
   strcpy(s1->name ,"Fahad Ali");
   s1->roll = 1;
   fwrite(&s1,sizeof(struct student),1,fp);
   printf("%s %d",s1->name,s1->roll);

   struct student *s2;
   fp1 = fopen("file.txt","r");
   fread(&s2,sizeof(struct student),1,fp1);
   printf("%d",s2->roll);	
   fclose(fp);
   
   return(0);
}