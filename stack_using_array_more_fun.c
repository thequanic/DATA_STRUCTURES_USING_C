//stack implementation using array with more functions
#include<stdio.h>
#include<stdlib.h>
#define n 10         //size of stack

int s[n];             //stack_array
int top=-1;

void push(int value)
{
    //function to add element to stack
    if(top>=n-1)
    {
        printf("\nStack is full\n");
       
    }
    else
    {
         (top)++;
         s[top]=value;
    }
}


int pop()
{
    //function to remove element from stack
    if(top==-1)
    {
          printf("\nStack is empty\n");
          return -1;
          
    }

    return(s[(top)--]);
}


void display()
{
    //function to display elements in stack
    if(top==-1)
    {
          printf("\nStack is empty\n");
          return;
    }
    else
    {
           int i;
           printf("\n");
           for(i=top;i>=0;i--){printf("%d\n",s[i]);}
           printf("\n");
    }
}


int isTop()
{
    //function to view the top most element of stack
    if(top==-1){printf("\nStack is Empty\n");return -1;}
    return s[top];
}

int replaceTop(int value)
{
    //function to replace the top most element of stack
    int r=pop();
    push(value);
    return r;
}

void insert_sorted(int value)
{

    //function to insert element in sorted stack such that stack remain sorted
    if(value>=s[top]||top==-1)
    {
        push(value);
        return;
    }
    int temp=pop();
    insert_sorted(value);
    push(temp);
}

void sort_stack()
{

    //function to sort stack
    if(top==-1){return;}
    int temp=pop();
    sort_stack();
    insert_sorted(temp);
}

void insert_at_bottom(int value)
{

    //function to insert element at bottom of stack
    if(top==-1)
    {
        push(value);
        return;
    }
    int temp=pop();
    insert_at_bottom(value);
    push(temp);

}

void reverse_stack()
{

    //function to reverse stack
    if(top==-1){return;}
    int temp=pop();
    reverse_stack();
    insert_at_bottom(temp);

}


int main()
{
    
    while(1)
    {
             printf("\nYou can perform following operations:\n");
             printf("1.PUSH\n2.DISPLAY\n3.POP\n4.ISTOP/GETTOP\n5.REPLACE_TOP\n6.SORT STACK\n7.REVERSE STACK\n8.EXIT\nEnter your choice:");

            int choice;
            scanf("%d",&choice);

            switch(choice)
            {
              case 1:
              {
                  int value;scanf("%d",&value,printf("\nEnter value (except -1):"));
                  push(value);
                  break;
              }


              case 2:
              {display();break;}

              case 3:
              {
                    int value=pop();
                    if(value!=-1){printf("\npoped value is %d\n",value);}
                    break;
              }

              case 4:
              {
                  int value=isTop();
                  if(value!=-1){printf("\nValue at stack top is %d\n",value);}
                  break;
              }

              case 5:
              {
                 int value,temp;scanf("%d",&value,printf("\nEnter value (except -1):"));
                 temp=replaceTop(value);
                 if(temp!=-1){printf("\nReplaced value is %d\n",temp);}
                 break;
                     
              }

              case 6:
              {
                  sort_stack();
                  printf("After sorting\n");
                  display();
                  break;
              }

              case 7:
              {
                  reverse_stack();
                  printf("After reversing\n");
                  display();
                  break;
              }
              
              case 8:
              exit(0);

              default: printf("\nWrong choice\n");

            }
    }
    return 0;
}