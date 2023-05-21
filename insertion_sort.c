//Insertion Sort
#include<stdio.h>
void insertion_sort(int a[],int n);
void display(int a[],int n);
int main()
{
    system("cls");
    int arr[8]={12,56,74,37,98,83,22,1};
    int num=8;
    //Calling Function
    insertion_sort(arr,num);
    display(arr,num);
    return 0;
}
//Sorting Array
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
//Display Array
void display(int a[],int n)
{
    printf("Insertion Sort:\n");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}