#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
} node;

node* front=NULL, *rear=NULL;

void enqueue(int data);
int dequeue();
void display();

int main()
{
    printf("\n\n********************************PROGRAM STARTED**********************************\n\n");
    while(1)
    {
         char*s;
         s="                         OPERATION PERFORMED SUCCESSFULLY                         ";
         printf("\n\n*********************************************************************************\n\n");
         printf("YOU CAN PERFORM FOLLOWING OPERATIONS::\n\n");
         printf("1.ENQUEUE\n");
         printf("2.DEQUEUE\n");
         printf("3.DISPLAY\n");
         printf("4.EXIT\n");
         printf("\nENTER YOUR CHOICE:");
         int choice;
         scanf("%d",&choice);

         switch(choice)
         {
             case 1:
             {
                 int value;
                 printf("Enter value to be inserted:");
                 scanf("%d",&value);
                 enqueue(value);
                 break;
             }

             case 2:
             {
                 int value=dequeue();
                 if(value!=-1)
                 {
                     printf("Deleted value is %d\n",value);
                 }
                 break;
             }

             case 3:
             {
                 display();
                 break;
             }

             case 4:
             {
                 printf("\n\n*********************************PROGRAM ENDED***********************************\n\n");
                 exit(0);
             }
             default:
             {
                 s="                                 INVALID CHOICE";
             }
         
         }
         printf("\n\n*********************************************************************************\n\n");
         printf("%s",s);
    
    }
    return 0;
}

void enqueue(int data)
{
    node*temp=(node*)malloc(sizeof(node));
    temp->info=data;
    temp->next=NULL;
    if(rear==NULL)
    {
        rear=front=temp;
        return;
    }
    rear->next=temp;
    rear=temp;

}

int dequeue()
{
    if(front==NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
        return -1;
    }
    node *temp=front;
    int value=temp->info;
    if(front==rear)
    {
        front=rear=NULL;

    }
    else
    {
        front=temp->next;
    }
    free(temp);
    return value;

}

void display()
{
    if(front==NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
        return ;
    }
    node *q=front;
    printf("\nQueue is::");
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->next;
    }
    printf("\n");
}