#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    printf("Polynomial: ");
    display(head);

    return 0;
}