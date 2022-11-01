#include<stdio.h>
#include<string.h>

int LinearSearch(char arr[],int size,char element){
    if (element == arr[size]){
        return size;
    }else
    {
        return LinearSearch(arr,size-1,element);
    }
    
   return -1;
}
int main(){
    char str[1000], ch;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character: ");
    scanf("%c", &ch);
    int size = strlen(str);
    int indexnum = LinearSearch(str,size,ch);
    if (indexnum != -1)
    {
        printf("Character found at index %c = %d\n", ch, indexnum);    
    }else
    {
        printf("Item not found.\n");    
    }
    
    return 0;
}