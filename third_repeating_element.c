/*
Write a the C program to create an array by inserting  N 
elements in it then find third repeating element from the array.
*/

#include<stdio.h>
#include<stdlib.h>

void insert_array(int arr[],int n);
int third_repeating_element(int arr[],int n);

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

    int arr[n];

    printf("Enter array elements:(except -1)::");
    insert_array(arr,n);

    int s=third_repeating_element(arr,n);
    if(s!=-1)
    {
        printf("\nThird repeating element in the array is: %d",s);
    }
    else
    {
        printf("\nThird repeating element does not exist...");
    }

    printf("\n\n************************** PROGRAM ENDED **************************\n\n");

    return 0;
}

void insert_array(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
}

int third_repeating_element(int arr[],int n)
{
    int count=0;
    int i;
    for(i=0;i<n;i++)
    {
        int j;
        if(arr[i]!=-1)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    break;
                }
            }
            
            if(count==3)
            {
                return arr[i];
            }
            
        }
    }
    return -1;
}