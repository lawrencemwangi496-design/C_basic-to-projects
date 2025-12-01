#include <stdio.h>

int main() {
    int rows, cols;

    // Ask user for size of the array
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int a[10][10]; // max size 10x10 (you can adjust)

    // Input values from user
    printf("\nEnter elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Print the array in matrix form
    printf("\nThe 2D array is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", a[i][j]); // %4d creates spacing
        }
        printf("\n"); // move to next row
    }

    return 0;
}
