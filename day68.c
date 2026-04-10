#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

// Enqueue
void enqueue(int v) {
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front > rear;
}

void kahnTopoSort() {
    // Step 1: Initialize indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Step 2: Calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                indegree[j]++;
            }
        }
    }

    // Step 3: Add nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 4: Process queue
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        // Reduce indegree of adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 5: Check cycle
    if (count != n) {
        printf("\nCycle exists! Topological sort not possible.\n");
    }
}

int main() {
    int m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    kahnTopoSort();

    return 0;
}