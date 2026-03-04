#include <stdio.h>
#include <stdlib.h>

int p,r,m,z,k,buf;
int a[10],avail[10],max[10][10],alloc[10][10],need[10][10];
int i,j,top;

void get()
{
    printf("\nENTER THE NUMBER OF PROCESSES: ");
    scanf("%d",&p);

    printf("\nENTER THE NUMBER OF RESOURCE TYPES: ");
    scanf("%d",&r);

    for(j=0;j<r;j++)
    {
        printf("\nENTER THE NUMBER OF RESOURCES FOR TYPE %d : ",j+1);
        scanf("%d",&avail[j]);
    }

    for(i=0;i<p;i++)
    {
        printf("\nENTER THE MAXIMUM NUMBER OF RESOURCES REQUIRED FOR PROCESS %d:\n",i+1);
        for(j=0;j<r;j++)
        {
            printf("For Resource type %d : ",j+1);
            scanf("%d",&max[i][j]);
        }
    }

    printf("\nENTER THE ALLOCATED INSTANCES:\n");
    for(i=0;i<p;i++)
    {
        printf("\nPROCESS %d:\n",i+1);
        for(j=0;j<r;j++)
        {
            printf("Resource Type - %d : ",j+1);
            scanf("%d",&m);

            if(m<=avail[j])
            {
                alloc[i][j]=m;
                avail[j]=avail[j]-m;
            }
            else
            {
                printf("\nALLOCATION EXCEEDS AVAILABLE RESOURCES.\n");
                alloc[i][j]=0;
            }
        }
    }
}

void disp1()
{
    printf("\nNEEDED RESOURCES:\n");
    for(i=0;i<p;i++)
    {
        printf("Process %d: ",i+1);
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
}

void seqnc()
{
    int count = 0;
    int finish[10] = {0};

    while(count < p)
    {
        int found = 0;

        for(i=0;i<p;i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j=0;j<r;j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    a[count++] = i+1;
                    finish[i] = 1;

                    for(k=0;k<r;k++)
                        avail[k] += alloc[i][k];

                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("\nSystem is NOT in safe state!\n");
            return;
        }
    }
}

void disp2()
{
    printf("\nSafe Sequence: ");
    for(i=0;i<p;i++)
        printf("P%d ",a[i]);
}

int main()
{
    get();
    disp1();
    seqnc();
    disp2();
    return 0;
}
