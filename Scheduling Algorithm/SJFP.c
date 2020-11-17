#include<stdio.h>
int main () {
    int at[10], bt[10], rt[10], endTime, i, smallest, processGantt[100],
    remain = 0, n, time, sum_wait = 0, sum_turnaround = 0;
    printf ("Enter no of Processes : ");
    scanf ("%d", &n);
    printf ("\nEnter arrival time : ");
    for (i = 0; i < n; i++)
      scanf ("%d", &at[i]);
    printf ("Enter burst time : ");
    for (i = 0; i < n; i++) {
      scanf ("%d", &bt[i]);
      rt[i] = bt[i];
    }
    rt[9] = 9999;
    for (time = 0; remain != n; time++) {
      smallest = 9;
      for (i = 0; i < n; i++) {
        if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
          processGantt[time] = i;
          smallest = i;
        }
    }
    rt[smallest]--;
    if (rt[smallest] == 0) {
      remain++;
      endTime = time + 1;
      sum_wait += endTime - bt[smallest] - at[smallest];
      sum_turnaround += endTime - at[smallest];
    }
    }
    printf ("\nGantt's Chart : ");
    for (i = 0; i <= time; i++) {
      if (processGantt[i] == processGantt[i + 1])
    continue;
      else
    printf ("P%d ", processGantt[i]);
    }
    printf ("\n\nAverage waiting time : %.2f\n", sum_wait * 1.0 / n);
    printf ("Average Turnaround time : %.2f\n\n", sum_turnaround * 1.0 / 5);
    return 0;
}

