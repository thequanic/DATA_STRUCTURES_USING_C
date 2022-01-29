/*

Write a the C program to create an array by inserting  N elements 
in it then find second non repeating element from the array.

*/

#include<stdio.h>
#include<stdlib.h>

void insert_array(int arr[],int n);
int second_non_repeating_element(int arr[],int n);

int main()
{
    printf("\n\n************************* PROGRAM STARTED *************************\n\n");

    printf("*******************************************************************\n");
    printf("PROGRAM MADE BY: DEVANSH GOEL, SECTION : N, STUDENT ID:20011990");
    printf("\nCLASS ROLL NUMBER: 31, GRAPHIC ERA HILL UNIVERSITY\n");
    printf("*******************************************************************\n\n");
    
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter array elements:(except -1)::");
    insert_array(arr,n);

    int s=second_non_repeating_element(arr,n);
    if(s!=-1)
    {
        printf("\nSecond non repeating element in the array is: %d",s);
    }
    else
    {
        printf("\nSecond non repeating element does not exist...");
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

int second_non_repeating_element(int arr[],int n)
{
    int count=0,check=0;
    int i;
    for(i=0;i<n;i++)
    {
        int j;
        check=0;
        for(j=0;j<n;j++)
        {
            if(arr[i]==arr[j] && i!=j)
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            count++;
            if(count==2)
            {
                return arr[i];
            }
        }
    }
    return -1;
}