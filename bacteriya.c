#include<stdio.h>
#include<math.h>
int main(){
    int time1,time2;
    int b1,b2;
    printf("Input the time1: ");
    scanf("%d",&time1);
    printf("Input the time2: ");
    scanf("%d",&time2);
    printf("Input the strands1: ");
    scanf("%d",&b1);
    printf("Input the strans2: ");
    scanf("%d",&b2);
    
    int sum = time2-time1;
    double p = 1/(float)(sum); 
    int data = (float)b1/pow((float)sum,p);
    printf("%d\n",data);


    return 0;
}