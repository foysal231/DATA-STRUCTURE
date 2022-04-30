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
void print_linked_list();
void search(int position);
void deletenode(int position);



int main()
{
    int position, value;
    printf("\n Create Linked List\n");
    printf("\n Input a number. (Enter -1 to stop)\n");
    create_linked_list();
    print_linked_list();

    printf("\n enter the position to search \n");
    scanf("%d",&position );
    search(position);

    deletenode(position+2);
    print_linked_list();
    deletenode(position);
    print_linked_list();

}


void create_linked_list()
{
    int val;

    while(1)
    {

        scanf("%d", &val);

        if(val==-1)
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

    //For the 1st element
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

void print_linked_list()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
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

void deletenode(int position)
{
    int i;
    struct linked_list *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
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

            printf("\n SUCCESSFULLY DELETED NODE \n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}
