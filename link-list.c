#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};
struct node *head = NULL;
void addNode(int val){
    struct node* temp = (struct node*) malloc(sizeof(struct node*)); 
    head = temp;
    temp->value = val;
    temp = temp->next;
}
void printNode(){
    struct node* ptr;
    ptr = head;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ",ptr->value);
            ptr = ptr->next;
        }    
    }else
    {
        printf("nai");
    }
    printf("\n");
    
}
int main(){
    addNode(1);
    addNode(2);
    addNode(3);
    printNode();
    return 0;
}