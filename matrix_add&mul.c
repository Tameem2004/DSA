#include<stdio.h>
#include<stdlib.h>

void addition(int A[10][10],int B[10][10],int r1,int c1);
void multiplication(int A[10][10],int B[10][10],int r1,int c2,int c1);

int main()
{
    int r1,c1,r2,c2,i,j,ch;
    printf("ENTER THE NUMBER OF ROWS AND COLUMNS IN 1ST ARRY");
    scanf("%d%d",&r1,&c1);
    printf("ENTER THE ROWS AND COLUMNS IN 2ND ARRAY");
    scanf("%d%d",&r2,&c2);
    int A[10][10],B[10][10],C[10][10];
    
    printf("ENTER NUMBER IN FIRST MATRIX\n");
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
    }

    printf("ENTER NUMBER IN SECOND MATRIX\n");
    {
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
    }

    printf("FIRST MATRIX IS: \n");
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                printf("%d ",A[i][j]);
            }
            printf("\n");
        }
    }

    printf("SECOND MATRIX IS: \n");
    {
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d ",B[i][j]);
            }
            printf("\n");
        }
    }
    
    printf("PRESS 0 FOR EXIT\n");
    printf("PRESS 1 FOR ADDITION\n");
    printf("PRESS 2 FOR MULTIPLICATION\n");
    
    
    while(1)
    {
    	printf("Enter your choice:\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 0:
    			exit(1);
    			break;
    		case 1:
                if(r1!=r2)
                {
                    printf("\n YOUR ARRAY CANNOT BE ADDABLE");
                    exit(1);
                    
                }
                else if(c1!=c2)
                {
                    printf("\n YOUR ARRAY CANNOT BE ADDABLE");
                    exit(1);
                    
                }
                else
    			addition(A,B,r1,c1);
    			break;
    		case 2:
                if(c1!=r2)
                    {
                        printf("\n YOUR ARRAY CANNOT BE MULTIPLIABLE");
                        exit(1);
                    }
                else 
    			    multiplication(A,B,r1,c2,c1);
				    break;
			dafault:
				printf("you enter a wrong choice");	
		}
	}
}

void addition(int A[10][10],int B[10][10],int r1,int c1)
{
    int C[10][10],i,j;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
            
        }
        printf("\n");
    }

    printf("MATRIX ADDITION IS: \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ",C[i][j]);
            
        }
        printf("\n");
    }
}

void multiplication(int A[10][10],int B[10][10],int r1,int c2,int c1)
{
    int D[10][10],i,j,k;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            D[i][j]=0;
            for(k=0;k<c1;k++)
            {
                D[i][j]=D[i][j]+A[i][k]*B[k][j];
            }
            
        }
        printf("\n");
    }

    printf("MATRIX MULTIPLICATION IS: \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
}