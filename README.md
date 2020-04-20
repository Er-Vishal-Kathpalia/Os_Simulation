# Os_Simulation
Question-Design a scheduler that can schedule the processes arriving system at periodical
intervals. Every process is assigned with a fixed time slice t milliseconds. If it is not able to
complete its execution within the assigned time quantum, then automated timer generates an
interrupt. The scheduler will select the next process in the queue and dispatcher dispatches the
process to processor for execution. Compute the total time for which processes were in the queue
waiting for the processor. Take the input for CPU burst, arrival time and time quantum from the
user.

FOR EVALUATION, 
FILE NAMED final_program.c has to be checked.

# Description
The Algorithm focuses on Time Sharing. In this algorithm, every process gets executed in a cyclic way. A certain time slice is defined in the system which is called time quantum. Each process present in the ready queue is assigned the CPU for that time quantum, if the execution of the process is completed during that time then the process will terminate else the process will go back to the ready queue and waits for the next turn to complete the execution.

# Explanation
1. Round Robin is the preemptive process scheduling algorithm.
2. Each process is provided a fix time to execute, it is called a quantum.
3. Once a process is executed for a given time period, it is preempted and other process executes for a given time period.
4. Context switching is used to save states of preempted processes.

# Algorithm
1.	Create an array arrival_time[], burst_time[] to keep track of arrival and burst time of processes.
2.	Create another array arr[] to store waiting times of processes temporarily in between execution.
3.	Initialize time: total = 0, counter = 0, wait time = 0, turnaround time = 0.
4.	Ask user for no of process and store it in limit.
5.	Repetitively ask user to give input for arrival time, burst time up to limit.
6.	Ask user to enter time quantum and store it into time quantum.
7.	Keep traversing the all processes while all processes are not done. Do following for i'th process if it is not done yet. 
a.	If temp[i] <= time_quantum && temp[i] > 0 
(i)	 total = total + temp[i]; 
(ii)	 temp[i] = 0; 
(iii)	 counter = 1; 
b.	 Else if temp[i] > 0 
(i)	 temp[i] = temp[i] - time_quantum; 
(ii)	 total = total + time_quantum; 
c.	 If temp[i] == 0 && counter == 1 
(i)	  x--;
(ii)	 (print burst_time[i], total, arrival_time[i], total - arrival_time[i] - burst_time[i]);
(iii)	 wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
(iv)	 turnaround_time = turnaround_time + total - arrival_time[i]; 
(v)	 counter = 0; 
d.	 If i == limit – 1 
e.	 i = 0;
f.	 Else if arrival_time[i + 1] <= total 
(i)	 i++; 
g.	 Else 
(i)	 i = 0;
8.	Print total waiting time - wait_time, average waiting time - wait_time/limit, average turnaround time - average_turnaround_time/limit.

# Complexity
•	Complexity of initialization of variables is O(1). total = 0 counter = 0 wait time = 0 turnaround time = 0.
•	Complexity for initializing arrays with for loop is O(limit). 
for(i = 0; i < limit; i++) { … }
•	Complexity of calculating waiting and turnaround time is O(limit). 
for(total = 0, i = 0; x != 0;) { …. } 
Hence, the complexity of implemented algorithm is O(limit).

# Constraints
1.	If we have large number of processes and a process with very less burst time. According to round robin it will have to wait for very long time if burst time of other processes is large and its turn comes late.
2.	If we have some processes running according to round robin and we have a process whose arrival time is after the completion of those processes, then that process will not execute. If we want that all the processes should execute successfully then the arrival time of other process must be less than or equal to the completion time of the running processes.

# Test Case
**Example.** Assume that there are 4 Processes P1, P2, P3, P4. The arrival time of the Processes are 0, 1, 2, 4 respectively and the Burst time of the processes are 5, 4, 2, 1 respectively. Assume the time Quantum of 2units. Calculate the Average waiting time and Average turnaround time of given processes.

**Explanation:** Firstly P1 process is taken from the ready queue to running queue and executed for 2 units. Then process P2 from ready queue and similarly process P3 and then P4. As P3 and P4 has 2, 1 burst time so they are successfully executed in first round only. But Process P1 and P2 left for P1 = 5 – 2 = 3 time slice and P2 = 4 – 2 = 2 time slice so firstly P1 is picked from ready queue and then Process P2 from ready queue in second round. In third round only process P1 is left for P1 = 3 – 2 = 1 time slice. So at last Process P1 is executed successfully.

The following is the table for the processes
**Process ID	Arrival_Time	Burst_Time	Completion_Time	Turnaround_Time	Waiting_Time	Response_Time

**P1       	        0	           5	             12	            12	          7	             0**

**P2	                1          	   4	             11	            10	          6	             1**

**P3	                2	           2	              6	             4	          2	             2**

**P4	                4	           1	              7	             3            2              2**
Average waiting time = (7+6+2+2)/4 = 4.25
Average turnaround time = (12+10+4+3)/4 = 7.25

# Output of the Program
To get output Run **final_program.c** has to run.

Execute and run the file.


