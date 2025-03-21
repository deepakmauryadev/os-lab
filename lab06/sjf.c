#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int at; // arrival time
    int bt; // burst time
    int ct; // completion time
    int tat; // turnaround time
    int wt; // waiting time
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_processes(Process *processes, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (processes[j].bt > processes[j + 1].bt) {
        swap(&processes[j], &processes[j + 1]);
      }
    }
  }
}

void calculate_times(Process *processes, int n) {
  int current_time = 0;

  for (int i = 0; i < n; i++) {
    if (current_time < processes[i].at) {
      current_time = processes[i].at;
    }
    processes[i].ct = current_time + processes[i].bt;
    processes[i].tat = processes[i].ct - processes[i].at;
    processes[i].wt = processes[i].tat - processes[i].bt;
    current_time = processes[i].ct;
  }
}

void print_results(Process *processes, int n) {
  printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
  }
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process *processes = (Process *)malloc(n * sizeof(Process));

  for (int i = 0; i < n; i++) {
    processes[i].id = i + 1;
    printf("Enter arrival time for process %d: ", i + 1);
    scanf("%d", &processes[i].at);
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].bt);
  }

  sort_processes(processes, n);
  calculate_times(processes, n);
  print_results(processes, n);

  free(processes);
  return 0;
}
