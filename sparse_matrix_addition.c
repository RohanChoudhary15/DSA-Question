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

SparseMatrix sparseMatrixAddition(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    result.rows = sm1.rows;
    result.cols = sm1.cols;
    result.numElements = 0;
    int i = 0, j = 0, k = 0;
    while (i < sm1.numElements &amp;&amp; j < sm2.numElements) {
        if (sm1.elements[i].row == sm2.elements[j].row &amp;&amp; sm1.elements[i].col == sm2.elements[j].col) {
            result.elements[k].row = sm1.elements[i].row;
            result.elements[k].col = sm1.elements[i].col;
            result.elements[k].value = sm1.elements[i].value + sm2.elements[j].value;
            i++;
            j++;
        } else if (sm1.elements[i].row < sm2.elements[j].row || (sm1.elements[i].row == sm2.elements[j].row &amp;&amp; sm1.elements[i].col < sm2.elements[j].col)) {
            result.elements[k] = sm1.elements[i];
            i++;
        } else {
            result.elements[k] = sm2.elements[j];
            j++;
        }
        k++;
        result.numElements++;
    }
    while (i < sm1.numElements) {
        result.elements[k++] = sm1.elements[i++];
        result.numElements++;
    }
    while (j < sm2.numElements) {
        result.elements[k++] = sm2.elements[j++];
        result.numElements++;
    }
    return result;
}

int main() {
    SparseMatrix sm1, sm2, sum;
    //Input and processing would go here
    return 0;
}
