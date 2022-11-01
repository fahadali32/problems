#include<stdio.h>
void bubleSort(int a[],int s){
	for (int i = 0; i < s-1; i++)
	{
		for (int j = 0; j < s-1; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}	
		}	
	}	
}

int selectionSort(int a[],int s){
	for (int i = 0; i < s-1; i++)
	{
		int min = i;
		for (int j = i; j < s-1; j++)
		{
			if (a[j+1] < a[min])
			{
				min = i;
				int temp = a[min];
				a[min] = a[j+1];
				a[j+1] = temp;
			}	
		}
	}
	
}

int main(){
	int num,size,arr[100];
	scanf("%d",&size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d",&num);
		arr[i] = num;
	}
	//bubleSort(arr,size);
	selectionSort(arr,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}