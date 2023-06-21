
#include <stdio.h>

int min(int a, int b)
{
    int k;
    if (a > b)
    {
        k = b;
    }
    else
    {
        k = a;
    }
    return k;
}

void main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int job[n], profit[n], deadline[n];
    printf("Enter the job id: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &job[i]);
    }
    printf("Enter the profit: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &profit[i]);
    }
    printf("Enter the deadline: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &deadline[i]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k < n - i + 1; k++)
        {
            if (profit[k + 1] > profit[k])
            {
                int temp1 = profit[k];
                profit[k] = profit[k + 1];
                profit[k + 1] = temp1;

                int temp2 = job[k];
                job[k] = job[k + 1];
                job[k + 1] = temp2;

                int temp3 = deadline[k];
                deadline[k] = deadline[k + 1];
                deadline[k + 1] = temp3;
            }
        }
    }
    printf("Jobs: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d  ", job[i]);
    }
    printf("\nProf: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d  ", profit[i]);
    }
    printf("\nDead: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d  ", deadline[i]);
    }
    int dmax = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deadline[i] > dmax)
        {
            dmax = deadline[i];
        }
    }
    printf("\nMaximum Deadline: %d", dmax);
    int k = 0;
    int timeslot[dmax];
    for (int i = 1; i <= dmax; i++)
    {
        timeslot[i] = -1;
    }
    int totalprofit = 0;
    printf("\nJobs ID used: ");
    for (int i = 1; i <= n; i++)
    {
        k = min(dmax, deadline[i]);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = job[i];
                printf("%d ", job[i]);
                totalprofit = totalprofit + profit[i];
                break;
            }
            k = k - 1;
        }
    }
    printf("\nTotal Profit: %d", totalprofit);
}