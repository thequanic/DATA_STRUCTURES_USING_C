//we will use two queues to implement a stack using two queues
//int q1[10],q2[10];
//where q1 will act as stack and q2 will help it

#include<stdio.h>
#include<stdlib.h>

// queue functions
int isEmpty_queue(int q[],int n, int*front, int*rear);

int isFull_queue(int q[],int n, int*front, int*rear);

void enqueue(int q[],int n, int*front, int*rear, int value);

int dequeue(int q[],int n, int*front, int*rear);

void display_queue(int q[],int n, int*front, int*rear);

//stack functions
void push(int q1[],int q2[],int *f1, int *r1,int *f2, int *r2,int n,int value);

int pop(int q1[],int q2[],int *f1, int *r1,int *f2, int *r2,int n);

void display_stack(int q1[],int q2[],int *f1, int *r1,int *f2, int *r2,int n);



int main()
{
    int n=10;
    int q1[n],q2[n];
    int f1=-1,f2=-1,r1=-1,r2=-1;     //front and rear for q1 and q2 respectvely

    while(1)
    {
             printf("\nYou can perform following operations:\n");
             printf("1.PUSH\n2.DISPLAY\n3.POP\n4.EXIT\nEnter your choice:");

            int choice;
            scanf("%d",&choice);

            switch(choice)
            {
              case 1:
              {
                  int value;
                  scanf("%d",&value,printf("\nEnter value (except -1):"));
                  push(q1,q2,&f1,&r1,&f2,&r2,n,value);
                  break;
              }

              case 2:
              { 
                  display_stack(q1,q2,&f1,&r1,&f2,&r2,n);
                  break;
              }

              case 3:
              { int value=pop(q1,q2,&f1,&r1,&f2,&r2,n);
                if(value!=-1){printf("\npoped value is %d\n",value);}
                break;
              }

              case 4:exit(0);

              default: printf("\nWrong choice\n");

            }
    }



    return 0;
}

int isEmpty_queue(int q[],int n, int*front, int*rear)
{
    if(*front==-1){return 1;}
    return 0;
}


int isFull_queue(int q[],int n, int*front, int*rear)
{
    if((*front==(*rear+1)%n)){return 1;}
    return 0;
}




void enqueue(int q[],int n, int*front, int*rear, int value)
{
    if(isFull_queue(q,n,front,rear))
    {
        printf("\nQueue is Full");
        return;
    }
    if(*rear==-1)
    {
        *front=0;
        *rear=0;
    }
    else 
    {
        *rear=(*rear+1)%n;
    }
    q[*rear]=value;
}


int dequeue(int q[],int n, int*front, int*rear)
{
    if(isEmpty_queue(q,n,front,rear))
    {
        printf("\nQueue is Empty");
        return -1;
    }
    int value=q[*front];
    if(*front==*rear)
    {
        *front=-1;
        *rear=-1;
    }
    else 
    {
        *front=(*front+1)%n;
    }
    return value;
}



void display_queue(int q[],int n, int*front, int*rear)
{
    if(isEmpty_queue(q,n,front,rear))
    {
        printf("\nQueue is Empty");
        return;
    }
    
    int i;
    for(i=*front;i!=*rear;i=(i+1)%n)
    {
        printf("%d ",q[i]);
    }
    printf("%d ",q[i]);

}

void push(int q1[],int q2[],int *f1, int *r1,int *f2, int *r2,int n,int value)
{
    if(isFull_queue(q1,n,f1,r1))
    {
        printf("\nStack is Full\n");
        return;
    }

    while(!isEmpty_queue(q1,n,f1,r1))      //while q1 is not empty
    {
        int temp=dequeue(q1,n,f1,r1);      //move elements from q1 to q2
        enqueue(q2,n,f2,r2,temp);
    }
 
     enqueue(q1,n,f1,r1,value);             //put value in q1


    while(!isEmpty_queue(q2,n,f2,r2))      //while q2 is not empty
    {
        int temp=dequeue(q2,n,f2,r2);      //move elements from q2 to q1
        enqueue(q1,n,f1,r1,temp);
    }
 
}

int pop(int q1[],int q2[],int *f1, int *r1,int *f2, int *r2,int n)
{
    if(isEmpty_queue(q1,n,f1,r1))
    {
        printf("\nStack is Empty\n");
        return -1;

    }

    return dequeue(q1,n,f1,r1);
}

void display_stack(int q1[],int q2[],int *f1, int *r1,int *f2, int *r2,int n)
{
    if(isEmpty_queue(q1,n,f1,r1))
    {
        printf("\nStack is Empty\n");
        return ;

    }

    printf("\nStack is::");
    display_queue(q1,n,f1,r1);
}
