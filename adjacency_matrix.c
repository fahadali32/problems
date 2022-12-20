#include <stdio.h>
int main()
{
    int edge, node, a, b, i, j;
    printf("Enter Number of Vertices: ");
    scanf("%d", &node);
    int matrix[node][node];
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
        {
            matrix[i][j] = 0;
        }
    }
    printf("Enter Number of Edges: ");
    scanf("%d", &edge);
    printf("Enter Your Edges: ");
    for (i = 0; i < edge; i++)
    {
        scanf("%d%d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    printf("Here is your graph representation :\n");
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}