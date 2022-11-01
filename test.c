#include<stdio.h>
int binarrySearch(int array[], int low, int high, int x) {
  while (low <= high){
    int mid = low + (high - low) / 2;
    if (array[mid] == x)
        return mid;
    if (array[mid] < x)
        low = mid + 1;
    else
        high = mid - 1;
  }
  
  return -1;
}
int main(){
    int size,i,sample;
    printf("input the size:\n");
    scanf("%d",&size);
    int data[size];
    for (int i = 0; i < size; i++)
    {
        int num;
        scanf("%d",&num);
        data[i] = num;    
    }
    printf("input the sample:\n");
    scanf("%d",&sample);
    
    int begin = 0;
    int result = binarrySearch(data,begin,size-1,sample);
    if (result != -1)
    {
        printf("fount the index :%d\n",result);
    }else
    {
        printf("item not found %d\n",result);
    }
    
    return 0;
}