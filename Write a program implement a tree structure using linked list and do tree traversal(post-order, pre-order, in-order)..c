#include <stdio.h>
#include <stdlib.h>

struct node
 {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    printf("%d ", node->data);
}
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    printPreorder(node->left);

    printPreorder(node->right);
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%d ", node->data);

    printInorder(node->right);
}


int main()
{
	struct node* root = newNode(14);
	root->left = newNode(2);
	root->right = newNode(11);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(10);
	root->right->right = newNode(30);
	root->right->left->left = newNode(7);
	root->right->right->left = newNode(40);

    printf("\nPOSTORDER TRAVERSAL IS \n");
    printPostorder(root);

    printf("\nPREORDER TRAVERSAL IS \n");
    printPreorder(root);

    printf("\nINORDER TRAVERSAL IS \n");
    printInorder(root);

    getchar();
    return 0;
}
