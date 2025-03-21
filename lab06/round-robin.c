#include "stdio.h";
#include "stdlib.h";

typedef struct {
  int id;
  int at; // arrival time
  int bt; // burst time
  int ct; // completion time
  int tat; // turnaround time
  int wt; // waiting time
  int rt; // remaining time
} Process;

void calculate_times(Process *processes, int n, int quantum) {
  int *remaining_time = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    remaining_time[i] = processes[i].bt;
  }

  int current_time = 0;
  int done = 0;

  while (!done) {
    done = 1;
    for (int i = 0; i < n; i++) {
      if (remaining_time[i] > 0) {
        done = 0;
        if (remaining_time[i] > quantum) {
          current_time += quantum;
          remaining_time[i] -= quantum;
        } else {
          current_time += remaining_time[i];
          processes[i].ct = current_time;
          processes[i].tat = processes[i].ct - processes[i].at;
          processes[i].wt = processes[i].tat - processes[i].bt;
          remaining_time[i] = 0;
        }
      }
    }
  }

  free(remaining_time);
}

void print_results(Process *processes, int n) {
  printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
  }
}

int main() {
  int n, quantum;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  Process *processes = (Process *)malloc(n * sizeof(Process));

  for (int i = 0; i < n; i++) {
    processes[i].id = i + 1;
    printf("Enter arrival time for process %d: ", i + 1);
    scanf("%d", &processes[i].at);
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].bt);
  }

  calculate_times(processes, n, quantum);
  print_results(processes, n);

  free(processes);
  return 0;
}
