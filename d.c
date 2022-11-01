#include<stdio.h>
int findEle(int array[],int size, int elementToDelete){
	for(int i = 0;i < size; i++){
	   if(array[i] == elementToDelete){
        return i;
       }
	}
    return -1;
  }

int deleteElement(int array[], int size, int elementToDelete){
	int position = findEle(array,size,elementToDelete);
    if(position==-1)
        printf("Element not found");
        int i;
        for(i=position;i<size-1;i++)
            array[i] = array[i+1];
            return size-1;
}

int main()
{
    int array[]={20, 31, 55, 98, 3, 45, 5, 90};
    int size = sizeof(array)/sizeof(array[0]);
    int i;
    int elementToDelete = 0;
    scanf("%d",&elementToDelete);
    printf("\nb4 ins: ");
    for(i=0;i<size;i++){
        printf("%d ", array[i]);
    }
  	size = deleteElement(array,size,elementToDelete);
  printf("\nAfter ins: ");
   for(i=0;i<=size-1;i++){
        printf("%d ", array[i]);
    }
    

    return 0;
}
