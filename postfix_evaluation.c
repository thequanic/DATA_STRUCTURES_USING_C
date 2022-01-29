//Write a C program to Evaluate Postfix Expression using Stack

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100

//stack functions
void push(int s[],int n, int *top,int value);
int pop(int s[],int *top);

//evaluator
int postfix_eval(char postfix[],int* check);
  

int main()
{
    char postfix[max];
    int check;
    printf("\n\n**********************************PROGAM STARTED**********************************\n\n");
    
    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL, SECTION : N, STUDENT ID:20011990");
    printf("\nCLASS ROLL NUMBER: 31, GRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");
    
    printf("Enter postfix expression (one operand=only single digit):");
    gets(postfix);
    int ans=postfix_eval(postfix,&check);
    if(check!=0)
    {
        printf("Given expression evaluated to: %d",ans);
    }
    
    printf("\n\n***********************************PROGAM ENDED***********************************\n\n");
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
        return -1;
    }

    return(s[(*top)--]);
}

int postfix_eval(char postfix[],int* check)
{
    *check=1;
    int i=0;
    int stack[max];
    int top=-1;
    while(postfix[i]!='\0')
    {
        if(postfix[i]>='0'&& postfix[i]<='9')
        {
            //if operand push it to stack
            push(stack,max,&top,postfix[i]-48);
            i++;
        }
         else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'
        ||postfix[i]=='/'||postfix[i]=='^')
        {
            //if operator pop two operands from stack
            //perform operation and push answer back
            
            int b=pop(stack,&top);
            int a=pop(stack,&top);
            int ans;
            if(a==-1||b==-1)
            {
                printf("\nExpression cannot be evaluated...\n");
                *check=0;
            }
            else if(postfix[i]=='+')
            {
                ans=a+b;
                push(stack,max,&top,ans);
            }
            else if(postfix[i]=='-')
            {
                ans=a-b;
                push(stack,max,&top,ans);
            }
            else if(postfix[i]=='*')
            {
                ans=a*b;
                push(stack,max,&top,ans);
            }
            else if(postfix[i]=='/')
            {
                ans=a/b;
                push(stack,max,&top,ans);
            }
            else if(postfix[i]=='^')
            {
                ans=pow(a,b);
                push(stack,max,&top,ans);
            }
            i++;

        }
        else
        {
            printf("\nInvalid character in postfix expression...\n");
            *check=0;
        }
    }
    return (pop(stack,&top));
}
