#include<stdio.h>
#include<math.h>
int main(){
    float con_time;
    int time1,time2,grams1,grams2;
    printf("Input the converted time (Hours): ");
    scanf("%f",&con_time);
    printf("Input the time (Min): ");
    scanf("%d",&time1);
    printf("Input the converted time (Min): ");
    scanf("%d",&time2);
    printf("Input the grams of juice: ");
    scanf("%d",&grams1);
    printf("Input the grams of converted juice: ");
    scanf("%d",&grams2);

    int res_time = con_time*60;
    int sum = grams1-grams2;
    float p = (1/(float)time2)*(float)res_time;
    float div_grams = ((float)sum/(float)grams1);
    float final = (float)grams1-((float)grams1*pow(div_grams,p));

    printf("The amout converted in %.1f hours is: %.4f\n",con_time,final);
    return 0;
}