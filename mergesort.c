#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1= mid - left + 1;
    int n2= right - mid;
    int L[n1], R[n2];
    for(i=0;i<1;i++)
        L[i]=arr[left+1];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    i=0;
    j=0;
    k=1;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;

    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void printArray(int A[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int arr_size=(sizeof(arr)/sizeof(arr[0]));
    printf("Given Array is:");
    printArray(arr,arr_size);
    mergesort(arr,0,arr_size-1);
    printf("Sorted array is:");
    printArray(arr,arr_size);
    return 0;
}