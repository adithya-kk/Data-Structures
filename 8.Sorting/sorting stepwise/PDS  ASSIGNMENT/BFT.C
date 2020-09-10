#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node* left, *right;
};

void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
	printGivenLevel(root, i);
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
	return;
    if (level == 1)
	printf("%d ", root->data);
    else if (level > 1)
    {
	printGivenLevel(root->left, level-1);
	printGivenLevel(root->right, level-1);
    }
}

int height(struct node* node)
{
    if (node==NULL)
	return 0;
    else
    {
	int lheight = height(node->left);
	int rheight = height(node->right);
	if (lheight > rheight)
	    return(lheight+1);
	else return(rheight+1);
    }
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
			malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void main()
{
    struct node *root = newNode(100);
    clrscr();
    root->left        = newNode(90);
    root->right       = newNode(80);
    root->left->left  = newNode(70);
    root->left->right = newNode(60);
    root->right->left = newNode(50);
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    getch();
}