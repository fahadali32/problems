#include <stdio.h>
int LinearSearch(char arr[],char element){
   for (int i = 0; arr[i] != '\0'; ++i) {
        if (element == arr[i]){
            return i;
        }  
   }
   return -1;
}
int main() {
    char str[1000], ch;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character: ");
    scanf("%c", &ch);
    
    int indexnum = LinearSearch(str,ch);
    if (indexnum != -1)
    {
        printf("Character found at index %c = %d\n", ch, indexnum);    
    }else
    {
        printf("Item not found.\n");    
    }
    
    return 0;
}
