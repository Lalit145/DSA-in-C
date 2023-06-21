include<stdio.h>
void main()
{
    int n;
    printf("Enter the number of items:");
    scanf("%d",&n);
    int item[n];
    int value[n];
    int weight[n];
    int ratio[n];
    int capacity;
    printf("Enter the item numbers:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&item[i]);
    }

    printf("Enter the values:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&value[i]);
    }

    printf("Enter the weights:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&weight[i]);
    }
    for(i=1;i<=n;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                int temp1=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp1;

                int temp2=item[i];
                item[i]item[j];
                item[j]=temp2;

                int temp3=value[i];
                value[i]=value[j];
                value[j]=temp3;

                int temp4=weight[i];
                weight[i]=weight[j];
                weight[j]=temp4;
            }
        }
    }
    printf("Enter the weight capacity:");
    sanf("%d",&capacity);
    while()
}