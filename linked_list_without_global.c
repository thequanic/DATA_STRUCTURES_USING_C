#include<stdio.h>
#include<stdlib.h>

typedef struct node{int info; struct node* link;}node;

void addatlast(node **start,int data);
void addatbeg(node **start,int data);
int addafter(node **start,int data, int pos);
int del_node(node **start,int data);
int display(node **start);
int search(node **start, int data);
void reverse(node **start);

int main()
{
     int choice,n,m,pos,i;
     node *start=NULL;
     while(1)
     {
         
         printf("\n_________________________________________________________________________________\n\n");
         printf("1.CREATE LIST\n");
         printf("2.ADD AT BEGINING\n");
         printf("3.ADD AT LAST\n");
         printf("4.ADD AFTER\n");
         printf("5.DELETE\n");
         printf("6.DISPLAY\n");
         printf("7.SEARCH\n");
         printf("8.REVERSE LIST\n");
         printf("9.QUIT\n");
         printf("_________________________________________________________________________________\n\n");
         printf("Enter your choice:");
         scanf("%d",&choice);
         switch (choice)
         {
             case 1:
             {
                 printf("HOW MANY NODES YOU WANT:");
                 scanf("%d",&n);
                 for(i=0;i<n;i++)
                 {
                     printf("Enter the element:");
                     scanf("%d",&m);
                     addatlast(&start,m);
                 }
                 break;
             }
             case 2:
             {
                 printf("Enter the element:");
                 scanf("%d",&m);
                 addatbeg(&start,m);
                 break;
             }
             case 3:
             {
                 printf("Enter the element:");
                 scanf("%d",&m);
                 addatlast(&start,m);
                 break;
             }
             case 4:
             {
                 printf("Enter the element:");
                 scanf("%d",&m);
                 printf("Enter the position after which this element is inserted:");
                 scanf("%d",&pos);
                 addafter(&start,m,pos);
                 break;
             }
             case 5:
             {
                 if(start==NULL){printf("LIST IS EMPTY\n"); continue;}
                 printf("Enter the element for deletion:");
                 scanf("%d",&m);
                 int i=del_node(&start,m);
                 printf("Element %d deleted from list\n",i);
                 break;
             }
             case 6:
             {
                 display(&start);
                 break;
             }
             case 7:
             {
                 printf("Enter the element to be searched:");
                 scanf("%d",&m);
                 search(&start,m);
                 break;
             }
             case 8:
             {
                 reverse(&start);
                 break;
             }
             case 9:
             {
                 exit(0);
             }
             default: printf("WRONG CHOICE\n");
         }
     }
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

void addatbeg(node **start,int data)
{
    node *temp=malloc(sizeof(node));
    temp->info=data;
    if(*start==NULL)
    {
        temp->link=NULL;
        *start=temp;
        return;
    }
    temp->link=*start;
    *start=temp;

}

int addafter(node **start,int data, int pos)
{
     if(*start==NULL)
     {
         printf("\nLIST IS EMPTY.......OPERATION ABORTED\n");
         return 0;
     }
     node *q,*temp;
     int i;
     q=*start;
     for(i=0;i<pos;i++)
     {
         q=q->link;
         if(q==NULL){printf("THERE ARE LESS THAN %d elements",pos);return 0;}
         
     }
     temp=malloc(sizeof(node));
     temp->info=data;
     temp->link=q->link;
     q->link=temp;
}

int del_node(node **start,int data)
{
    node *temp,*q;
    if((*start)->info==data)
    {
        temp=*start;
        *start=(*start)->link;
        int i=temp->info;
        free(temp);
        return i;
    }
    q=*start;
    while(q->link!=NULL)
    {
        if(q->link->info==data)
        {
           temp= q->link;
           q->link=temp->link;
           int i=temp->info;
           free(temp);
           return i;   
        }
        q=q->link;
    }
   
    printf("ELEMENT %d NOT FOUND\n",data);
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

int search(node **start,int data)
{
    node *q=*start;
    int pos=0;
    while(q!=NULL)
    {
        if(q->info==data){printf("Item %d found at position %d\n",data,pos);return 0;}
        q=q->link;
        pos++;
    }
    if(q==NULL)
    {
        printf("ITEM %d NOT FOUND IN LIST \n",data);
    }
}
  
void reverse(node **start)
{
    node *q,*p;
    q=*start;
    *start=q->link;
    q->link=NULL; 
    while(*start!=NULL)
    {
       p=q;
       q=*start;
       *start=q->link;
       q->link=p;
    }
    *start=q;
}
