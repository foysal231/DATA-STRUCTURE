#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void createlist(int x);
void printlist();
void delete_1st();
void delete_middle(int pos);
int count_node();

int main()
{
    int n, pos, count;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter total node: ");
    scanf("%d", &n);
    printf("Data for Node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;

    createlist(n);
    printlist();

    printf("\n");
    delete_1st();
    printlist();

    delete_middle((n - 1) / 2);
    printlist();

    printf("\n");
    count = count_node();
    printf("Total nodes of current link list is %d\n\n", count);
    return 0;
}
void createlist(int x)
{
    struct node *temp, *newnode;
    int i, data;
    temp = head;

    for (i = 2; i <= x; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Data for Node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void printlist()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_1st()
{

    struct node *current;
    current = head;
    head = head->next;
    free(current);
}

void delete_middle(int pos)
{
    int i;
    struct node *temp1 = head;
    struct node *temp2;
    for (i = 2; i <= pos; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

int count_node()
{
    int count = 0;
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

