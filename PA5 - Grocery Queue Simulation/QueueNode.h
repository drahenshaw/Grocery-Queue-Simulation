/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: QueueNode.h header file.																										           *
********************************************************************************************************************************************************/
#pragma once

#include <iostream>
#include "Data.h"

class QueueNode
{
public:
	QueueNode();
	~QueueNode();

	QueueNode(QueueNode &copy);

	Data *getData();
	QueueNode *getNext();

	void setData(Data *newpData);
	void setNext(QueueNode *ptrNext);

private:
	Data *pData;
	QueueNode *pNext;
};
