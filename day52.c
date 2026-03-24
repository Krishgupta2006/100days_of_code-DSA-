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

// Build tree from level order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    // If both sides found → this is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-null
    return (left != NULL) ? left : right;
}

int main() {
    int n, i, p, q;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n, 0);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}