//stack using linked list
#include <stdio.h>
#include <stdlib.h>

//user defined data type node
typedef struct node
{
    int info;
    struct node *link;
}node;

//pointer for stack
node *top=NULL;

void push(int value);
int pop();
void display();
int Top();
int replaceTop(int value);


int main()    //main function
{
    int choice;
    printf("\n\n***********************************PROGRAM STARTED***********************************\n\n");
    while(1)
    {
        char *s="OPERATION PERFORMED SUCCESSFULLY";
        printf("\n\n*************************************************************************************\n\n");
        printf("YOU CAN PERFORM FOLLOWING OPERATIONS...........\n\n");
        printf("\n___________MENU___________\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.GET TOP\n");
        printf("5.REPLACE VALUE AT TOP\n");
        printf("6.EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter element to be pushed:");
                int value;
                scanf("%d",&value);
                push(value);
                break;
            }

            case 2:
            {
                int value=pop();
                if(value!=-1)
                {
                    printf("Poped value is %d\n",value);
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
                int value=Top();
                if(value!=-1)
                {
                    printf("Value at top of the stack is %d\n",value);
                }
                break;
            }

            case 5:
            {
                printf("Enter the new value:");
                int value1;
                scanf("%d",&value1);
                int value2=replaceTop(value1);
                if(value2!=-1)
                {
                    printf("Value replaced is %d\n",value2);
                }
                break;
            }

            case 6:
            {
                printf("\n\n*************************************************************************************\n\n");
                printf("                                   PROGRAM FINISHED                                        ");
                printf("\n\n*************************************************************************************\n\n");
                exit(0);
            }

            default:   s="        INVALID CHOICE         ";
        }
         printf("\n\n*************************************************************************************\n\n");
         printf("                         %s                            ",s);

    }
    return 0;
}

void push(int value)
{
    //function to insert value in stack
    node *temp=(node*)malloc(sizeof(node));

    if(temp==NULL)         //checking whether memory allocated to temp
    {
        printf("\nStack Overflow\n");
        return;
    }

    temp->info=value;
    temp->link=NULL;

    if(top==NULL)       //checking whether temp is first element in stack
    {
        top=temp;
        return;
    }

    temp->link=top;
    top=temp;

}

int pop()
{
    //function to delete value from stack top and return deleted value
    if(top==NULL)
    {
        printf("\nStack Underflow, Stack is Empty");
        return -1;
    }
    node *temp=top;
    top=temp->link;
    int i=temp->info;
    free(temp);
    return i;
}

void display()
{
    //function to display values in stack
    if(top==NULL)
    {
        printf("\nStack Underflow, Stack is Empty");
        return;
    }
    node *q;
    q=top;
    printf("Stack is: ");
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->link;
        
    }
    printf("\n");
}

int Top()
{
    //function to return top most value of stack
    if(top==NULL)
    {
        printf("\nStack Underflow, Stack is Empty");
        return -1;
    }
    return top->info;
}

int replaceTop(int value)
{
   //function to update topmost value of stack
    int value1=pop();
    if(value1 !=-1)
    push(value);
    return value1;
}