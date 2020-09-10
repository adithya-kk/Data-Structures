#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node* next;
};

struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = newNode(new_data);

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

long multiplyTwoLists (struct node* first, struct node* second)
{
    int num1 = 0, num2 = 0;
    while (first || second)
    {
	if(first){
	    num1 = num1*10 + first->data;
	    first = first->next;
	}
	if(second)
	{
	    num2 = num2*10 + second->data;
	    second = second->next;
	}
    }


    return num1*num2;
}

void printList(struct node *node)
{
    while(node != NULL)
    {
	printf("%d ", node->data);
	node = node->next;
    }
    printf("\n");
}

void main(void)
{
    struct node* first = NULL;
    struct node* second = NULL;
    clrscr();
    //In Reverse Order
    push(&first, 4);
    push(&first, 4);
    push(&first, 1);
    printf("First List is ");
    printList(first);

    push(&second, 4);
    push(&second, 1);
    printf("Second List is ");
    printList(second);

    printf("Result is ");
    printf("%d", multiplyTwoLists(first, second));

    getch();
}