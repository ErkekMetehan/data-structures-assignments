#include <stdio.h>

int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int row = 4, col = 5;
    int size = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }
    int sparseMatrix[size][3];
    int k = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Satir\tSutun\tDeger\n");
    printf("----- ----- -----\n");
    for (int i = 0; i < size; i++) {
        printf("%4d %4d %4d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}
