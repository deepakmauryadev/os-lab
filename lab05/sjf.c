#include <stdio.h>

typedef struct {
  int pid, at, bt, ct, tat, wt;
} Process;

void sjf(Process processes[], int n) {
  int current_time = 0;
  int completed_processes = 0;
  for (int i = 0; i < n; i++) processes[i].ct = 0;

  while (completed_processes < n) {
    int shortest_job_index = -1;
    int shortest_bt = -1;

    for (int i = 0; i < n; i++) {
      Process *p = &processes[i];
      if (p->ct == 0 && p->at <= current_time) {
        if (shortest_job_index == -1 || p->bt < shortest_bt) {
          shortest_job_index = i;
          shortest_bt = p->bt;
        }
      }
    }

    if (shortest_job_index == -1) {
      current_time++;
      continue;
    }

    Process *p = &processes[shortest_job_index];
    current_time += p->bt;
    p->ct = current_time;
    p->tat = p->ct - p->at;
    p->wt = p->tat - p->bt;
    completed_processes++;
  }
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  
  Process processes[n];
  printf("Enter PID, Arrival Time, and Burst Time for each process:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &processes[i].pid, &processes[i].at, &processes[i].bt);
  }
  
  sjf(processes, n);

  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    Process *p = &processes[i];
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p->pid, p->at, p->bt, p->ct, p->tat, p->wt);
  }
  
  return 0;
}
