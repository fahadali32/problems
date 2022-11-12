#include<stdio.h>
void toh(int n,char beg,char aux,char end){
    if (n >= 1)
    {
        toh(n-1,beg,end,aux);
        printf("%d Disk move %c to %c\n",n,beg,end);
        toh(n-1,aux,beg,end);
    }
}
int main(){
    int num;
    printf("How many disk you want to add: \n");
    scanf("%d",&num);
    toh(num,'A','B','c');
    return 0;
}