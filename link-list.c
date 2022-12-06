#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};
struct node *head,*tail = NULL;
void beginaddNode(int val){  
    struct node *ptr,*temp;  
    ptr = (struct node*)malloc(sizeof(struct node));      
    if (head == NULL)
    {
        head = ptr;
        ptr->value = val;
    }else
    {
       ptr->value = val;
       ptr->next = head;
       head = ptr;
    }  
}
void lastaddNode(int val){  
      
    struct node *ptr,*temp;  
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        ptr->value = val;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            
        }  
    }
}
void deletebeginNode(){
    struct node *ptr;
    if (head == NULL) 
    {
        printf("cant delete ");
    }else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
    }   
}
void deletelastNode(){
    struct node* temp = head;
    struct node* previous; 
    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }else
    {
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        previous->next = NULL;
        //printf("%d deleted\n", temp->value);
        free(temp);
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
    lastaddNode(2);
    lastaddNode(3);
    printNode();
    deletebeginNode();
    printNode();
    deletelastNode();
    printNode();
    return 0;
}