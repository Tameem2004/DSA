//Linear Search
#include<stdio.h>
int main()
{
    system("cls");
    int arr[8]={12,56,74,37,98,83,22,1};
    int item=37,i=0,num=8;
    while(i<num)
    {
        if(arr[i]==item)
        {
            printf("Item %d Found at %d Position",item,i+1);
            break;
        }
        i++;
    }
    printf("\n");
    return 0;
}