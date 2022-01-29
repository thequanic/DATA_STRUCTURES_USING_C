//double linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *pre,*next;
}node;

node *head=NULL,*tail=NULL;

void addatlast(int value)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->info=value;
    temp->pre=NULL;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }

    tail->next=temp;
    temp->pre=tail;
    tail=temp;

    
}

void addatbeg(int value)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->info=value;
    temp->pre=NULL;
    temp->next=NULL;

    if(tail==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }

    temp->next=head;
    head->pre=temp;
    head=temp;
    

}

void addafter(int value,int pos)
{
    node*q;
    int i;
    q=head;
    for(i=0;i<pos;i++)
    {
         q=q->link;
         if(q==NULL){printf("THERE ARE LESS THAN %d elements",pos);return 0;}
         
    }
    
    
    node *temp=(node *)malloc(sizeof(node));
    temp->info=value;
    temp->pre=q;
    temp->next=q->next;
    q->next=temp;
    temp->next->pre=temp;




}

void DeleteByValue(int value)
{
     node *q=head;
     while(q!=NULL)
     {
         if(q->info==value)
         {
             q->pre->next=q->next;
             q->next->pre=q->pre;
             free(q);
             return;

         }
         q=q->next;
     }
     printf("Value %d not found in list",value);
}

void DeleteByPosition(int pos)
{
    node *q=head;
    int p=0;
    while(q!=NULL)
    {
          if(p==pos)
          {
             q->pre->next=q->next;
             q->next->pre=q->pre;
             free(q);
             return;
          }
          q=q->next;
          p++;

    }
    printf("Position %d not found in list",pos);
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    node *q=head;
    printf("\nList is: ");
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->next;
    }

}

void search(int value)
{
    int pos=0;
    node *q=NULL;
    while(q!=NULL)
    {
        
    }
}