#include <stdio.h>
int main() {
    int A[10][10], B[10][10], R[10][10];
    int r1, c1, r2, c2, choice;
    printf("Rows & Cols of A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter A:\n");
    for (int i=0;i<r1;i++)
        for (int j=0;j<c1;j++)
            scanf("%d", &A[i][j]);
    printf("Rows & Cols of B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter B:\n");
    for (int i=0;i<r2;i++)
        for (int j=0;j<c2;j++)
            scanf("%d", &B[i][j]);
    printf("\n1.Addition\n2.Multiply\n3.Transpose(A)\nChoice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        if (r1==r2 && c1==c2) {
            for (int i=0;i<r1;i++)
                for (int j=0;j<c1;j++)
                    R[i][j] = A[i][j] + B[i][j];
            printf("\nAddition Result:\n");
            for (int i=0;i<r1;i++) {
                for (int j=0;j<c1;j++) printf("%d ", R[i][j]);
                printf("\n");
            }
        } else printf("Error! Sizes differ.\n");
    }
    else if (choice == 2) {
        if (c1==r2) {
            for (int i=0;i<r1;i++)
                for (int j=0;j<c2;j++) {
                    R[i][j]=0;
                    for (int k=0;k<c1;k++)
                        R[i][j]+=A[i][k]*B[k][j];
                }
            printf("\nMultiplication Result:\n");
            for (int i=0;i<r1;i++) {
                for (int j=0;j<c2;j++) printf("%d ", R[i][j]);
                printf("\n");
            }
        } else printf("Error! Cols of A != Rows of B.\n");
    }
    else if (choice == 3) {
        printf("\nTranspose of A:\n");
        for (int i=0;i<c1;i++) {
            for (int j=0;j<r1;j++)
                printf("%d ", A[j][i]);
            printf("\n");
        }
    }
    else printf("Invalid choice!\n");
    return 0;
}
