/* This program computes the indefinite integral of a polynomial. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
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

Node* integrate(Node* head) {
    Node* temp = head;
    while (temp) {
        temp->exp++;
        temp->coeff /= temp->exp;
        temp = temp->next;
    }
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next) printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* poly = NULL;

    poly = insertEnd(poly, 3, 2);
    poly = insertEnd(poly, 5, 1);
    poly = insertEnd(poly, 6, 0);

    printf("Original Polynomial: ");
    display(poly);

    poly = integrate(poly);

    printf("Integrated Polynomial: ");
    display(poly);

    return 0;
}
