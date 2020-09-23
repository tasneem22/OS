#include<stdio.h>
void findWaitingTime(int n, int bt[], int wt[] , int arrival_time[])
{
    int i;
	wt[0] = 0;
	for (i = 1; i < n ; i++ ){
		wt[i] = (bt[i-1] + wt[i-1]) - arrival_time[i] ;
		if(wt[i] < 0)wt[i] = 0;
		}
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[] , int arrival_time[])
{
    int i;
	for (i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int n, int bt[] , int arrival_time[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0 , completion_time[n];

	findWaitingTime(n, bt, wt , arrival_time);

	findTurnAroundTime(n, bt, wt, tat , arrival_time);

	printf("Process ID   Burst time   Waiting time   Turn around time   completion time\n");


	int i;
	for(i = 0;i < n;++i)
        completion_time[i] = tat[i]+arrival_time[i];
	for (i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("   	       %d ", bt[i]);
		printf("	       %d",wt[i]);
		printf("	       %d",tat[i]);
		printf("	       %d\n",completion_time[i]);
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
}

int main()
{
    int n , i;
    scanf("%d",&n);
    int arrival_time[n] , burst_time[n];
    for(i = 0;i < n;++i)scanf("%d",arrival_time+i);
	for(i = 0;i < n;++i)scanf("%d",burst_time+i);
	findavgTime(n, burst_time , arrival_time);
	return 0;
}
