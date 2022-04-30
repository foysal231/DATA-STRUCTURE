#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL, *front = NULL, *rear = NULL;

void push(int);
void pop();
void enqueue(int value);
void dequeue();
void stack_display();
void queue_display();

int main()
{
    int choice, stack_value, queue_value;

    while (1)
    {
        printf("\n\t\tMENU\n");
        printf("1. Push\n2. Pop\n3. Enqueue\n4. Dequeue\n5. Stack Display\n6. Queue Display\n7. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data for Stack: ");
            scanf("%d", &stack_value);
            push(stack_value);
            break;

        case 2:
            pop();
            break;

        case 3:
            printf("\nEnter data for Queue: ");
            scanf("%d", &queue_value);
            enqueue(queue_value);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            printf("Stack Display\n");
            stack_display();
            break;
        case 6:
            printf("Queue Display\n");
            queue_display();
            break;

        case 7:
            exit(0);
        default:
            printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is Empty!\n");
    }
    else
    {
        struct Node *temp = top;
        printf("\nDeleted element: %d\n", temp->data);
        top = temp->next;
        free(temp);
        printf("Delete Successful!\n");
    }
}

void enqueue(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Insert Successful!\n");
}
void dequeue()
{
    if (front == NULL)
        printf("\nQueue is Empty!!!\n");
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
        printf("Delete Successful!\n");
    }
}
void stack_display()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void queue_display()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
