/* This program removes terms with even exponents from a polynomial. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode->prev = NULL;
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
    newNode->prev = temp;
    return head;
}

Node* removeEvenExponents(Node* head) {
    Node *temp = head;
    while (temp) {
        if (temp->exp % 2 == 0) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            temp = (temp->next) ? temp->next : NULL;
        } else {
            temp = temp->next;
        }
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
    poly = insertEnd(poly, 4, 1);
    poly = insertEnd(poly, 5, 0);

    printf("Original Polynomial: ");
    display(poly);

    poly = removeEvenExponents(poly);

    printf("Polynomial After Removing Even Exponents: ");
    display(poly);

    return 0;
}
