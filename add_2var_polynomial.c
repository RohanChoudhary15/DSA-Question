#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int x_exp, y_exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int x_exp, int y_exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->x_exp = x_exp;
    newNode->y_exp = y_exp;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int coeff, int x_exp, int y_exp) {
    Node* newNode = createNode(coeff, x_exp, y_exp);
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

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node *result = NULL, *temp1 = poly1, *temp2 = poly2;
    while (temp1 && temp2) {
        if (temp1->x_exp == temp2->x_exp && temp1->y_exp == temp2->y_exp) {
            result = insertEnd(result, temp1->coeff + temp2->coeff, temp1->x_exp, temp1->y_exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->x_exp > temp2->x_exp || (temp1->x_exp == temp2->x_exp && temp1->y_exp > temp2->y_exp)) {
            result = insertEnd(result, temp1->coeff, temp1->x_exp, temp1->y_exp);
            temp1 = temp1->next;
        } else {
            result = insertEnd(result, temp2->coeff, temp2->x_exp, temp2->y_exp);
            temp2 = temp2->next;
        }
    }
    while (temp1) {
        result = insertEnd(result, temp1->coeff, temp1->x_exp, temp1->y_exp);
        temp1 = temp1->next;
    }
    while (temp2) {
        result = insertEnd(result, temp2->coeff, temp2->x_exp, temp2->y_exp);
        temp2 = temp2->next;
    }
    return result;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%dx^%d y^%d ", temp->coeff, temp->x_exp, temp->y_exp);
        if (temp->next) printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    poly1 = insertEnd(poly1, 3, 2, 1);
    poly1 = insertEnd(poly1, 5, 1, 2);
    poly1 = insertEnd(poly1, 6, 0, 0);

    poly2 = insertEnd(poly2, 4, 2, 1);
    poly2 = insertEnd(poly2, 1, 1, 2);
    poly2 = insertEnd(poly2, 2, 0, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
