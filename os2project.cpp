//https://github.com/vishnu190/operating-system.git
#include<iostream>

using namespace std;


int arrival_time1[30],arrival_time2[30],arrival_time3[30];

int burst_time1[30],burst_time2[30],burst_time3[30];

int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;

int time_quantum2=2;

int total,x,temp[30],counter=0;

float avg_waiting_time=0,avg_turnaround_time=0;

void project()
{
	printf("TIMW QUANTUM IS FIXED----> 2"); 
    
	for(i=0;i<j;i++)
	{
		temp[i]=burst_time1[i];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(i=0,total=0;x!=0;) 
    { 
    	if(temp[i]<=time_quantum2&&temp[i]>0) 
        { 
            total=total+temp[i]; 
            temp[i]=0; 
            counter=1; 
        } 
        else if(temp[i]>0) 
        { 
            temp[i]=temp[i]-time_quantum2; 
            total=total+time_quantum2; 
        } 
        if(temp[i]==0&&counter==1) 
        { 
            x--; 
            printf("\nProcess[%d]\t%d\t%d\t%d",i+1,burst_time1[i],total-arrival_time1[i],total-arrival_time1[i]-burst_time1[i]);
            avg_waiting_time=avg_waiting_time+total-arrival_time1[i]-burst_time1[i]; 
            avg_turnaround_time=avg_turnaround_time+total-arrival_time1[i]; 
            counter = 0; 
        } 
if(i==j-1) 
{
i=0; 
}
else if(arrival_time1[i+1]<=total) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
    avg_waiting_time=avg_waiting_time/j;
    avg_turnaround_time=avg_turnaround_time/j;
    printf("\nAverage Waiting Time:%f",avg_waiting_time); 
    printf("\nAverage Turnaround Time:%f\n",avg_turnaround_time); 
}
int main()
{
printf("Enter the no. of process you want to enter\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter details of process[%d]\n",i+1);
printf("Arrival Time:");
scanf("%d",&at[i]);
printf("Burst Time:");
scanf("%d",&bt[i]);
printf("ENTER PRIORITY:");
		scanf("%d",&pr[i]);
		
	}

for(i=0;i<n;i++)
	
{
if(pr[i]>=1&&pr[i]<=5)
	{
		printf("Process[%d] belongs to Queue 1\n",i+1);
		arrival_time1[j]=at[i];
		burst_time1[j]=bt[i];
		j++;
}
		
	else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			k++;
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
		}
	}
	
	project();
	return 0;
}


