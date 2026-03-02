#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    // find last node and length
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // make circular
    temp->next = head;

    // effective rotations
    k = k % length;

    int steps = length - k;

    temp = head;

    // move to new last node
    for(int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // new head
    head = temp->next;

    // break circle
    temp->next = NULL;

    return head;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {

    int n, k;

    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}