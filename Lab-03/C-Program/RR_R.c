#include<stdio.h>
int main()
{
    int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
    float awt=0,atat=0;
    printf("Enter the Number of process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter burst time for Process P%d~~",i+1);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter quantum time: ");
    scanf("%d",&qt);
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            temp = qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
                rem_bt[i]=rem_bt[i]-qt;
            else
                if(rem_bt[i]>=0)
                {
                    temp=rem_bt[i];
                    rem_bt[i]=0;
                }
                sq=sq+temp;
                tat[i]=sq;
        }
        if(n==count)
            break;
    }
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("\nThe Average Turnaround time is -- %f",atat);
    printf("\nThe Average Waiting time is -- %f ",awt);
    return 0;
}
