#include <stdio.h>
#define MAX 10

static int read_dimensions(const char *label, int *rows, int *cols) {
    printf("%s (rows columns, 1-%d each): ", label, MAX);
    if (scanf("%d %d", rows, cols) != 2 ||
        *rows < 1 || *rows > MAX || *cols < 1 || *cols > MAX) {
        fprintf(stderr, "Error: dimensions must be between 1 and %d.\n", MAX);
        return 0;
    }
    return 1;
}

static int input(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &mat[i][j]) != 1) {
                fprintf(stderr, "Error: enter integer matrix elements only.\n");
                return 0;
            }
        }
    }
    return 1;
}

static void display(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

static void add(int A[MAX][MAX], int B[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) res[i][j] = A[i][j] + B[i][j];
}

static void multiply(int A[MAX][MAX], int B[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) res[i][j] += A[i][k] * B[k][j];
        }
    }
}

static void transpose(int mat[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) res[j][i] = mat[i][j];
}

int main(void) {
    int A[MAX][MAX] = {{0}}, B[MAX][MAX] = {{0}}, res[MAX][MAX] = {{0}};
    int r1, c1, r2, c2, choice;

    if (!read_dimensions("Matrix A", &r1, &c1)) return 1;
    printf("Enter Matrix A:\n");
    if (!input(A, r1, c1)) return 1;

    printf("Choose operation: 1. Addition  2. Multiplication  3. Transpose of A\nChoice: ");
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Error: enter 1, 2, or 3.\n");
        return 1;
    }

    if (choice == 1 || choice == 2) {
        if (!read_dimensions("Matrix B", &r2, &c2)) return 1;
        printf("Enter Matrix B:\n");
        if (!input(B, r2, c2)) return 1;
    }

    switch (choice) {
        case 1:
            if (r1 != r2 || c1 != c2) {
                fprintf(stderr, "Error: addition requires matrices with equal dimensions.\n");
                return 1;
            }
            add(A, B, res, r1, c1);
            printf("Result (Addition):\n");
            display(res, r1, c1);
            break;
        case 2:
            if (c1 != r2) {
                fprintf(stderr, "Error: multiplication requires columns of A = rows of B.\n");
                return 1;
            }
            multiply(A, B, res, r1, c1, c2);
            printf("Result (Multiplication):\n");
            display(res, r1, c2);
            break;
        case 3:
            transpose(A, res, r1, c1);
            printf("Result (Transpose of A):\n");
            display(res, c1, r1);
            break;
        default:
            fprintf(stderr, "Invalid choice. Use 1, 2, or 3.\n");
            return 1;
    }
    return 0;
}
