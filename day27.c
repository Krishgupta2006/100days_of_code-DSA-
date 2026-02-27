#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
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

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    // Move pointer of longer list ahead
    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse both lists together
    while(ptr1 != NULL && ptr2 != NULL) {

        if(ptr1->data == ptr2->data)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

// Main function
int main() {

    int n, m;

    // First list
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    // Second list
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // Find intersection
    int result = findIntersection(list1, list2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}