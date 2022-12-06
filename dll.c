#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* prev;
    struct node* next;
};
struct node* head;
void beginaddNode(int val){
    struct node* ptr;
    ptr = (struct node*) malloc(sizeof(struct node*));
    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->value = val;
    }else
    {
        ptr->value = val;
        ptr->next = head;
        head = ptr;
    }
    
    
}  
void deletebeginNode(){
    struct node *ptr;
    if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }else
    {
       ptr = head;
       head = ptr->next;
       head->prev = NULL;
       free(ptr); 
    }   
} 
void deletelastNode(){
    struct node* ptr,*ptr2;
    if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr2 = ptr->prev;
            ptr = ptr->next;
        }
        ptr2->next = NULL;
        free(ptr);
        //return head;
    }
    
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
    beginaddNode(1);
    beginaddNode(2);
    beginaddNode(3);
    printNode();
    deletebeginNode();
    printNode();
    deletelastNode();
    printNode();
    return 0;
}