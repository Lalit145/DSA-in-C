#include<stdio.h>

void main()
{
    int n;
    int i,j=1;
    printf("Enter the number of jobs:");
    scanf("%d",&n);
    int job[n];
    int profit[n];
    int dead[n];
    int dmax=0;
    printf("Enter the job ids:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&job[i]);
    }
    printf("Enter the profits:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&profit[i]);
    }
    printf("Enter the deadlines:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&dead[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(profit[i]<profit[j])
            {
                int temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;

                int temp2=job[i];
                job[i]=job[j];
                job[j]=temp2;

                int temp3=dead[i];
                dead[i]=dead[j];
                dead[j]=temp3;
            }
            
        }
    }
    for(i=1;i<=n;i++)
    {
        if(dead[i]>dmax)
        {
            dmax=dead[i];
        }
    }
    printf("Max deadline:%d",dmax);
    int timeslot[dmax];

    for (int i = 1; i <= dmax; i++)
    {
        timeslot[i] = -1;
    }
    int totalprofit=0;
    printf("Jobs used:");
    int k=0;
    for(i=1;i<=n;i++)
    {
        if(dead[i]<dmax)
        {
            k=dead[i];
        }
        else
        {
            k=dmax;
        }
        while(k>=1)
        {
            if(timeslot[k]==-1)
            {
                timeslot[k]=job[i];
                printf("%d ",job[i]);
                totalprofit=totalprofit+profit[i];
                break;
            }
            k=k-1;
        }
    }
    printf("Total profit:%d",totalprofit);
}