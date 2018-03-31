/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: GroceryQueueSimulation.cpp source file for non member functions.																											           *
********************************************************************************************************************************************************/
#include "GroceryQueueSimulation.h"

void printWelcome(void)
{
	cout << "Welcome to David's Grocery Line Simulator." << endl;
}

void printInstructions(void)
{
	cout << "How many minutes (int value) would you like to shop today?: " << endl;
}

int getOption(void)
{
	int option = 0;	
	cin >> option;
	return option;
}

int validateOption(void)
{
	int valid = 0;
	bool success = false;

	do
	{
		valid = getOption();
		if (valid < MINSHOP || valid > MAXSHOP)
		{
			cout << "Please enter a valid time between 1 - 1500 minutes." << endl;
		}
		else
		{
			success = true;
		}
	} while (!success);
	return valid;
}

int programIntro(void) //Starts rand, prints welcome & validates menu option
{
	int valid = 0;
	initializeRand();
	printWelcome();
	printInstructions();
	valid = validateOption();
	cout << endl;
	return valid;
}

void printEntrance(int customer, int minute, Data *newData, int line) //prints customers entering a line
{
	if (line == EXPRESS)
	{
		cout << "Customer: " << customer << " entered Express Line at minute: " << minute;		
	}
	else //NORMAL
	{
		cout << "Customer: " << customer << " entered Normal Line at minute: " << minute;		
	}	

	cout << " with a service time of: " << newData->getServiceTime() << endl;
}

void printExit(Queue &line, int time, int lane) //prints customers exiting a line
{
	cout << "Customer: " << line.getHead()->getData()->getCustomerNumber();

	if (lane == EXPRESS)
	{
		cout << " exit Express Line at minute: " << time << endl;
	}
	else
	{
		cout << " exit Normal Line at minute: " << time << endl;
	}
}

void initializeRand(void)
{
	srand(time(NULL));
}
