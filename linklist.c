#include<stdio.h>
struct Node{
    int value;
    struct Node* next;
};
int printlist(struct Node *data){

    while (data != NULL)
    {
        printf("%d",data->value);
        data = data->next;
    }
    
}
int main(){
    
    return 0;
}