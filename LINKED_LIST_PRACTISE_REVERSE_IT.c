//take a user input linked list and reverse it

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *  next;
} node;

void addatlast(node ** head,int data)
{
    node * temp=(node *) malloc (sizeof(node));
    temp->data=data;
    temp->next=NULL;

    if(*head==NULL)
    {
        *head=temp;
        return;
    }

    node *q=*head;

    while(q->next!=NULL)
    {
        q=q->next;

    }

    q->next=temp;
    return;
}

void reverse(node ** head)
{
    node *q=*head;
    node *p=NULL;
    *head=q->next;
    q->next=NULL;
    while(*head!=NULL)
    {
        p=q;
        q=*head;
        *head=q->next;
        q->next=p;

    }

    *head=q;

}

void display(node ** head)
{
    if(*head==NULL)
    {
        printf("\n\nLIST IS EMPTY\n\n");
        return;
    }

    node *q=*head;
    printf("LIST IS: ");
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}


int main()
{
    printf("\n\n**********************************PROGAM STARTED**********************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL,STUDENT ID:20011990");
    printf("\nGRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");


    node* head=NULL;
    int n;
    printf("Enter number of nodes:");
    scanf("%d",&n);

    printf("\nEnter list:");

    int data,i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        addatlast(&head,data);
    }

    printf("\n****Entered list****\n\n");
    display(&head);

    reverse(&head);

    printf("\n\n****Reversed list****\n\n");
    display(&head);

    printf("\n\n***********************************PROGAM ENDED***********************************\n\n");
    
    return 0;
}