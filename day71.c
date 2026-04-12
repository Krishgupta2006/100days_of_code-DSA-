#include <stdio.h>

#define EMPTY -1

int table[100];  // hash table

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using Quadratic Probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash Table Full\n");
}

// Search using Quadratic Probing
void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    char op[10];
    int key;

    // Initialize table
    for (int i = 0; i < 100; i++)
        table[i] = EMPTY;

    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {   // INSERT
            insert(key, m);
        } else if (op[0] == 'S') {   // SEARCH
            search(key, m);
        }
    }

    return 0;
}