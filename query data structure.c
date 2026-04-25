#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) printf("Queue Full!\n");
    else {
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if (front == -1) printf("Queue Empty!\n");
    else {
        printf("Removed %d\n", items[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    dequeue(); dequeue();
    return 0;
}
