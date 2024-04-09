#include<stdio.h>
#include<stdlib.h>

void bubblesort(int arr[],int n,int* opcount)
{
    for(int i=0;i<n;i++)
    {
       int  swapped=0;
       for(int j=0;j<n-i-1;j++)
       {
        (*opcount)++;
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            (*opcount)++;
            swapped=1;
        }
       }
    }
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}

int main()
{
    int n;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    int arr[n],bestcase[n],worstcase[n];
    int opcountbest=0, opcountworst=0;

    printf("Enter the elements into the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        bestcase[i]=arr[i];
    }

    for(int i=0;i<n;i++)
    {
        worstcase[i]=arr[n-i-1];
    }

    bubblesort(bestcase,n,&opcountbest);
    printf("\nSorted array(BEST CASE)");
    printarray(bestcase,n);
    printf("The operation count is %d\n",opcountbest);



bubblesort(worstcase,n,&opcountworst);
printf("\nSorted array(worst case):");
printarray(worstcase,n);
printf("The operation count is %d\n",opcountworst);
}