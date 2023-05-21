//Binary Search
#include<stdio.h>
int main()
{
    system("cls");
    int arr[8]={1,12,22,37,56,74,83,98};
    int item=37,lb=0,ub=7;
    while(lb<=ub)
    {
        int mid=lb+ub/2;
        if(arr[mid]==item)
        {
            printf("Item %d Found at %d Position",item,mid+1);
            break;
        }
        else if(arr[mid]>item)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    printf("\n");
    return 0;
}