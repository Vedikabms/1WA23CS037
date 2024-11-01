#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;
typedef struct {
    Queue queue1;
    Queue queue2;
} Stack;

void initQueue(Queue* q);
bool isQueueEmpty(Queue* q);
bool isQueueFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void initStack(Stack* stack);
bool isStackEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->front == -1;
}

bool isQueueFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Error value
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void initStack(Stack* stack) {
    initQueue(&stack->queue1);
    initQueue(&stack->queue2);
}

bool isStackEmpty(Stack* stack) {
    return isQueueEmpty(&stack->queue1);
}

void push(Stack* stack, int value) {
    enqueue(&stack->queue2, value);
    while (!isQueueEmpty(&stack->queue1)) {
        enqueue(&stack->queue2, dequeue(&stack->queue1));
    }
    Queue temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Error value
    }
    return dequeue(&stack->queue1);
}

int peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->queue1.data[stack->queue1.front];
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    if (isStackEmpty(&stack)) {
        printf("Stack is empty.\n");
    }
    return 0;
}
