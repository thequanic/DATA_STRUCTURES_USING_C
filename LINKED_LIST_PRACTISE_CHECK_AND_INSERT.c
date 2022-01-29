/*ques. Create a singly linked list. Input a check key. Now insert user entered values to
linked list in following order:

if value is smaller than key, insert at starting of the list
if value is larger than key, insert at end of the list
if value is equal to key, discard the value and do not insert

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* link;

} node;

node* start=NULL;

void insert_at_beg(int value)
{
    node * temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=NULL;
    
    if (start==NULL)
    {
        start=temp;
        return;
    }

    temp->link=start;
    start=temp;
    return;
} 

void insert_at_end(int value)
{
    node * temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=NULL;
    
    if (start==NULL)
    {
        start=temp;
        return;
    }

    node* q=start;
    while(q->link!=NULL)
    {
        q=q->link;
    }
    q->link=temp;
    return;
}

void display()
{
    if(start==NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    node*q=start;
    printf("List is::");
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->link;
    }
}

int main()
{
    int check_value;
    printf("Enter a check value::");
    scanf("%d",&check_value);
    while(1)
    {
        printf("\n\n*****************************************************************************************\n\n");
        printf("##### MENU #####\n\n");
        printf("1.Insert node\n");
        printf("2.Display\n"); 
        printf("3.Exit");
        int choice;
        printf("\nEnter your choice::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter value to be inserted::");
                int value;
                scanf("%d",&value);
                if(value<check_value)
                {
                    insert_at_beg(value);
                }
                else if(value>check_value)
                {
                    insert_at_end(value);
                }
                else
                {
                    printf("Value==Check_Value.....Will not be inserted\n");
                }
                break;
            }

            case 2:
            {
                display();
                break;
            }

            case 3:
            {
                printf("\nEnd of program\n");
                exit(0);
            }

            default:printf("Invalid Choice");
        }


    }
}