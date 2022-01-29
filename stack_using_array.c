/*
Write a C Program implement STACK using array in menu driven form.
*/

//stack implementation using array
#include<stdio.h>
#include<stdlib.h>


void push(int s[],int n, int *top,int value);
int pop(int s[],int *top);
void display(int s[],int *top);
int isTop(int s[],int *top);
int replaceTop(int st[],int n,int *top,int value);


int main()
{
    printf("\n\n************************* PROGRAM STARTED *************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL, SECTION : N, STUDENT ID:20011990");
    printf("\nCLASS ROLL NUMBER: 31, GRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");
    
    int n;
    scanf("%d",&n,printf("Enter max size of stack:"));
    int top=-1;
    int st[n];
    while(1)
    {
             printf("\nYou can perform following operations:\n");
             printf("1.PUSH\n2.DISPLAY\n3.POP\n4.ISTOP/GETTOP\n5.REPLACE_TOP\n6.EXIT\nEnter your choice:");

            int choice;
            scanf("%d",&choice);

            switch(choice)
            {
              case 1:
                    {
                        int value;
                        scanf("%d",&value,printf("\nEnter value (except -1):"));
                        push(st,n,&top,value);
                        break;
                    }

              case 2:
                    {
                        display(st,&top);
                        break;
                    }

              case 3:
                    {
                        int value=pop(st,&top);
                        if(value!=-1)
                        {
                            printf("\npoped value is %d\n",value);
                        }
                        break;
                    }

              case 4:
                    {
                        int value=isTop(st,&top);
                        if(value!=-1)
                        {
                            printf("\nValue at stack top is %d\n",value);
                        }
                        break;
                    }

              case 5:
                    {
                        int value,temp;
                        scanf("%d",&value,printf("\nEnter value (except -1):"));
                        temp=replaceTop(st,n,&top,value);
                        if(temp!=-1)
                        {
                            printf("\nReplaced value is %d\n",temp);
                        }
                        break;
                    }

              case 6:
                    {
                        printf("\n\n************************** PROGRAM ENDED **************************\n\n");
                        exit(0);
                    }

              default: 
                        printf("\nWrong choice\n");

            }
    }
    return 0;
}

void push(int s[],int n, int *top,int value)
{
    //function to add element to stack
    if(*top>=n-1)
    {
        printf("\nStack is full\n");
       
    }
    else
    {
         (*top)++;
         s[*top]=value;
    }
}


int pop(int s[],int *top)
{
    //function to remove element from stack
    if(*top==-1)
    {
          printf("\nStack is empty\n");
          return -1;
          
    }

    return(s[(*top)--]);
}


void display(int s[],int *top)
{
    //function to display elements in stack
    if(*top==-1)
    {
          printf("\nStack is empty\n");
          return;
    }
    else
    {
           int i;
           printf("\n");
           for(i=*top;i>=0;i--){printf("%d\n",s[i]);}
           printf("\n");
    }
}


int isTop(int s[],int *top)
{
    //function to view the top most element of stack
    if(*top==-1){printf("\nStack is Empty\n");return -1;}
    return s[*top];
}

int replaceTop(int st[],int n,int *top,int value)
{
    //function to replace the top most element of stack
    int r=pop(st,top);
    push(st,n,top,value);
    return r;
}

