#include "stdio.h"

typedef struct {
  int pid;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
} Process;

int compare_process(Process *p1, Process *p2) {}

void sjf(Process processes[], int n) {
  int current_time = 0;
  int completed_processes = 0;
  for (int i=0; i<n; i++) processes[i].ct = 0;

  while (completed_processes < n) {
    int sortest_job_index = -1;
    int sortest_bt = -1;

    for (int i=0; i<n; i++) {
      Process *p = &processes[i];
      if (p->ct == 0 && p->at <= current_time) {
        if (sortest_job_index == -1 || p->bt < sortest_bt) {
          sortest_job_index = i;
          sortest_bt = p->bt;
        }
      }
    }

    if (sortest_job_index == -1) {
      current_time++;
      continue;
    }

  }
}
