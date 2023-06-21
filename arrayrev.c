#include<stdio.h>
#include<math.h>
void main()
{
    int n;
    int arr[n];
    printf("Enter limit:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int i=n-1;i>=0;i--)
    {
        printf("%d\n",arr[i]);
    }
    
}