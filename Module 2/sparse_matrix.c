#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;

Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* transpose(Node* head, int rows, int cols) {
    Node *temp = head, *transposed = NULL;
    while (temp) {
        transposed = insertEnd(transposed, temp->col, temp->row, temp->value);
        temp = temp->next;
    }
    return transposed;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("(%d, %d, %d) ", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* sparseMatrix = NULL;

    sparseMatrix = insertEnd(sparseMatrix, 0, 0, 5);
    sparseMatrix = insertEnd(sparseMatrix, 0, 2, 8);
    sparseMatrix = insertEnd(sparseMatrix, 1, 1, 3);
    sparseMatrix = insertEnd(sparseMatrix, 2, 0, 6);
    
    printf("Original Sparse Matrix: ");
    display(sparseMatrix);

    Node* transposed = transpose(sparseMatrix, 3, 3);
    
    printf("Transposed Sparse Matrix: ");
    display(transposed);

    return 0;
}
