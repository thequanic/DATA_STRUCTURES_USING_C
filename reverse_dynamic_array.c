/*
Write a C program Create a  Dynamic array 
and then Reverse the array  using recursion and then finally print the array.
*/

#include<stdio.h>
#include<stdlib.h>

void insert_array(int arr[],int n);
void print_array(int arr[],int n);
void reverse_array(int *arr,int high,int low);

int main()
{
    printf("\n\n************************* PROGRAM STARTED *************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL, STUDENT ID:20011990");
    printf("\nGRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");
    
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int *arr=(int*)malloc(n*sizeof(int));

    printf("Enter array elements::");
    insert_array(arr,n);

    printf("Reverse of given array is:");
    reverse_array(arr,n,0);
    print_array(arr,n);

    free(arr);

    printf("\n\n************************** PROGRAM ENDED **************************\n\n");

    return 0;
}

void insert_array(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
}

void print_array(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
}

void reverse_array(int *arr,int high,int low)
{
    if(high<=low)
    {
        return;
    }

    int temp=arr[high-1];
    arr[high-1]=arr[low];
    arr[low]=temp;

    reverse_array(arr,high-1,low+1);

}
