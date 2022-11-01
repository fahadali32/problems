#include<stdio.h>
#include <math.h>

int main(){
    float a,b,c;
    int time;
    printf("input the t: ");
    scanf("%f",&a); 
    printf("input the t0: ");
    scanf("%f",&b);
    printf("input the t100: ");
    scanf("%f",&c); 
    printf("input the time: ");
    scanf("%d",&time);
    float tf = a-b;
    float tt = c-b;
    float tfdiv = tf/tt;
    printf("%.2lf\n",b+(tt*pow(tfdiv,4)));

    return 0;
}
