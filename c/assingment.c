#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int* b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}

void calculatecost(int assingment[],int costmatrix [][],int n,int *opcount)
{
    totalcost=0;
    for (int i=0;i<n;i++);
    {
        totalcost+= costmatrix[i][assingment[i]];
    }
    (*opcount)++
    printf("Assingment:");
    for(int i=0;i<n;i++)
    {
        printf("(%d,%d)",i+1,assingment[i]+1);
    }
    printf("Totalcost",totalcost);
}

void bruteforce(int assingment[],int costmatrix[][],int n,int start,int end,int *opcount)
{
    if(start==end)
    {
        claculatecost(assingment,costmatrix,n,opcount);
        return;
    }

    for( int i=start;i<=end;i++)
    {
        swap(&assingment(start),&assingment[i]);

        bruteforce(assingment,costmatrix,n,start+1,end,opcount);

        swap(&assingment(start),&assingment[i]);
    }
}

int main()
{
    int n,opcount=0;
    int assignment[];
    int costmatrix[][];

    printf("Enter the number of tasks");
    scanf("%d",&n);

    printf("Enter the costmatrix ");
    for(int i=0;i<n;i++)
    {
        for(int j=0:j<n;j++){
           printf("%d",&costmatrix[i][j]); 
        }
    }

    for(int i=0;i<n;i++)
    {
        assignment[i]=i;
    }

    bruteforce(assignment,costmatrix,n,0,n-1,&opcount);

    printf("operation count is:",opcount);

    return 0;
}