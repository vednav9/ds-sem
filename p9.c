//Binary Search Tree using Linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left, *right;
} node;
node *root = NULL;
node *Insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}
void preorder(node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void main()
{
    int choice, num;

    while (1)
    {
        printf("\n --------MENU------------\n");
        printf("1\tInsert\n");
        printf("2\tPreorder Display\n");
        printf("3\tInorder Display \n");
        printf("4\tPostorder Display\n");
        printf("5\tExit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your number:");
            scanf("%d", &num);
            root = Insert(root, num);
            break;
            ;
        case 2:
            printf("Pre-Order Display\n");
            preorder(root);
            break;
            ;
        case 3:
            printf("In-Order Display\n");
            inorder(root);
            break;
            ;
        case 4:
            printf("Post-Order Display\n");
            postorder(root);
            break;
            ;
        case 5:
            exit(0);
        default:
            printf("\n ----Wrong Option----\n");
            break;
        }
    }
}
