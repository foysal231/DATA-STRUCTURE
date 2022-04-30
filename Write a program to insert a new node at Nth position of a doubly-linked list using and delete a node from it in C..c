#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node* prev;
  int data;
  struct node* next;
};

struct node* addToEmpty(struct node* head, int data)
{
  struct node* temp = malloc(sizeof(struct node));

  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;

  head = temp;
  return head;
}

struct node* addAtBeg(struct node* head, int data)
{
  struct node* temp = malloc(sizeof(struct node));

  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;
  temp->next = head;
  head->prev = temp;

  head = temp;
  return head;
}

struct node* addAtEnd(struct node* head, int data)
{
  struct node* temp, * tp;
  temp = malloc(sizeof(struct node));

  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;

  tp = head;
  while (tp->next != NULL)
  {
    tp = tp->next;
  }
  tp->next = temp;
  temp->prev = tp;
  return head;
}

struct node* addAfterPos(struct node* head, int data, int position)
{
  struct node* newP = NULL;
  struct node* temp = head;
  struct node* temp2 = NULL;
  newP = addToEmpty(newP, data);

  while (position != 1)
  {
    temp = temp->next;
    position--;
  }

  if (temp->next == NULL)
  {
    temp->next = newP;
    newP->prev = temp;
  }
  else
  {
    temp2 = temp->next;
    temp->next = newP;
    temp2->prev = newP;
    newP->next = temp2;
    newP->prev = temp;
  }
  return head;
};

struct node* delFirst(struct node* head)
{
  struct node* temp = head;
  head = head->next;
  free(temp);
  return head;
}


struct node* delLast(struct node* head)
{
  struct node* temp = head;
  struct node* temp2;
  while (temp->next != NULL)
    temp = temp->next;
  temp2 = temp->prev;
  temp2->next = NULL;
  free(temp);
  return head;
}


struct node* delInter(struct node* head, int position)
{
  struct node* temp = head;
  struct node* temp2 = NULL;
  if (position == 1)
  {
    head = delFirst(head);
    return head;
  }

  while (position > 1)
  {
    temp = temp->next;
    position--;
  }

  if (temp->next == NULL)
    head = delLast(head);
  else
  {
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    temp = NULL;
  }
  return head;
}

void print(struct node* head)
{
  struct node* ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}


int main()
{
  struct node* head = NULL;
  struct node* ptr;
  int position = 2;
  head = addToEmpty(head, 45);
  head = addAtBeg(head, 25);
  head = addAtEnd(head, 90);
  head = addAfterPos(head, 30, position);

  ptr = head;
  printf("After insertion a new node(30) at position two: ");
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  head = delInter(head, 2);
  printf("\nAfter Deletion a node: ");
  print(head);

  return 0;
}
