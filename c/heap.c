#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i)
{
    int largest =i;
    int right=2*i+2;
    int left =2*i+1;

    if(left<n && arr[left]>arr[largest])
    {
        largest =left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest =right;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
    
}

void buildheap(int arr[],int n)
{
    int startindex=(n/2)-1;

    for(int i=startindex;i>=0;--i)
    {
        heapify(arr,n,i);
    }
}

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[]={1,4,3,2,5,4,9};
    int n= sizeof(arr)/sizeof(arr[0]);
     printf("Original array: ");
    printarray(arr, n);

    // Build heap
    buildheap(arr, n);

    printf("Heap: ");
    printarray(arr, n);

    return 0;
}