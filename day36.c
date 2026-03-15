#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int n, m, i, x;

    // number of elements
    scanf("%d", &n);

    // enqueue n elements
    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        if(front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }

    // number of dequeues
    scanf("%d", &m);

    // perform m dequeues
    for(i = 0; i < m; i++) {
        if(front != -1) {
            front = (front + 1) % MAX;
        }
    }

    // display queue from front to rear
    i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }

    return 0;
}