#include<stdio.h>
#include<math.h>
int main(){
    int per,inp,pre_yr,ne_yr;
    float x;
    float sum_per,div;
    sum_per = per/100;
    printf("Input the initial population: ");
    scanf("%d",&inp);
    printf("Input the initial percentage: ");
    scanf("%d",&per);
    printf("Input the initial year: ");
    scanf("%d",&pre_yr);
    printf("Input the initial next year: ");
    scanf("%d",&ne_yr);
    sum_per = (float)per/(float)100;
    x = (float)inp+(sum_per*(float)inp);
    div = x/inp;
    int result = inp*(pow(div,((float)ne_yr/(float)pre_yr)));
    printf("total population: %d\n",result);
    
    return 0;
}