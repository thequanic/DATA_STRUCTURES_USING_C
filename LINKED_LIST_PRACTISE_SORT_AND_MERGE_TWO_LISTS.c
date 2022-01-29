/*
Write a C program to create TWO singly linked list L1 and L2 
and sort both the list and finally merge both the list such 
that L2 comes after L1.
[use double  pointer]
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node*link;
}node;

void addatlast(node **start, int data);
int display(node **start);
void split_list(node ** start, node ** first_half, node ** second_half);
node * sorted_merge( node ** first_half, node **second_half);
void sort_list(node**start);
void merge_lists(node **list1, node **list2);

int main()
{

    printf("\n\n**********************************PROGAM STARTED**********************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL, SECTION : N, STUDENT ID:20011990");
    printf("\nCLASS ROLL NUMBER: 31, GRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");

    //creating lists
    node *list1=NULL,*list2=NULL;

    int n1,n2,i,data;

    printf("Enter number of nodes in list 1:");
    scanf("%d",&n1);

    printf("Enter data elements of list 1:");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&data);
        addatlast(&list1,data);
    }

    printf("Enter number of nodes in list 2:");
    scanf("%d",&n2);

    printf("Enter data elements of list 2:");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&data);
        addatlast(&list2,data);
    }
    
    printf("\n\nLIST 1 IS:");
    display(&list1);

    printf("\n\nLIST 2 IS:");
    display(&list2);

    //sorting lists
    sort_list(&list1);
    sort_list(&list2);
    
    printf("\n\nLIST 1 AFTER SORTING IS:");
    display(&list1);

    printf("\n\nLIST 2 AFTER SORTING IS:");
    display(&list2);
    


    //merging lists
    merge_lists(&list1,&list2);

    printf("\n\nMERGED LIST IS:");
    display(&list1);

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


int display(node **start)
{
    node *q;
    if(*start==NULL)
    {
        printf("LIST IS EMPTY\n");
        return 0;

    }
    q=*start;
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->link;
    }
    printf("\n");
}

void split_list(node ** start, node ** first_half, node ** second_half)
{
    node*fast=(*start)->link;
    node*slow=*start;

    while(fast!=NULL)
    {
        fast=fast->link;
        if(fast!=NULL)
        {
            fast=fast->link;
            slow=slow->link;
        }
    }

    *first_half=*start;
    *second_half=slow->link;
    slow->link=NULL;
}

node * sorted_merge( node ** first_half, node **second_half)
{
    node * result=NULL;

    if(*first_half==NULL)
    {
        result=*second_half;
        return result;
    }

    if(*second_half==NULL)
    {
        result=*first_half;
        return result;
    }

    if((*first_half)->info<(*second_half)->info)
    {
        result=*first_half;
        result->link=sorted_merge(&((*first_half)->link),second_half);
    }
    else
    {
        result=*second_half;
        result->link=sorted_merge(&((*second_half)->link),first_half);
    }

    return result;
}

void sort_list(node**start)
{
    //using merge sort
    if(*start==NULL || (*start)->link==NULL)
    {
        return;
    }

    node*first_half,*second_half;

    split_list(start,&first_half,&second_half);

  
    sort_list(&first_half);
    sort_list(&second_half);

    *start=sorted_merge(&first_half,&second_half);
}

void merge_lists(node **list1, node **list2)
{
    if(*list1==NULL)
    {
        *list1=*list2;
        return;
    }

    node*q=*list1;
    while(q->link!=NULL)
    {
        q=q->link;
    }
    q->link=*list2;
}
