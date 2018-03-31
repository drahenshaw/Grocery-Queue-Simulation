/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: Data.cpp source file.																											           *
********************************************************************************************************************************************************/

#include "Data.h"

Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	this->customerNumber = newCustomerNumber;
	this->serviceTime = newServiceTime;
	this->totalTime = newTotalTime;
}

Data::~Data()
{
	//
}

Data::Data(Data & copy)
{
	customerNumber = copy.customerNumber;
	serviceTime = copy.serviceTime;
	totalTime = copy.totalTime;
}

int Data::getCustomerNumber()
{
	return customerNumber;
}

int Data::getServiceTime()
{
	return serviceTime;
}

int Data::getTotalTime()
{
	return totalTime;
}

void Data::setCustomerNumber(int newCustomerNumber)
{
	customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime)
{
	serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime)
{
	totalTime = newTotalTime;
}

Data * Data::makeData(int customer)
{
	Data *data = new Data();
	data->setCustomerNumber(customer);
	data->setServiceTime(generateExpressTime());

	return data;
}

ostream & operator << (ostream &lhs, Data &rhs)
{
	lhs << "Customer Number: " << rhs.getCustomerNumber() << endl;
	lhs << "Service Time: " << rhs.getServiceTime() << endl;
	lhs << "Total Time: " << rhs.getTotalTime() << endl << endl;
	return lhs;
}

int generateExpressTime()
{
	return rand() % ERANDMOD + EXPRESS;
}

int generateNormalTime()
{
	return rand() % NRANDMOD + NORMAL;
}