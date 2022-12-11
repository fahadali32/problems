#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int id;
    int roll;
    char name[1000];
    struct node *next;
};
struct node *head;
void addnode(int id,int roll,char *name){
    struct node *ptr,*temp;                                 
    ptr = (struct node*) malloc(sizeof(struct node*));
    ptr->id = id;
    ptr->roll = roll;
    strcpy(ptr->name,name);
    ptr->next = NULL; //1 index
    if (head == NULL)
    {
        head = ptr;
        temp = ptr;
    }else
    {
        temp->next = ptr;
        temp = ptr;
    }   
}
void addafterthirdNode(int id,int roll,char *name){
    struct node *ptr,*temp,*temp2;
    temp = (struct node*) malloc(sizeof(struct node*));
    //int data = 1;
    if (head != NULL)
    {
        ptr = head;
        while (ptr->next != NULL && ptr->id != 3)
        {    
            ptr = ptr->next;    
        }
        //temp2 = temp->next;
        if (ptr->id == 3)
        {
            temp->id = id;
            temp->roll = roll;
            strcpy(temp->name,name);   
        }
        temp2 = temp;
        temp2->next = ptr->next;
        ptr->next = temp2;
        
        //printf("\n%d\n %d\n",temp2->next->id,temp2->id);
    }
    
}
void deletethirdNode(int val){
    struct node *ptr,*ptr2;
    if (head == NULL)
    {
        printf("nothing to delete");
    }else
    {
        ptr = head;
        while (ptr->next->id != val)
        {
            ptr = ptr->next;
        }
        // printf("%d\n",ptr->next->next->id);
        ptr2 = ptr->next->next;
        ptr->next = NULL;
        ptr->next = ptr2;
        //printf("%d\n",ptr2->id);
    }
    
    
}
void printNode(){
    struct node* ptr;
    ptr = head;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d %d %s \n",ptr->id,ptr->roll,ptr->name);
            ptr = ptr->next;
        }    
    }else
    {
        printf("nai");
    }
}
int main(){
    // addnode(1,11,"Fahad");
    // addnode(2,12,"Ali");
    // addnode(3,13,"Rahi");
    // addnode(5,15,"Fahim");
    // addnode(6,15,"Alif");
    int roll,id;
    char name[256];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&id);
        scanf("%d",&roll);
        scanf("%s",name);
            
    }
    

    addafterthirdNode(4,14,"Kodu");
    printNode();
    deletethirdNode(3);
    printf("\n");
    printNode();
    
    return 0;
}