/* This program subtracts two polynomials. */
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

Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node *result = NULL, *temp1 = poly1, *temp2 = poly2;
    do {
        do {
            if (temp1->exp == temp2->exp) {
                result = insertEnd(result, temp1->coeff - temp2->coeff, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
                break;
            } else if (temp1->exp > temp2->exp) {
                result = insertEnd(result, temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            } else {
                result = insertEnd(result, -temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            }
        } while (temp1 && temp2);
    } while (temp1 || temp2);
    return result;
}

void display(Node* head) {
    Node* temp = head;
    do {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next != head) printf("+ ");
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    poly1 = insertEnd(poly1, 3, 2);
    poly1 = insertEnd(poly1, 5, 1);
    poly1 = insertEnd(poly1, 6, 0);

    poly2 = insertEnd(poly2, 4, 2);
    poly2 = insertEnd(poly2, 1, 1);
    poly2 = insertEnd(poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    Node* result = subtractPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
