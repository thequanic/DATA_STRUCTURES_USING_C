/*
Write a C Program to create  singly linked list by adding nodes in the right hand side and
 delete alternate node from the list and then print  the final list.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{int info; struct node* link;}node;

void addatlast(node **start,int data);
int del_next_node(node *q);
int del_alter_nodes(node **start);
int display(node **start);

int main()
{
    printf("\n\n**********************************PROGAM STARTED**********************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL,STUDENT ID:20011990");
    printf("\nGRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");

    node*start=NULL;


    int n;
    printf("Enter number of nodes:");
    scanf("%d",&n);

    printf("Enter data elements for %d nodes:: (except -1)::",n);
    int i,data;
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        addatlast(&start,data);
    }

    printf("\nLIST CREATED....\n");
    if( del_alter_nodes(&start)!=-1)
    {
        printf("DELETING ALTERNATIVE NODES....\n\n");
    }

    display(&start);


    printf("\n\n***********************************PROGAM ENDED***********************************\n\n");
    

    return 0;
}

void addatlast(node **start, int data)
{
      node *q,*temp=malloc(sizeof(node));
      temp->info=data;
      temp->link=NULL;
      if(*start==NULL){*start=temp;}
      else
      {
          q=*start;
          while(q->link!=NULL){q=q->link;}
          q->link=temp;
      }

}

int del_next_node(node *q)
{
    if(q==NULL || q->link==NULL )
    {
        return -1;

    }

    node *temp=q->link;
    q->link=temp->link;
    int value=temp->info;
    free(temp);
    return value;

}


int del_alter_nodes(node **start)
{
    if(*start==NULL)
    {
        return -1;
    }
    node*q=*start;
    while(1)
    {
        int value=del_next_node(q);
        if(value==-1)
        {
            return 1;
        }
        q=q->link;
    }


}

int display(node **start)
{
    node *q;
    if(*start==NULL)
    {
        printf("LIST IS EMPTY\n");
        return 0;

    }
    q=*start;
    printf("List is:\n");
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->link;
    }
    printf("\n");
}