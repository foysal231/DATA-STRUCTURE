#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL, *last=NULL;
void create_linked_list();
void insert_at_last(int value);
void search(int position);
void deletenode(int position);
void insertatdeleteposition(int value, int position);
void print_linked_list();


int main()
{
    int position, value;

    printf("\n Create Linked List\n");

    printf("\n Input a number. (Enter 0 to stop)\n");

    create_linked_list();

    print_linked_list();

    printf("\n enter the position to search \n");

    scanf("%d",&position );

    search(position);

    printf("\n enter the value to insert at %d position \n",position);

    scanf("%d",&value );

    deletenode(position );

    insertatdeleteposition(value, position);

    print_linked_list();

}

void create_linked_list()
{
    int val;

    while(1)
    {

        scanf("%d", &val);

        if(val==0)
        break;

        insert_at_last(val);
    }

}

void insert_at_last(int value)
{
    node *temp_node;

    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;

    temp_node->next=NULL;

    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }

}

void search(int position)
{
    int c = 0;

    struct linked_list *temp;

    temp = head;

    while(c != position)
    {
        c++;
        temp = temp->next;
    }
    printf("%d is present in %d position",temp->number, position);

}

void deletenode(int position )
{
    int i;

    struct linked_list *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("\n List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position ; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)

            head = head->next;

            prevNode->next = toDelete->next;

            toDelete->next = NULL;

            free(toDelete);

            printf("\n \n SUCCESSFULLY DELETED NODE FROM %d position\n",position );
        }
        else
        {
            printf("\n Invalid position  unable to delete.");
        }
    }
}

void insertatdeleteposition(int value, int position)
{
    int i;

    struct linked_list *newNode, *temp;

    newNode = (struct linked_list*)malloc(sizeof(struct linked_list));

    if(newNode == NULL)
    {
        printf("\n Unable to allocate memory.");
    }
    else
    {
        newNode->number = value;
        newNode->next = NULL;
        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
            break;
        }

        if(temp != NULL)
        {
            newNode->next = temp->next;

            temp->next = newNode;

            printf("\n value INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("\n UNABLE TO INSERT value AT THE GIVEN POSITION\n");
        }
    }
}

void print_linked_list()
{
    printf("\n \nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf(" %d ", myList->number);

        myList = myList->next;
    }
    puts("");
}
