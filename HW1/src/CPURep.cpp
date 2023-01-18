/* @Author
Student Name: Emir Sümer
Student ID : 150200112
Date: 14.19.2022
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
// #include "node.h"
#include "ProcessRep.h"
#include "FIFORep.h"
#include "CPURep.h"

using namespace std;

CPURep::CPURep()
{
    mFinishedProcess = new FIFORep;
}

CPURep::~CPURep()
{
    delete mFinishedProcess;
}

ProcessRep* CPURep::runCPU(ProcessRep* p, int time)
{
    if(p != NULL){
        if(p->startTime == -1){
            p->startTime = time-1;
        } 
        p->remainingTime--;
        if(p->remainingTime == 0){
            p->endTime = time;
            mFinishedProcess->queue(p);
            return NULL;
        }
    }
    return p;
}

FIFORep* CPURep::getFinishedProcess()
{
    return mFinishedProcess;
}

void CPURep::setFinishedProcess(FIFORep* finishedProcess)
{
    mFinishedProcess = finishedProcess;
}