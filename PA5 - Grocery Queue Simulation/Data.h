/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: Data.h header file.																											           *
********************************************************************************************************************************************************/
#pragma once

#include <iostream>
using std::ostream;
using std::endl;

#define ERANDMOD 5
#define NRANDMOD 6
#define EXPRESS 1
#define NORMAL 3

class Data
{
public: // Member functions
	Data(int newCustomerNumber = 0, int newServiceTime = 0, int newTotalTime = 0);
	~Data();
	Data(Data &copy);

	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);

	//Others?
	Data *makeData(int customer);

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!

ostream & operator << (ostream &lhs, Data &rhs);

int generateExpressTime();
int generateNormalTime();