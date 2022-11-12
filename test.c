#include<stdio.h>
int data(int n)
{
    if(n != 0){
        data(n-1);
        printf("%d",n);
    }
}
int main(){
    data(3);
    printf("\n");
    return 0;
}