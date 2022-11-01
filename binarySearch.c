#include<stdio.h>
#include<string.h>

   int binarySearch(char arr[], char x,int l,int n)
	{
		l = 0 ;
		int r = n;
		while (l <= r)
		{
			int m = l + (r - l) / 2;

		if (x == (arr[m]))
			return m;
			
			if (x > (arr[m]))
				l = m + 1;
            else
				r = m - 1;
		}

		return -1;
	}

	int main()
	{
		char arr[100];
		char ch;
        int l = 0;
        printf("Enter the string: \n");
        scanf("%s",arr);
        ch = getchar(); 
        printf("Enter a character: \n");
        scanf("%c",&ch);
      	int n = 4;
		int result = binarySearch(arr,ch,l,n-1);

		if (result == -1)
			printf("Element not present\n");
		else
			printf("Element found at index %d\n",result);
	}
	
