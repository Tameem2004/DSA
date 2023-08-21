#include<stdio.h>

void addition(int A[10][10],int B[10][10],int n);
void multiplication(int A[10][10],int B[10][10],int n);

int main()
{
    int num,i,j;
    printf("ENTER THE NUMBER OF ROWS AND COLUMNS");
    scanf("%d",&num);
    int A[10][10],B[10][10],C[10][10];
    
    printf("ENTER NUMBER IN FIRST MATRIX\n");
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
    }

    printf("ENTER NUMBER IN SECOND MATRIX\n");
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
    }

    printf("FIRST MATRIX IS: \n");
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                printf("%d ",A[i][j]);
            }
            printf("\n");
        }
    }

    printf("SECOND MATRIX IS: \n");
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                printf("%d ",B[i][j]);
            }
            printf("\n");
        }
    }

    addition(A,B,num);
    multiplication(A,B,num);
}

void addition(int A[10][10],int B[10][10],int n)
{
    int C[10][10],i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
            
        }
        printf("\n");
    }

    printf("MATRIX ADDITION IS: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",C[i][j]);
            
        }
        printf("\n");
    }
}

void multiplication(int A[10][10],int B[10][10],int n)
{
    int D[10][10],i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            D[i][j]=0;
            for(k=0;k<n;k++)
            {
                D[i][j]=D[i][j]+A[i][k]*B[k][j];
            }
            
        }
        printf("\n");
    }

    printf("MATRIX MULTIPLICATION IS: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
}