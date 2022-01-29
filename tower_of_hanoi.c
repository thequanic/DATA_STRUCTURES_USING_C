#include <stdio.h>

void toh(char , char , char , int );

//conditions for hanoi tower
//condition 1: we can not place smaller disk below larger disk
//condition 2: we can only move one disk at a time
//condition 3: we want to tranfer disks from tower A to B in exactly same order

int main()
{

    printf("\n\n*********************************PROGRAM STARTED*********************************\n\n");
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    char a='A',b='B',c='C';
    printf("\nThere are %d disks to be moved from tower %c to %c\n",n,a,b);
    printf("We will follow following steps:\n\n");
    toh(a,b,c,n);
    printf("\n\n**********************************PROGRAM ENDED**********************************\n\n");
    return 0;
}

void toh(char a, char b, char c, int n)
{
    if(n==1)
    {
        printf("MOVE DISK %d FROM TOWER %c TO %c\n",n,a,b);
        return;
    }
    toh(a,c,b,n-1);
    printf("MOVE DISK %d FROM TOWER %c TO %c\n",n,a,b);
    toh(c,b,a,n-1);

}