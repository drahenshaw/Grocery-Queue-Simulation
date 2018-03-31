/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: QueueNode.cpp source file.																									           *
********************************************************************************************************************************************************/

#include "QueueNode.h"

QueueNode::QueueNode()
{
	pData = nullptr;
	pNext = nullptr;
}

QueueNode::~QueueNode()
{
	//
}

QueueNode::QueueNode(QueueNode & copy)
{
	pData = copy.getData();
	pNext = copy.getNext();
}

Data * QueueNode::getData()
{
	return pData;
}

QueueNode * QueueNode::getNext()
{
	return pNext;
}

void QueueNode::setData(Data *newpData)
{
	pData = newpData;
}

void QueueNode::setNext(QueueNode * ptrNext)
{
	pNext = ptrNext;
}
