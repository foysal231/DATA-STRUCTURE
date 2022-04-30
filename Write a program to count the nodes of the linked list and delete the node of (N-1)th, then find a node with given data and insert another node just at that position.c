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
int countNodes();
void delete_before_last_node(int position );
void search_number(int key);
void insert_at_the_position(int key, int value);

int main()
{
    int key, value, position;

    printf("Create Linked List\n");

    printf("Input a number. (Enter -1 to stop)\n");

    create_linked_list();

    print_linked_list();

    printf("\n number of nodes %d \n",countNodes());

    position=countNodes()-1;

    delete_before_last_node( position );

    printf("\nEnter the data to search it from List\n");

    scanf("%d", &key);

    search_number(key);

    printf("\nInsert new number at %d data's position \n", key);

    scanf("%d", &value);

    insert_at_the_position( key,  value);

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

int countNodes()
{
    int count = 0;

    struct linked_list *temp;

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void delete_before_last_node(int position )
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

            printf("\n \n SUCCESSFULLY DELETED %d th NODE \n",position );
        }
        else
        {
            printf("\n Invalid position  unable to delete.");
        }
    }
}

void search_number(int key)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)

    {
        if(searchNode->number==key)
        {
            printf("%d is present in this list. Memory address is %d\n", key, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)

    printf("Item not found\n");

}

void insert_at_the_position(int key, int value)
{
    node *myNode = NULL;
    node *temp = head;
    int flag = 0;

    while(temp!=NULL)
    {
        if(temp->next->number==key)
        {
            node *newNode = (node *) malloc(sizeof(node));

            newNode->number = value;

            newNode->next = temp->next;

            temp->next = newNode;

            printf("%d is inserted \n", value);

            flag = 1;


            break;
        }
        else
            temp = temp->next;
    }

    if(flag==0)

    printf("Key not found!\n");

}
