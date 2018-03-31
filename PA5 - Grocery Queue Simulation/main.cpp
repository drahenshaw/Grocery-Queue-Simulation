/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: main.cpp source file.																											           *
********************************************************************************************************************************************************/

#include "GroceryQueueSimulation.h"

int main(void)
{
	Queue express, normal;

	int n = programIntro(); //prints instructions, get number of minutes to simulate	
	int elapsedTime = 0;
	int dailyReset = 0;

	int expressCustomers = 1, headWaitTime = 0, flag = 0, reset = 0;
	int normalCustomers = 1, headWaitTimeN = 0, flagN = 0, resetN = 0;
	
	int expressArrival = generateExpressTime();
	int normalArrival = generateNormalTime();
	
	Data *newExpress = nullptr, *newNormal = nullptr;
		
	do
	{
		//Express Queue
		if (expressArrival == 0)
		{
			express.enqueue();										//make new QueueNode	
			newExpress = newExpress->makeData(expressCustomers);	//make new Data Node				
			express.getTail()->setData(newExpress);					//attach data to Queue
			printEntrance(expressCustomers++, elapsedTime, newExpress, EXPRESS);	//announce to screen								
			newExpress->setTotalTime(express.getQueueTime());		//find total time			
			expressArrival = generateExpressTime();					//get next arrival time	
		}
		if (!express.isEmpty() && reset == 1) //decrement wait time at head of queue
		{
			headWaitTime--;
			if (headWaitTime == 0) //flag for dequeue if wait time hits zero
			{
				flag = 1;
				reset = 0;
			}
		}
		if (!express.isEmpty() && flag == 1) //head node flagged for dequeue
		{		
			printExit(express, elapsedTime, EXPRESS); //announce to screen
			express.dequeue();				 //remove head node from queue
			flag = 0;						 //reset flag

			if (!express.isEmpty())			 //get next head wait time after dequeue
			{
				headWaitTime = express.getHead()->getData()->getServiceTime();				
				reset = 1;
			}
		}
		if (!express.isEmpty() && reset == 0) //get wait time if queue is populated
		{
			headWaitTime = express.getHead()->getData()->getServiceTime();
			reset = 1;						  //prevent overwrite of a new wait time
		}	
		
		//Normal Queue
		if (normalArrival == 0)
		{
			normal.enqueue();										//make new QueueNode	
			newNormal = newNormal->makeData(normalCustomers);		//make new Data Node				
			normal.getTail()->setData(newNormal);					//attach data to Queue
			printEntrance(normalCustomers++, elapsedTime, newNormal, NORMAL);	//announce to screen							
			newNormal->setTotalTime(normal.getQueueTime());			//find total time			
			normalArrival = generateNormalTime();					//get next arrival time	
		}
		if (!normal.isEmpty() && resetN == 1)
		{
			headWaitTimeN--;
			if (headWaitTimeN == 0)
			{
				flagN = 1;
				resetN = 0;
			}
		}
		if (!normal.isEmpty() && flagN == 1) //dequeue
		{
			printExit(normal, elapsedTime, NORMAL);
			normal.dequeue();
			flagN = 0;

			if (!normal.isEmpty())
			{
				headWaitTimeN = normal.getHead()->getData()->getServiceTime();
				resetN = 1;
			}
		}
		if (!normal.isEmpty() && resetN == 0) 
		{
			headWaitTimeN = normal.getHead()->getData()->getServiceTime();
			resetN = 1;
		}

		expressArrival--; //adjust counters
		normalArrival--;
		elapsedTime++;
					
		if (elapsedTime >= PRINT && elapsedTime % PRINT == 0) //print lines every 10 minutes
		{
			cout << endl << "Elapsed Time: " << elapsedTime << endl;
			cout << "Express Queue: " << endl;
			express.printQueueRecursive(express.getHead());

			cout << "Normal Queue: " << endl;
			normal.printQueueRecursive(normal.getHead());
			cout << endl;
		}	

		if (elapsedTime >= TWENTYFOURHOURS && dailyReset == 0)
		{
			expressCustomers = normalCustomers = 1;
			dailyReset = 1;
		}	

	} while (elapsedTime < n);
	
	return 0;
}