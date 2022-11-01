#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  char num[10][10] = {
                        "0",
                         "one",
                         "two",
                         "three",
                         "four",
                         "five",
                         "six",
                         "seven",
                         "eight",
                         "nine"
                     };
  int a, b,i;
  scanf("%d\n%d", &a, &b);
  for(i=a; i<=b; i++){
    if(i<=9) {
        printf("%s\n",num[i]);
    }
    else{
        if(i%2==0){ 
            printf("%s","even");
        }
        else {
            printf("%s","odd");
        }
        }
    }

  
  return 0;
}