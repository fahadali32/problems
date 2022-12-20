#include<stdio.h>

const int NUM = 31;
int array[20];
void positions(char str[], int n)
{
    for (int i = 0; i < n-1; i++) {
        array[i] = (str[i] & NUM); 
        // printf("%d ",(str[i] & NUM));
    }
}
 
int main()
{
    char str[] = "MY FAVOURIATE FOOD IS";
    int mat1[10][10];
    int n = sizeof(str)/sizeof(str[0]);
    int matSzize;
    scanf("%d",&matSzize);
    int row,column;
    row = (n-1)/matSzize;
    // printf("%d %d %d\n",matSzize,n-1,row);
    int mat2[10][10] = {
        { 1, -1, 1},
        { 1 ,1 , 0},
        {1 , 2, 1}
    };
    positions(str, n);
    
    for (int i = 0; i < matSzize; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat1[i][j] = array[i*row + j];
        }
        
    }
    
    for (int i = 0; i < matSzize; i++) {
        for (int j = 0; j < row; j++) {
        printf("%d ,", mat1[i][j]);
        }
        printf("\n");
    }

    // int temp[matSzize][row];
    // for (int i = 0; i < matSzize; i++) {
    //     for (int j = 0; j < row; j++) {
    //         temp[i][j] = 0;
    //         for (int k = 0; k < matSzize; k++) {
    //             temp[i][j] += mat2[i][k] * mat1[k][j];
    //         }
    //     }
    // }


    // for (int i = 0; i < matSzize; i++) {
    //     for (int j = 0; j < row; j++) {
    //         printf("%d ", temp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\n");
    return 0;
}