#include<stdio.h>
int top = -1; 
int stack[5];
int push(){
    if (top == 4)
    {
        printf("overflow");
    }else
    {
        int x;
        printf("Enter element to be pushed into the stack: ");
        scanf("%d", &x);
        top+=1;
        stack[top] = x;
    }
    
    
}
int main(){
    push();
    for (int i = 0; i < 4; i++)
    {
        printf("%d",stack[i]);
    }
    
    return 0;
}