#include<stdio.h>
void selectsort(int arr[],int n,int* opcount)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            (*opcount)++;

            if(arr[j]<arr[min])
            {
                min=j;
            }
        }

        int temp= arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        (*opcount)++;
    }
}

void printarray(int arr[],int n)
{
    printf("sorted array :");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
int main()
{
    int n,opcount=0;
    printf("Enter the number of elements");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    selectsort(arr,n,&opcount);
    printarray(arr,n);

    printf("\nThe number of opertions is:%d ",opcount);
    return 0;   
}