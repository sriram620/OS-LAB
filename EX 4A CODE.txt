#include <stdio.h>

int main() 
{
    int i, n;
    int burst[10], wait[10], turn[10];
    float w = 0, t = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d", &burst[i]);
    }

    // First process waiting time is 0
    wait[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++)
    {
        wait[i] = wait[i-1] + burst[i-1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++)
    {
        turn[i] = wait[i] + burst[i];
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n\n");
    for(i = 0; i < n; i++)
        printf("\tP%d\t|", i+1);

    printf("\n0");

    for(i = 0; i < n; i++)
        printf("\t\t%d", turn[i]);

    // Calculate averages
    for(i = 0; i < n; i++)
    {
        w += wait[i];
        t += turn[i];
    }

    printf("\n\nAverage Waiting Time = %.2f", w/n);
    printf("\nAverage Turnaround Time = %.2f\n", t/n);

    return 0;
}
