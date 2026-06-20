#include <stdio.h>

int main() {
    int a[10][10], rows, cols;
    int i, j, flag = 1;

   
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    
    if (rows != cols) {
        printf("Matrix is not symmetric (not square).\n");
        return 0;
    }

    
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (a[i][j] != a[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag)
        printf("Matrix is symmetric.\n");
    else
        printf("Matrix is not symmetric.\n");

    return 0;
}
