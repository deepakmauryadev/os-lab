#include "stdio.h"

typedef struct {
  int pid, at, bt, ct, tat, wt;
} Process;

void fcfs(Process processes[], int n) {
  int current_time = 0;

  for (int i=0; i<n; i++) {
    Process *p = &processes[i];

    if (p->at > current_time) current_time = p->at;

    p->ct = current_time + p->bt;
    p->tat = p->ct - p->at;
    p->wt = p->tat - p->bt;

    current_time = p->ct;
  }
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process processes[n];

  printf("Enter process details (PID, AT, BT)\n");
  for (int i=0; i<n; i++) {
    Process *p = &processes[i];

    printf("Process %d: ", i);
    scanf("%d %d %d", &p->pid, &p->at, &p->bt);
  }

  fcfs(processes, n);

  printf("\n");
  printf("Process scheduling result (FCFS)\n");
  printf("\n");
  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i=0; i<n; i++) {
    Process *p = &processes[i];
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p->pid, p->at, p->bt, p->ct, p->tat, p->wt);
  }
  printf("\n");

  float avg_tat = 0, avg_wt = 0;

  for (int i=0; i<n; i++) {
    avg_tat += processes[i].tat;
    avg_wt += processes[i].wt;
  }

  avg_tat /= n;
  avg_wt /= n;

  printf("Average Turnaround Time: %.2f\n", avg_tat);
  printf("Average Waiting Time: %.2f\n", avg_wt);

  return 0;
}
