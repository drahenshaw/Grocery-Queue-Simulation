/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: Queue.cpp source file.																										           *
********************************************************************************************************************************************************/

#include "Queue.h"

Queue::Queue()
{
	pHead = pTail = nullptr;	
}

Queue::~Queue()
{	
	Data *pMem = nullptr;

	while (pHead != nullptr)
	{
		pMem = dequeue();

		if (pMem != nullptr)
		{
			delete pMem;
		}
	}	
}

Queue::Queue(Queue & copy)
{
	//Shallow copy or deep copy?
}

QueueNode * Queue::getHead()
{
	return pHead;
}

QueueNode * Queue::getTail()
{
	return pTail;
}

void Queue::setHead(QueueNode * newHead)
{
	pHead = newHead;
}

void Queue::setTail(QueueNode * newTail)
{
	pTail = newTail;
}

void Queue::enqueue()
{
	QueueNode *pMem = nullptr;

	pMem = new QueueNode(); //constructor for pointers only? need to allocate space for the actual data?
	
	if (pMem != nullptr)
	{
		if (isEmpty()) //only one node in queue
		{
			pHead = pTail = pMem; 
		}
		else
		{
			pTail->setNext(pMem);
			pTail = pMem; 
		}		
	}
}

Data * Queue::dequeue()
{
	Data *deleted = nullptr;

	if (!isEmpty())
	{
		if (pHead == pTail) //single node in queue
		{
			deleted = pHead->getData();
			delete pHead;
			pHead = pTail = nullptr;
		}
		else //more than single node
		{
			QueueNode *pTemp = pHead;
			deleted = pHead->getData();
			pHead = pHead->getNext();
			delete pTemp;
		}
	}
	return deleted;
}

bool Queue::isEmpty()
{
	if (pHead == nullptr) { return true; }
	else { return false; }	
}

void Queue::printQueueRecursive(QueueNode *pNode)
{
	if (pNode != nullptr)
	{
		Data *pTemp = pNode->getData(); //get memory location of data in node
		cout << endl << *pTemp; //overload extraction to print details
		printQueueRecursive(pNode->getNext()); //move to next node
	}
}

int Queue::getQueueTime()
{
	int queueTime = 0;
	QueueNode *pCur = pHead;

	if (!isEmpty()) //if list isnt empty
	{
		while (pCur != nullptr) //loop through summing service times
		{
			queueTime += pCur->getData()->getServiceTime();
			pCur = pCur->getNext();
		}
	}
	return queueTime;
}
