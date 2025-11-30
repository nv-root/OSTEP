**Cooperative:** Processes give up control to os

**Non-Cooperative:** timer interrupts

## Scheduling

### Metrics

1. **T<sub>_turnaround_</sub>** = T<sub>_completion_</sub> - T<sub>_arrival_</sub>

2. **T<sub>_response_</sub>** = T<sub>_firstrun_</sub> - T<sub>_arrival_</sub>

### Algorithms

1. **FCFS** (non-preemptive)

   problems : convoy effect

2. **SJF** (non-preemptive)

   problems : convoy effect (for late arrivals), considering initial jobs arrive at the same time

3. **STCF** (preemptive)

4. **RR** (preemptive, time-sliced, good for response time)

   problems : context-switching overhead if time slice is too short

5. **MLFQ** (uses priority queues)

   problems : starvation, gaming the scheduler

   **Rules**

   - priority(A) > priority(B) ? run(A)
   - priority(A) == priority(B) ? run(A, B) in RR
   - new jobs are placed in the highest priority queue initially (thinks all jobs are short)
   - if a job uses up its time-slice while running, its priority is reduced (realizes they're not short)
   - if a job gives up the cpu before its time-slice, its priority is kept the same (means it's waiting for I/O and is interactive. so priority is not changed)
   - periodically place the low priority jobs in the high priority queue (solution to starvation & in the job needs - may be it needs to be interactive after some time)

   **_re-written rule_**

   - if a job has used the allocated time at a level, it's demoted (solution to gaming the scheduler)
