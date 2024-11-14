/* This program removes odd coefficients from a polynomial. */
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

Node* removeOddCoefficients(Node* head) {
    Node *temp = head, *prev = NULL;
    do {
        if (temp->coeff % 2 != 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            temp = (prev) ? prev->next : head;
        } else {
            prev = temp;
            temp = temp->next;
        }
    } while (temp != head);
    return head;
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
    Node* poly = NULL;

    poly = insertEnd(poly, 3, 2);
    poly = insertEnd(poly, 4, 1);
    poly = insertEnd(poly, 5, 0);

    printf("Original Polynomial: ");
    display(poly);

    poly = removeOddCoefficients(poly);

    printf("Polynomial After Removing Odd Coefficients: ");
    display(poly);

    return 0;
}
