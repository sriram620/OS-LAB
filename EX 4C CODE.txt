#include <stdio.h>

struct process {
    int id;         // Process ID
    int bt;         // Burst Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
    int priority;   // Priority
};

// Function to calculate Waiting Time
void findWaitingTime(struct process proc[], int n) 
{
    proc[0].wt = 0;  // First process waiting time = 0

    for (int i = 1; i < n; i++) 
    {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;
    }
}

// Function to calculate Turnaround Time
void findTurnaroundTime(struct process proc[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        proc[i].tat = proc[i].wt + proc[i].bt;
    }
}

// Function to calculate and print average times
void findAverageTimes(struct process proc[], int n) 
{
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) 
    {
        totalWT += proc[i].wt;
        totalTAT += proc[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
}

// Priority Scheduling Function
void priorityScheduling(struct process proc[], int n) 
{
    struct process temp;

    // Sort processes based on priority (Lower number = Higher priority)
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (proc[i].priority > proc[j].priority) 
            {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    // Calculate waiting and turnaround time
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    // Display results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) 
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].id, proc[i].bt, proc[i].priority,
               proc[i].wt, proc[i].tat);
    }

    // Print averages
    findAverageTimes(proc, n);
}

int main() 
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for (int i = 0; i < n; i++) 
    {
        proc[i].id = i + 1;

        printf("\nEnter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &proc[i].bt);

        printf("Enter Priority for Process P%d: ", i + 1);
        scanf("%d", &proc[i].priority);
    }

    priorityScheduling(proc, n);

    return 0;
}
