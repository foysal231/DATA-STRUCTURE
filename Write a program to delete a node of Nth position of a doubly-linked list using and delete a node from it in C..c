#include <stdio.h>
#include <stdlib.h>

struct node {
   int num;
   struct node * prev;
   struct node * next;
}*head, *last;

void DlListcreation(int n);
void DlListDeleteFirstNode();
void DlListDeleteLastNode();
void DlListDeleteAnyNode(int pos);
void displayDlList(int a);

int main()
{
   int n,num1,a,pos;
   head = NULL;
   last = NULL;

   printf("Number of nodes \n ");
   scanf("%d", &n);
   DlListcreation(n);
   a=1;
   displayDlList(a);
   printf(" Position ( 1 to %d ) to delete a node : ",n);
   scanf("%d", &pos);


if(pos<1 || pos>n)
   {
    printf("\n Invalid position. Try again.\n ");
   }
        if(pos>=1 && pos<=n)
     {

   DlListDeleteAnyNode(pos);
       a=2;
   displayDlList(a);
     }
   return 0;
}
void DlListcreation(int n)
{
   int i, num;
   struct node *newnode;
   if(n >= 1)
   {
       head = (struct node *)malloc(sizeof(struct node));
       if(head != NULL)
       {
           printf("Data for node 1:");
           scanf("%d", &num);
           head->num = num;
           head->prev = NULL;
           head->next = NULL;
           last = head;
           for(i=2; i<=n; i++)
           {
               newnode = (struct node *)malloc(sizeof(struct node));
               if(newnode != NULL)
               {
                   printf("Data for node %d:", i);
                   scanf("%d", &num);
                   newnode->num = num;
                   newnode->prev = last;
                   newnode->next = NULL;
                   last->next = newnode;
                   last = newnode;
               }
               else
               {
                   printf(" Memory can not be allocated.");
                   break;
               }
           }
       }
       else
       {
           printf(" Memory can not be allocated.");
       }
   }
}

void DlListDeleteAnyNode(int pos)
{
   struct node *curNode;
   int i;
   curNode = head;
   for(i=1; i<pos && curNode!=NULL; i++)
   {
       curNode = curNode->next;
   }
   if(pos == 1)
   {
       DlListDeleteFirstNode();
   }
   else if(curNode == last)
   {
       DlListDeleteLastNode();
   }
   else if(curNode != NULL)
   {
       curNode->prev->next = curNode->next;
       curNode->next->prev = curNode->prev;
       free(curNode);
   }
   else
   {
       printf("Position is invalid!\n");
   }
}

void DlListDeleteFirstNode()
{
   struct node * NodeToDel;
   if(head == NULL)
   {
       printf(" Deleting is not possible. No data in the list.\n");
   }
   else
   {
       NodeToDel = head;
       head = head->next;
       head->prev = NULL;
       free(NodeToDel);
   }
}

void DlListDeleteLastNode()
{
   struct node * NodeToDel;
   if(last == NULL)
   {
       printf(" Deleting is not possible. No data in the list.\n");
   }
   else
   {
       NodeToDel = last;
       last = last->prev;
       last->next = NULL;
       free(NodeToDel);
   }
}

void displayDlList(int m)
{
   struct node * tmp;
   int n = 1;
   if(head == NULL)
   {
       printf(" No data found in the List yet.");
   }
   else
   {
       tmp = head;
       if (m==1)
       {
       printf("LINK LIST->");
       }
       else
       {
        printf("\n New list  :\n");
       }
       while(tmp != NULL)
       {
           printf(" node %d-> %d\n", n, tmp->num);
           n++;
           tmp = tmp->next;
       }
   }
}

