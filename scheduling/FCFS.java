import java.util.*;
class FCFS
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int noOfProcesses;
		int temp, j, i, timeSpent = 0;
		float totalWaitingTime = 0 ,totalTurnAroundTime = 0;
		float averageWaitingTime, averageTurnAroundTime;
		
		System.out.println("Enter the number of processes:");
		noOfProcesses = sc.nextInt();
	 
		int burstTime[] = new int[noOfProcesses];
		int arrivalTime[] = new int[noOfProcesses];
		int waitingTime[] = new int [noOfProcesses];
		int turnAroundTime[] = new int [noOfProcesses];
		int process[] = new int [noOfProcesses];
		int ganttChart[][] = new int [noOfProcesses][2];
	 
		System.out.println("Enter the burst time and arrival time for each process:");
		for(i = 0; i < noOfProcesses; i++)
		{
			System.out.println("For process: " + (i + 1));
			System.out.println("Burst time:");
			burstTime[i] = sc.nextInt();
			System.out.println("Arrival time:");
			arrivalTime[i] = sc.nextInt();
			process[i] = i + 1;
		}
	 
		System.out.println("The processes, their burst times and their arrival times are:");
		System.out.println("Process\t| Burst Time\t| Arrival Time\t|");
		
		for(i = 0; i < noOfProcesses; i++)
		{
			System.out.println("P[" +  (process[i]) + "]\t|\t" + (burstTime[i]) + "\t|\t" + (arrivalTime[i]) + "\t|");
		}
				
		waitingTime[0] = 0;    //waiting time for first process is 0
		
		for(i = 0; i < noOfProcesses; i++)
		{
			for(j = i+1; j < noOfProcesses; j++)
			{   	
				if(arrivalTime[i] > arrivalTime[j])
				{	
					temp = burstTime[i];
					burstTime[i] = burstTime[j];
					burstTime[j] = temp;
					
					temp = process[i];
					process[i] = process[j];
					process[j] = temp;
					
					temp = arrivalTime[i];
					arrivalTime[i] = arrivalTime[j];
					arrivalTime[j] = temp;
				}
			}
		}
		
		for(i = 0; i < noOfProcesses; i++)
		{
			ganttChart[i][0] = process[i];
			timeSpent = timeSpent + burstTime[i];
			ganttChart[i][1] = timeSpent;
		}
		
		for(i = 1; i < noOfProcesses; i++)
		{
			waitingTime[i] = ganttChart[i-1][1] - arrivalTime[i];
			totalWaitingTime += waitingTime[i];

		}
		
		averageWaitingTime = totalWaitingTime / noOfProcesses;
		
		for(i = 0; i < noOfProcesses; i++)
		{
			turnAroundTime[i] = waitingTime[i] + burstTime[i];
			totalTurnAroundTime += turnAroundTime[i];
		}
		
		averageTurnAroundTime = totalTurnAroundTime / noOfProcesses;
		
		System.out.println("The waiting time and turnaround time of all processes as per their order of completion are: ");
		System.out.println("Process\t|Turnaround Time|Waiting Time");
		for(i = 0; i < noOfProcesses; i++)
		{
			System.out.println("P[" +  (process[i]) + "]\t|\t" + (turnAroundTime[i]) + "\t|\t" + (waitingTime[i]));
		}

		System.out.println("\nThe gantt Chart is:\n");
		for(i = 0; i < noOfProcesses; i++)
		{
			System.out.print("P[" + ganttChart[i][0] + "]\t|");
		}
		System.out.println();
		
		for(i = 0; i < noOfProcesses; i++)
		{
			System.out.print(ganttChart[i][1] + "msec\t|");
		}
		
		System.out.println("\n\nAverage waiting time is " + averageWaitingTime + " msec");
		System.out.println("Average turnaround time is " + averageTurnAroundTime + " msec");
	
	}
}