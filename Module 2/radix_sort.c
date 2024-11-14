#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int getMax(Node* head) {
    int max = head->data;
    Node* temp = head;
    while (temp) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void countingSort(Node** head, int exp) {
    Node *output = NULL;
    int count[10] = {0};
    Node* temp = *head;

    while (temp) {
        count[(temp->data / exp) % 10]++;
        temp = temp->next;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    temp = *head;
    while (temp) {
        int digit = (temp->data / exp) % 10;
        Node* newNode = createNode(temp->data);
        if (!output) {
            output = newNode;
        } else {
            Node* tail = output;
            while (tail->next) tail = tail->next;
            tail->next = newNode;
        }
        count[digit]--;
        temp = temp->next;
    }

    *head = output;
}

void radixSort(Node** head) {
    int max = getMax(*head);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(head, exp);
    }
}


void display(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* list = NULL;

    insertEnd(&list, 170);
    insertEnd(&list, 45);
    insertEnd(&list, 75);
    insertEnd(&list, 90);
    insertEnd(&list, 802);
    insertEnd(&list, 24);
    insertEnd(&list, 2);
    insertEnd(&list, 66);

    printf("Original List: ");
    display(list);

    radixSort(&list);

    printf("Sorted List: ");
    display(list);

    return 0;
}
