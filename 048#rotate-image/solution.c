void rotate4(int *a, int *b, int *c, int *d) {
    int t = *d;
    *d = *c;
    *c = *b;
    *b = *a;
    *a = t;
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize <= 1) return;
    int i,j;
    for (i = 0; i < (matrixRowSize >> 1); i++) {
        for (j = 0; j - (matrixRowSize & 1) < (matrixRowSize >> 1); j++) {
            rotate4(&matrix[i][j], &matrix[j][matrixRowSize-i-1], &matrix[matrixRowSize-i-1][matrixRowSize-j-1], &matrix[matrixRowSize-j-1][i]);
        }
    }
}