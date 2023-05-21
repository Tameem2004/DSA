//Selection Sort
#include<stdio.h>
void selection_sort(int a[],int n);
void swap(int *x,int *y);
void display(int a[],int n);
int main()
{
    system("cls");
    int arr[8]={12,56,74,37,98,83,22,1};
    int num=8;
    //Calling Function
    selection_sort(arr,num);
    display(arr,num);
    return 0;
}
//Shorting Array
void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min_index]>a[j])
            {
                min_index=j;
            }
        }
        if(min_index!=i)
        {
            //Calling Swap Function
            swap(&a[i],&a[min_index]);
        }
    }
}
void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}
//Display Array
void display(int a[],int n)
{
    printf("Selection Sort:\n");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}