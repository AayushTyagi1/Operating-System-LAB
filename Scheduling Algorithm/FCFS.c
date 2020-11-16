#include <stdio.h>
#define max 20

void waiting_time(int n, int bt[], int wt[], int at[]) {
    int t[n];
    t[0] = 0, wt[0] = 0;
    for (int i = 1; i < n; i++) {
        t[i] = t[i - 1] + bt[i - 1];
        wt[i] = t[i] - at[i];
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void TurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void avgtime(int n, int bt[], int at[]) {
    int wt[n], tat[n], p[n], total_wt = 0, total_tat = 0, temp, j;
    float avg_waitngT,avg_TatT;
    waiting_time(n, bt, wt, at);
    TurnAroundTime(n, bt, wt, tat);
    for (int i = 0; i < n; i++) {
        int t;
        temp = at[i];
        t = i;
        j = i - 1;
        while ((temp < at[j]) && (j >= 0)) {
            at[j + 1] = at[j];
            p[j + 1] = j;
            j--;
        }
        at[j + 1] = temp;
        p[j + 1] = t;
    }
    printf("GANTT CHART : ");
    for (int j = 0; j < n; j++) {
        printf("P%d", p[j]);
        printf("|");
    }
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
    avg_waitngT = (float) total_wt / (float) n;
    avg_TatT = (float) total_tat / (float) n;
    printf("\nAvg. Waiting Time : %0.2f", avg_waitngT);
    printf("\nAvg Turn Around Time : %0.2f", avg_TatT);
    printf("\n");
}

int main() {
    int n, bt[max], at[max];
    printf("Enter Number of Process : ");
    scanf("%d", & n);
    printf("Enter Burst Time : ");
    for (int i = 0; i < n; i++)
        scanf("%d", & bt[i]);
    printf("Enter Arrival Time : ");
    for (int i = 0; i < n; i++)
        scanf("%d", & at[i]);

    avgtime(n, bt, at);

    return 0;
}

