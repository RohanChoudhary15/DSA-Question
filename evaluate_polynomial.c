/* This program evaluates a polynomial at a given point. */
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
    newNode->next = newNode;
    return newNode;
}

Node* insertEnd(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

double evaluatePolynomial(Node* head, double x) {
    double result = 0.0;
    Node* temp = head;
    do {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    } while (temp != head);
    return result;
}

int main() {
    Node* poly = NULL;

    poly = insertEnd(poly, 3, 2);
    poly = insertEnd(poly, -5, 1);
    poly = insertEnd(poly, 6, 0);

    double x = 2.0;
    double result = evaluatePolynomial(poly, x);

    printf("Polynomial evaluated at x = %.2f: %.2f\n", x, result);

    return 0;
}
