#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head,*tail = NULL; 
  
void addNode(); 
void insertNode(int data);  
void randominsert();  
void size();  
void search();  
void main ()  
{  
    int choice =0;  
    while(choice != 9)   
    {  
        printf("\n\tMain Menu\t\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n                                              \n");  
        printf("\n1.Insert data\n2.Search for an element\n3.Size of the link list\n4.Insert element in specefic position");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            addNode();      
            break;  
            case 2:  
            search();
            break;  
            case 3:  
            size();              
            break;  
            case 4:  
            randominsert();
            break;  
            default:  
            printf("Please enter valid choice: ");  
        }  
    }  
}  
void addNode(){
    int num = 0;
    printf("How many node you want to add in the linklist: \n");
    scanf("%d",&num);
    printf("Enter the node: \n");
    for (int i = 0; i < num; i++)
    {
        int data;
        scanf("%d",&data);
        insertNode(data);
    }
    
    
}
void insertNode(int data){
    struct node *ptr;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
    }else
    {
        tail->next = ptr;
        tail = ptr;
    }
}
void randominsert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode inserted");  
    }  
}  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
}  
  
void size()  
{  
    struct node *ptr;  
    ptr = head;
    int num = 0;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting size\n");   
        while (ptr!=NULL)  
        {  
            num += 1;
            ptr = ptr -> next;  
        }
        printf("%d",num);  
    }  
}     
              