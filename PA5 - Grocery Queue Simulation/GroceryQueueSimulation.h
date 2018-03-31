/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA5 - Grocery Store Queue Simulation																						   *
*Date: March 2, 2018																																   *
*Description: GroceryQueueSimulation.h main header file.																					           *
********************************************************************************************************************************************************/
#pragma once

#include <cstdlib>
#include <ctime>
#include "Queue.h"

#define MINSHOP 1
#define MAXSHOP 1500
#define PRINT 10
#define TWENTYFOURHOURS 1440

void printWelcome(void);
void printInstructions(void);
int getOption(void);
int validateOption(void);
void initializeRand(void);
int programIntro(void);

void printEntrance(int customer, int minute, Data *newData, int line);
void printExit(Queue &line, int time, int lane);

