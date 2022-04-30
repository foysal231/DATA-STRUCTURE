#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right_child;
    struct node *left_child;
};


struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{

    if(root==NULL)

    return new_node(x);

    else if(x>root->data)

    root->right_child = insert(root->right_child, x);

    else

    root->left_child = insert(root->left_child,x);

    return root;
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left_child);

    printf("%d ", node->data);

    printInorder(node->right_child);
}

int main()
{
    struct node *root;
    root = new_node(20);
    insert(root,30);
    insert(root,12);
    insert(root,15);
    insert(root,13);
    printInorder(root);
    printf("\n");
    return 0;
}
