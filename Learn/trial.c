#include <stdio.h>
#include <stdlib.h>

int n, i, j, temp = 0, t, completionTime[10], tat[10], wt[10], burst[10] = {0}, arrival[10] = {0}, order[10] = {0};
float total_tat = 0, total_wt = 0;

void swap(int *xp, int *yp)
{
    int t = *xp;
    *xp = *yp;
    *yp = t;
}

void Sort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (arr[i] > arr[j])
            {
                swap(&arrival[i],&arrival[j]);
                swap(&burst[i], &burst[j]);
                swap(&order[i], &order[j]);
            }
}
int main()
{
    printf("\n-------------------------------");
    printf("\nPROGRAM  : FIRST COME FIRST SERVE \n\n");
    printf("---------------------------------\n");
    printf("Enter no of process : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nArrival time of process %d is :", i);
        scanf("%d", &arrival[i]);
        printf("\nBurst time of process %d is :", i);
        scanf("%d", &burst[i]);
        order[i] = i;
    }
	int smallest = arrival[1];
	int j = 1;
	int current_time = 0;
	for(int loop=1;loop<=n;loop++){
		if(smallest>arrival[i]){
			smallest = arrival[i];
			j = i;
		}
	}
	current_time = smallest;
	
	Sort(arrival,n);
	for(i=1;i<=n;i++){
		completionTime[i] = current_time + burst[i];
		wt[i] = current_time - arrival[i];
		if(wt[i]<0){
		wt[i] = abs(wt[i]);
		}
		tat[i] = wt[i] + burst[i];
		total_tat += tat[i];
		total_wt += wt[i];
	}

/*
    Sort(arrival, n);
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            temp = burst[i] + arrival[1];
            completionTime[i] = temp;
            tat[i] = completionTime[i] - arrival[i];
            wt[i] = tat[i] - burst[i];
            total_tat = total_tat + tat[i];
        }
        else
        {
            temp = temp + burst[i];
            completionTime[i] = temp;
            tat[i] = completionTime[i] - arrival[i];
            wt[i] = tat[i] - burst[i];
            if (wt[i] < 0)
            {
                completionTime[i] = completionTime[i] + abs(wt[i]);
                temp = completionTime[i];
                tat[i] += abs(wt[i]);
                wt[i] = 0;
            }
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
        }
    }
*/

	

    total_wt = total_wt / n;
    total_tat = total_tat / n;
    printf("\norder in which process get executed :\t");
    for (i = 1; i <= n; i++)
    {
        printf("%d \t ", order[i]);
    }
    printf("\n\n             arrival_time       Burst_time    Turn_around_time    waiting_time     completion time");
    for (i = 1; i <= n; i++)
    {
        printf("\nprocess%d            %d             %d                  %d                 %d               %d", order[i], arrival[i], burst[i], tat[i], wt[i], completionTime[i]);
    }
    printf("\n\n Average waiting time is %.2f", total_wt);
    printf("\n Average turn around time is is %.2f\n", total_tat);
}
