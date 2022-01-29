// Write a C program to create an array by inserting N elements in it and then print all
//the numbers which are armstrong number from the array

#include<stdio.h>

int pow_(int num,int power);
int isarmstrong(int num);


int main()
{
    printf("\n\n*******************************************************************************\n\n");
    int n;
    printf("\nEnter size of array::");
    scanf("%d",&n);

    int arr[n];
    int i;

    printf("Enter array::\n=>");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    printf("Armstrong numbers in given array are::\n");
    for(i=0;i<n;i++)
    {
        if(isarmstrong(arr[i])==1){printf("%d\t",arr[i]);}
    }   
    printf("\n\n***********************************PROGRAM ENDS****************************************\n\n");

    return 0;
}

int pow_(int num,int power)
{
     if(power==1){return num;}
     return num*pow_(num,--power);
}

int isarmstrong(int num)
{
    int temp=num,size=0;

    while(temp>0)
    {
         size++;
         temp/=10;
    }

    int sum=0;
    temp=num;

    while(temp>0)
    {
         sum+=pow_(temp%10,size);
         temp/=10;
    }

    if(sum==num){return 1;}
    else{return 0;}

}