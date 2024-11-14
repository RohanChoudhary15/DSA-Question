#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

typedef struct {
    int rows;
    int cols;
    int numElements;
    SparseMatrixElement elements[MAX_SIZE];
} SparseMatrix;

void printSparseMatrix(SparseMatrix sm) {
    int k = 0;
    for (int i = 0; i < sm.rows; i++) {
        for (int j = 0; j < sm.cols; j++) {
            if (k < sm.numElements &amp;&amp; sm.elements[k].row == i &amp;&amp; sm.elements[k].col == j) {
                printf("%d ", sm.elements[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

SparseMatrix sparseMatrixTranspose(SparseMatrix sm) {
    SparseMatrix transpose;
    transpose.rows = sm.cols;
    transpose.cols = sm.rows;
    transpose.numElements = sm.numElements;
    for (int i = 0; i < sm.numElements; i++) {
        transpose.elements[i].row = sm.elements[i].col;
        transpose.elements[i].col = sm.elements[i].row;
        transpose.elements[i].value = sm.elements[i].value;
    }
    return transpose;
}

int main() {
    SparseMatrix sm, transpose_sm;
    //Input and processing would go here
    return 0;
}
