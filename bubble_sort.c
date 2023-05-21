//Bubble Sort
#include<stdio.h>
void bubble_sort(int a[],int n);
void display(int a[],int n);
int main()
{
    system("cls");
    int arr[8]={12,56,74,37,98,83,22,1};
    int num=8;
    //Calling Function
    bubble_sort(arr,num);
    display(arr,num);
    return 0;
}
//Shorting Array
void bubble_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
            }
        }
    }
}
//Display Array
void display(int a[],int n)
{
    printf("Bubble Sort:\n");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}