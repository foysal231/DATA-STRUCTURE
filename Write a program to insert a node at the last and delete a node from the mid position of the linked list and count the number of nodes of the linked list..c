#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node *next ;
}
*start ;

void createList (int n)
{
    struct node *newNode, *temp ;
    int data, i ;

    start=(struct node *) malloc (sizeof(struct node)) ;

    if(start == NULL)
    {
        printf("Error! unable to allocate") ;
    }
    else
    {
        printf("Enter the data of node 1: ") ;

        scanf("%d", &data) ;

        start->data=data ;

        start->next=NULL ;

        temp=start ;

        for(i=2; i<=n; i++)
        {
            newNode=(struct node *)malloc(sizeof(struct node)) ;

            if(newNode == NULL)
            {
                printf("Error! unable to allocate.") ;
                break ;
            }
            else
            {
                printf("Enter the data of node %d: ", i) ;

                scanf("%d", &data) ;

                newNode->data=data ;

                newNode->next=NULL ;

                temp->next=newNode ;

                temp=temp->next;
            }
        }
    }
}

void deleteposition(int position)
{
    struct node *ptr=start ;
    int count=1 ;
    if(position==1)
    {
       if(start==NULL)
    {
        return ;
    }
    start=start->next ;
        return ;
    }
    while(ptr->next!=NULL)
    {
        if(count+1==position)
        {
            break ;
        }
        count++ ;
        ptr=ptr->next ;
    }
    if(count!=position && ptr->next==NULL)
    {
        printf("position not found\n") ;
        return ;
    }
    struct node *del ;
    del=ptr->next ;
    if(del->next==NULL)
    {
        ptr->next=NULL ;
    }
    else
    {
        ptr->next=ptr->next->next ;
    }
    free(del);

}

void insertatlast(int value)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node)) ;
    ptr->data=value ;
    ptr->next=NULL ;

    struct node* temp=start ;

    if(start==NULL)
    {
        start=ptr ;
        return ;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next ;
    }
    temp->next=ptr ;
}

int count()
{
    int count=0 ;

    struct node *temp ;

    temp=start ;

    while(temp != NULL)
    {
        count++ ;
        temp=temp->next ;
    }

    return count ;
}
void displayList()
{
    struct node *temp ;

    if(start == NULL)
    {
        printf("List is empty.") ;
    }
    else
    {
        temp=start ;
        while(temp != NULL)
        {
            printf("%d-> ", temp->data) ;
            temp=temp->next ;
        }
        printf("NULL\n") ;
    }
}

int main ()
{
    int n, node ;

    printf("number of node: ") ;
    scanf("%d", &n) ;
    createList(n) ;

    printf("\ndata:\n") ;
    displayList();

    node=count();
    printf("We have %d node\n",node) ;

    int x;
    printf("Enter the value to insert in last: ") ;
    scanf("%d",&x) ;

    printf("\nAfter Insert\n") ;
    insertatlast(x) ;
    displayList() ;
    node=count() ;
    printf("After delete, %d node\n",node) ;

    printf("\nAfter Delete\n") ;
    int position ;
    position=count()/2 ;
    deleteposition(position) ;
    displayList() ;
    node=count() ;
    printf("After delete, %d node\n",node) ;
    return 0 ;
}
