#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main()
{
// coefficients of the system of linear equations
float a[SIZE][SIZE] = {{1, 1, 1}, {1, 2, 4}, {1, 3, 9}};
// constants on the right-hand side
float b[SIZE] = {4, 6, 12};


// number of unknowns
int n = SIZE;

int i, j, k;
float ratio;

// perform row operations to transform matrix into upper triangular form
for (i = 0; i < n - 1; i++)
{
    // check for zero on main diagonal
    if (a[i][i] == 0.0)
    {
        printf("Mathematical Error!");
        exit(0);
    }

    for (j = i + 1; j < n; j++)
    {
        ratio = a[j][i] / a[i][i];
        for (k = i; k < n; k++)
        {
            a[j][k] = a[j][k] - ratio * a[i][k];
        }
        b[j] = b[j] - ratio * b[i];
    }
}

// solve for unknowns using back substitution
float x[SIZE];
x[n - 1] = b[n - 1] / a[n - 1][n - 1];
for (i = n - 2; i >= 0; i--)
{
    x[i] = b[i];
    for (j = i + 1; j < n; j++)
    {
        x[i] = x[i] - a[i][j] * x[j];
    }
    x[i] = x[i] / a[i][i];
}

// print solutions
printf("Solution:\n");
for (i = 0; i < n; i++)
{
    printf("x[%d] = %0.3f\n", i, x[i]);
}

return 0;
}