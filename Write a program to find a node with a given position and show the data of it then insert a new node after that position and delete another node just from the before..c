#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* addToEmpty(int data)
{
  struct node* temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->next = temp;
  return temp;
}

struct node* addAtEnd(struct node* tail, int data)
{
  struct node* newP = malloc(sizeof(struct node));
  newP->data = data;
  newP->next = NULL;

  newP->next = tail->next;
  tail->next = newP;
  tail = tail->next;
  return tail;

}

int searchElement(struct node* tail, int element)
{
  struct node* temp;
  int index = 0;

  if (tail == NULL)
    return -2;

  temp = tail->next;
  do {
    if (temp->data == element)
      return index;
    temp = temp->next;
    index++;
  } while (temp != tail->next);
  return -1;
}

struct node* addAfterPos(struct node* tail, int data, int pos)
{
  struct node* p = tail->next;
  struct node* newP = malloc(sizeof(struct node));
  newP->data = data;
  newP->next = NULL;
  while (pos > 1)
  {
    p = p->next;
    pos--;
  }
  newP->next = p->next;
  p->next = newP;
  if (p == tail)
    tail = tail->next;

  return tail;
}


void print(struct node* tail)
{
  if (tail == NULL)
    printf("No node in the list.");
  else
  {
    struct node* p = tail->next;
    do {
      printf("%d ", p->data);
      p = p->next;
    } while (p != tail->next);
  }
  printf("\n");
}


int main()
{
  struct node* tail = NULL;
  int element;
  tail = addToEmpty(34);
  tail = addAtEnd(tail, 45);
  tail = addAtEnd(tail, 66);
  tail = addAtEnd(tail, 6);

  printf("The elements are: ");
  print(tail);
  printf("\nEnter the element you want to search: ");
  scanf("%d", &element);

  int index = searchElement(tail, element);
  if (index == -1)
    printf("Element not found\n");
  else if (index == -2)
    printf("Linked list is empty\n");
  else
    printf("Element %d is at index %d\n", element, index);

  tail = addAfterPos(tail, 61, 3);
  printf("\nAfter adding a data in position three: ");
  print(tail);

  return 0;
}
