//simple infix to prefix notation convertor

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//stack functions
char push(char s[],int n, int *top,char value);
char pop(char s[],int *top);
char get_top(char s[],int *top);

//reverse function
void reverse_string(char str[]);

//converter functon
void infix_to_postfix(char infix[],int n,char postfix[]);
void infix_to_prefix(char infix[],int n,char prefix[]);



int main()
{
    
    int n=100;
    char infix[n];
    char prefix[n];
    printf("\n\n**********************************PROGAM STARTED**********************************\n\n");
    printf("Enter infix expression \n(with single character variable or single digit operand): ");
    gets(infix);
    infix_to_prefix(infix,n,prefix);
    printf("\nPrefix expression: %s",prefix);
    printf("\n\n***********************************PROGAM ENDED***********************************\n\n");

    
    return 0;
}


char push(char s[],int n, int *top,char value)
{
    //function to add element to stack
    if(*top>=n-1)
    {
        return '@';
    }
    else
    {
         (*top)++;
         s[*top]=value;
         return '#';
    }
}


char pop(char s[],int *top)
{
    //function to remove element from stack
    if(*top==-1)
    {
         
          return '@';
          
    }

    return(s[(*top)--]);
}

char get_top(char s[],int *top)
{
    //function to view the top most element of stack
    if(*top==-1){return '@';}
    return s[*top];
}

void reverse_string(char str[])
{
    int i,j,size=0;
    while(str[size]!='\0')
    {
        size++;
    }
    char temp;
    j=size-1;
    for(i=0;i<size/2;i++)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;

    }
}


void infix_to_postfix(char infix[],int n,char postfix[])
{
    char stack[n];
    int i=0,j=0;
    int top=-1;
    while(infix[i]!='\0')
    {
        if((infix[i]>='a' && infix[i]<='z')|| (infix[i]>='A' 
        && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9'))
        {
            if((infix[i-1]>='a' && infix[i-1]<='z')|| (infix[i-1]>='A' 
            && infix[i-1]<='Z') || (infix[i-1]>='0' && infix[i-1]<='9'))
            {
                printf("\nMULTI DIGIT OPERAND/MULTI CHARACTER VARIABLE DETECTED... CANNOT CONVERT\n");
                return;
            }
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else if(infix[i]=='^')
        {
            push(stack,n,&top,infix[i]);
            i++;
        }
        else if(infix[i]=='*'|| infix[i]=='/')
        {
            while(get_top(stack,&top)=='^'||get_top(stack,&top)=='*'||get_top(stack,&top)=='/')
            {
                postfix[j]=pop(stack,&top);
                j++;
            }
            push(stack,n,&top,infix[i]);
            i++;
        }
        else if(infix[i]=='+'||infix[i]=='-')
        {
            while(get_top(stack,&top)=='^'||get_top(stack,&top)=='*'
            ||get_top(stack,&top)=='/'||get_top(stack,&top)=='+'
            ||get_top(stack,&top)=='-')
            {
                postfix[j]=pop(stack,&top);
                j++;
            }
            push(stack,n,&top,infix[i]);
            i++;
        }
        else if(infix[i]=='(')
        {
            push(stack,n,&top,infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(get_top(stack,&top)!='(')
            {
                postfix[j]=pop(stack,&top);
                j++;
            }
            pop(stack,&top);
            i++;
        }
        else 
        {
            printf("\nINVALID CHARACTER IN ENTERED EXPRESSION\n");
            return;
        }
    }
    while(get_top(stack,&top)!='@')
    {
        postfix[j]=pop(stack,&top);
        j++;
    }
    postfix[j]='\0';
}

void infix_to_prefix(char infix[],int n,char prefix[])
{
    char rev[n];
    strcpy(rev,infix);
    reverse_string(rev);
    int i=0;
    while(rev[i]!='\0')
    {
        if(rev[i]==')'){rev[i]='(';}
        else if(rev[i]=='('){rev[i]=')';}
        i++;
    }
    infix_to_postfix(rev,n,prefix);
    reverse_string(prefix);
}