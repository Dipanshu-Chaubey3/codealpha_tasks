#include <stdio.h>
#define MAX 10

void input(int mat[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

void display(int mat[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void add(int A[MAX][MAX], int B[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            res[i][j] = A[i][j] + B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for(int k = 0; k < c1; k++)
                res[i][j] += A[i][k] * B[k][j];
        }
}

void transpose(int mat[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            res[j][i] = mat[i][j];
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter Matrix A:\n");
    input(A, r1, c1);

    printf("Rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter Matrix B:\n");
    input(B, r2, c2);

    printf("\n1. Addition\n2. Multiplication\n3. Transpose (Matrix A)\nChoice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(r1 == r2 && c1 == c2) {
                add(A, B, res, r1, c1);
                printf("\nResult (Addition):\n");
                display(res, r1, c1);
            } else
                printf("Error: Same dimensions required!\n");
            break;

        case 2:
            if(c1 == r2) {
                multiply(A, B, res, r1, c1, c2);
                printf("\nResult (Multiplication):\n");
                display(res, r1, c2);
            } else
                printf("Error: Columns of A must equal rows of B!\n");
            break;

        case 3:
            transpose(A, res, r1, c1);
            printf("\nResult (Transpose of A):\n");
            display(res, c1, r1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
