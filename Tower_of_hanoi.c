//Tower_of_hanoi
#include<stdio.h>
#include<stdlib.h>
int Tower_Of_Hanoi(int n,char src,char oux,char dest);
int main()
{
    system("cls");
    int N;
    printf("enter the number of disk");
    scanf("%d",&N);
    Tower_Of_Hanoi(N,'A','B','C');
    printf("\n");
    return 0;
}

int Tower_Of_Hanoi(int n,char src,char oux,char dest)
{
    if(n==0)
    {
        return 0;
    }
    Tower_Of_Hanoi(n-1,src,dest,oux);
    printf("\nMove %d from %c to %c",n,src,dest);
    Tower_Of_Hanoi(n-1,oux,src,dest);
}
