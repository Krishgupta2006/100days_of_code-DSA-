#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to search in BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;   // Not found

    if (root->data == key)
        return 1;   // Found

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input BST elements
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input key to search
    printf("Enter key to search: ");
    scanf("%d", &key);

    // Search operation
    if (search(root, key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}