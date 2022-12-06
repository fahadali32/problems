#include<stdio.h>

int main(){
  FILE *fp;
  fp = fopen("./data.csv","w");
  fprintf(fp,"%s","Fahad,");
  fprintf(fp,"%d %s",1,",");
  fprintf(fp,"%d %s",100,",");
  fprintf(fp,"%s","Ali");
  fclose(fp);
 
  
  return 0;
}
