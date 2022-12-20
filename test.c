#include <stdio.h>

#define M 3
#define N 7
#define P 3

int main(void) {
    // Declare and initialize matrices a1 and a2
    int a1[M][N] = {{13, 6, 15, 9, 5, 15, 0}, {25, 1, 21, 1, 0, 15, 9}, {0, 22, 18, 20, 6, 4, 19}};
    int a2[P][M] = {{1, -1, 1}, {1, 1, 0}, {1, 2, 1}};


    // Declare matrix a3 to store the result of the multiplication
    int a3[M][N];
    printf("Matrix a1:\n");
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        printf("%d ", a1[i][j]);
    }
    printf("\n");
}

printf("Matrix a2:\n");
for (int i = 0; i < P; i++) {
    for (int j = 0; j < M; j++) {
        printf("%d ", a2[i][j]);
    }
    printf("\n");
}
printf("Matrix a3:\n");
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        printf("%d ", a3[i][j]);
    }
    printf("\n");
}

    // Perform matrix multiplication
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a3[i][j] = 0;
            for (int k = 0; k < P; k++) {
                printf("a %d %d",a1[i][k],i);
                a3[i][j] += a1[i][k] * a2[k][j];
            }
            printf("\n");
        }
    }

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
