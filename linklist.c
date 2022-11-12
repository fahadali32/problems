#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
};
struct Node *head,*tail = NULL;
int printlist(){
    struct Node *current = head;
    if(head == NULL) {  
        printf("List is empty\n");  
    } 
    printf("Nodes of singly linked list: \n");  
    while (current != NULL)
    {
        printf("%d ",current->value);
        current = current->next;
    }
    printf("\n");  
}
int addNode(int data){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }else
    {
        tail->next = newNode;
        tail = newNode;
    }
    
    
}
int main(){

    int num = 0;
    printf("How many node you want to add in the linklist: \n");
    scanf("%d",&num);
    printf("Enter the node: \n");
    for (int i = 0; i < num; i++)
    {
        int data;
        scanf("%d",&data);
        addNode(data);
    }
    printlist();

    return 0;
}
