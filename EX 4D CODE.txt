#include <stdio.h>

// Function to calculate Waiting Time
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];

    // Copy burst time into remaining burst time array
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int time = 0;  // Current time

    while (1)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > quantum)
                {
                    time += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }
}

// Function to calculate Turnaround Time
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate Average Times
void findAverageTimes(int processes[], int n, int wt[], int tat[])
{
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

// Round Robin Scheduling
void roundRobinScheduling(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               processes[i], bt[i], wt[i], tat[i]);
    }

    findAverageTimes(processes, n, wt, tat);
}

int main()
{
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobinScheduling(processes, n, burst_time, quantum);

    return 0;
}
