#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    struct Node *temp = head, *prev = NULL;

    // If head contains key
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

// Function to print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main() {

    int n, key;

    // Input size
    scanf("%d", &n);

    // Create list
    struct Node* head = createList(n);

    // Input key to delete
    scanf("%d", &key);

    // Delete key
    head = deleteKey(head, key);

    // Print updated list
    printList(head);

    return 0;
}