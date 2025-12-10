⦁	PRIORITY:

AIM: To write a c program to simulate the CPU scheduling priorityalgorithm.

DESCRIPTION:

To calculate the average waiting time in the priority algorithm, sort the burst times according to their priorities and then calculate the average waiting time of the processes. The waiting time of each process is obtained by summing up the burst times of all the previous processes.

ALGORITHM:

Step 1: Start the process

Step 2: Accept the number of processes in the ready Queue

Step 3: For each process in the ready Q, assign the process id and accept the CPU burst time

Step 4: Sort the ready queue according to the priority number.

Step 5: Set the waiting of the first process as ‗0„ and its burst time as its turnaround time Step 6: Arrange the processes based on process priority

Step 7: For each process in the Ready Q calculate Step 8:for each process in the Ready Q calculate

⦁	Waiting time(n)= waiting time (n-1) + Burst time (n-1)

⦁	Turnaround time (n)= waiting time(n)+Burst time(n)

Step 9: Calculate

⦁	Average waiting time = Total waiting Time / Number of process

⦁	Average Turnaround time = Total Turnaround Time / Number of process Print the results in an order.


Step10: Stop
