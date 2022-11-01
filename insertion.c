#include <stdio.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main() {
  int num,x;
  printf("Please Enter the Number of Elements you want in the array: ");
  scanf("%d", &num);    
  printf("Please Enter the Value of Elements: \n");
  int arr[num];
  for(x = 0; x < num; x++)
    scanf("%d", &arr[x]);
  int size = num;
  insertionSort(arr, size);
  printf("Sorted array in ascending order:\n");
  printArray(arr, size);
}