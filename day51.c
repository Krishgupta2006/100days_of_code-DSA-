#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // If both values are greater → go right
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // Otherwise this is LCA
    return root;
}

int main() {
    int n, i, value, p, q;
    struct Node* root = NULL;

    // Input
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}