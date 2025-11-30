#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
  int pid;
  int arrival_time;
  int burst_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
  int start_time;
} Process;

void sortByArrival(Process p[], int n) {
  Process temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (p[j].arrival_time > p[j + 1].arrival_time ||
          (p[j].arrival_time == p[j + 1].arrival_time &&
           p[j].pid > p[j + 1].pid)) {

        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
}

void fcfs(Process p[], int n) {
  int current_time = 0;
  float total_waiting_time = 0;
  float total_turnaround_time = 0;

  printf("\n===GANTT CHART===\n");
  printf("+-------------------+\n");

  for (int i = 0; i < n; i++) {
    if (current_time < p[i].arrival_time) {
      printf("| Idle (%d -> %d) ", current_time, p[i].arrival_time);
      current_time = p[i].arrival_time;
    }

    p[i].start_time = current_time;
    p[i].completion_time = current_time + p[i].burst_time;
    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

    current_time = p[i].completion_time;

    printf("| P%d (%d-%d) ", p[i].pid, p[i].start_time, p[i].completion_time);

    total_turnaround_time += p[i].turnaround_time;
    total_waiting_time += p[i].waiting_time;
  }

  printf("\n+-------------------+\n");
  printf("\nPID\tArrival\tBurst\tStart\tComplete\tTAT\tWait");
  printf("\n----------------------------------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time,
           p[i].burst_time, p[i].start_time, p[i].completion_time,
           p[i].turnaround_time, p[i].waiting_time);
  }
  printf("\n----------------------------------------------------\n\n");

  printf("Average Waiting time\t: %.2f\n", total_waiting_time / n);
  printf("Average Turnaround time\t: %.2f\n", total_turnaround_time / n);
}

int main() {

  int n, i;
  printf("FCFS\n");
  printf("======");

  printf("\nEnter the no.of processes: ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("\nNo processes");
    return 0;
  }

  Process *processes = (Process *)malloc(n * sizeof(Process));

  if (!processes) {
    fprintf(stderr, "\nmemory allocation failed\n");
    return 1;
  }

  printf("\nEnter Arrival Time and Burst Time for each process:\n");
  for (i = 0; i < n; i++) {
    int arrival_time = 0;
    int burst_time = 0;

    processes[i].pid = i + 1;
    printf("Process P%d:\n", i + 1);
    do {
      printf("Arrival Time: ");
      scanf("%d", &arrival_time);
    } while (arrival_time < 0);

    processes[i].arrival_time = arrival_time;

    do {

      printf("Burst Time: ");
      scanf("%d", &burst_time);
    } while (burst_time <= 0);

    processes[i].burst_time = burst_time;
  }

  sortByArrival(processes, n);

  fcfs(processes, n);

  free(processes);

  return 0;
}
