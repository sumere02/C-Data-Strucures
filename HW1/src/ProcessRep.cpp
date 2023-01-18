/* @Author
Student Name: Emir Sümer
Student ID : 150200112
Date: 14.19.2022
*/
#include <iostream> 
#include <stdio.h>
#include <string>
#include "ProcessRep.h"


using namespace std;

ProcessRep::ProcessRep(string processType, int processID, int deliverTime, int processTime)
{   
    mpNext = NULL;
    mProcessType = processType;
    mProcessID = processID;
    mDeliverTime = deliverTime;
    mProcessTime = processTime;
    remainingTime = processTime;
    startTime = -1;
    endTime = -1;
}

ProcessRep::~ProcessRep()
{
    if(this->mpNext != NULL){
        delete this->mpNext;
    }
}

ProcessRep* ProcessRep::getNext()
{
    return mpNext;
}

void ProcessRep::setNext(ProcessRep *next)
{
    mpNext = next;
}

string ProcessRep::getProcessType()
{
    return mProcessType;
}

void ProcessRep::setProcessType(string processType)
{
    mProcessType = processType;
}

int ProcessRep::getDeliverTime()
{
    return mDeliverTime;
}

void ProcessRep::setDeliverTime(int deliverTime)
{
    mDeliverTime = deliverTime;
}

int ProcessRep::getProcessID()
{
    return mProcessID;
}

void ProcessRep::setProcessID(int processID)
{
    mProcessID = processID;
}

int ProcessRep::getProcessTime()
{
    return mProcessTime;
}

void ProcessRep::setProcessTime(int ProcessTime)
{
    mProcessTime = ProcessTime;
}