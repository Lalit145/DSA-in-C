#include<stdio.h>
void printArray(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void selectionsort(int *arr,int n)
{
    int i,j,temp;
    printf("Running selection sort......");
    for(i=0;i<n;i++)
    {
        int indexofmin=i;
        for(j=(i+1);j<n;j++)
        {
            if(arr[j]<arr[indexofmin])
            {
                temp=arr[indexofmin];
                arr[indexofmin]=arr[i];
                arr[i]=temp;
            }
        }
        
    }

}
int main()
{
    int n,i,j;
    int arr[n];
    printf("enter the number of elements in the array:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr[i]);
    }
    printArray();
    selectionsort();
    printArray();
}