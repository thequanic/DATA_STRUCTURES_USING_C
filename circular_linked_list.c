/*
Write a C program to create a circular
link list by adding the nodes in right hand side and then print the list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* link;
}node;

void addatlast(node ** last, int data);
void display(node ** last);

int main()
{
    printf("\n\n*********************************PROGRAM STARTED***********************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL, SECTION : N, STUDENT ID:20011990");
    printf("\nCLASS ROLL NUMBER: 31, GRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");

    node *last=NULL;

    int n;
    printf("Enter number of nodes in the linked list:");
    scanf("%d",&n);

    int data;
    printf("Enter data for %d nodes:\n",n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        addatlast(&last,data);
    }

    display(&last);


    printf("\n\n*************************************************************************************\n\n");
    printf("                                   PROGRAM FINISHED                                        ");
    printf("\n\n*************************************************************************************\n\n");
    exit(0);
    return 0;
}

void addatlast(node ** last, int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->info=data;
    temp->link=NULL;

    if(*last==NULL)
    {
        *last=temp;
    }

    temp->link=(*last)->link;
    (*last)->link=temp;
    *last=temp;
}

void display(node ** last)
{
    if(*last==NULL)
    {
        printf("\nLIST IS EMPTY\n");
        return;
    }

    node *q=(*last)->link;
    printf("\nLIST IS:");
    
    while(q!=*last)
    {
        printf("%d ",q->info);
        q=q->link;
    }

    printf("%d\n",q->info);
}