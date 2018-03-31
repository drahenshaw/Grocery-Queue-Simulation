/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: Queue.h header file.																											           *
********************************************************************************************************************************************************/
#pragma once

#include <iostream>
#include "QueueNode.h"

using std::cout;
using std::cin;
using std::endl;

class Queue
{
public:
	Queue();
	~Queue();

	Queue(Queue &copy);

	QueueNode *getHead();
	QueueNode *getTail();
	
	void setHead(QueueNode *newHead);
	void setTail(QueueNode *newTail);

	void enqueue();
	Data *dequeue(); 

	bool isEmpty();
	void printQueueRecursive(QueueNode *pNode);
	
	int getQueueTime();

private:
	QueueNode *pHead;
	QueueNode *pTail;
};
