#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char* str;
    str = (char *)malloc(sizeof(char) *1024);
    scanf("%s",str);
    //printf("%s",str);
    int count = 0;
    int len = sizeof(str)/sizeof(str[0]);
    for(int i = 0; i < strlen(str); i++) {  
        count = 1;  
        for(int j = i+1; j < strlen(str); j++) {  
            if(str[i] == str[j] && str[i] != ' ') {  
                count++;  
                str[j] = '0';  
            }  
        }  
        if(count > 1 && str[i] != '0')  
            printf("%c\n", str[i]);  
    }  
    return 0;
}