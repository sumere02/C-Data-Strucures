/* @Author
Student Name: Emir Sümer
Student ID : 150200112
Date: 14.19.2022
*/
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include "SchedulerRep.h"

using namespace std;

SchedulerRep::SchedulerRep()
{
    mpProcessFIFO[0] = new FIFORep;
    mpProcessFIFO[1] = new FIFORep;
    mpProcessFIFO[2] = new FIFORep;
    mpRunningProcess = NULL;
    pCpuObj = new CPURep;
    timeSliceCount = 0;
    totalTime = 0;
}
SchedulerRep::~SchedulerRep()
{
    delete mpProcessFIFO[0];
    delete mpProcessFIFO[1];
    delete mpProcessFIFO[2];
    delete mpRunningProcess;
    delete pCpuObj;
}

FIFORep* SchedulerRep::getProcessFIFO(int index)
{
    return mpProcessFIFO[index];
}

void SchedulerRep::setProcessFIFO(FIFORep* fifo, int index)
{
    mpProcessFIFO[index] = fifo;
}

void SchedulerRep::setRunningProcess(ProcessRep* p)
{
    mpRunningProcess = p;
}

ProcessRep* SchedulerRep::getRunningProcess()
{
    return mpRunningProcess;
}

void SchedulerRep::pushProcess(ProcessRep* p)
{
    if(p != NULL){
        if(p->getProcessType() == "A"){
            mpProcessFIFO[0]->queue(p);
        }
        else if(p->getProcessType() == "B"){
            mpProcessFIFO[1]->queue(p);
        }
        else{
            mpProcessFIFO[2]->queue(p);
        }
    }       
}

ProcessRep* SchedulerRep::popProcess()
{
    ProcessRep *temp = NULL;
    if(mpProcessFIFO[0]->getHead() != NULL){
        temp = mpProcessFIFO[0]->dequeue(); 
    }
    else if(mpProcessFIFO[1]->getHead() != NULL){
        temp = mpProcessFIFO[1]->dequeue(); 
    }
    else if(mpProcessFIFO[2]->getHead() != NULL){
        temp = mpProcessFIFO[2]->dequeue(); 
    }
    timeSliceCount = 0;
    return temp;  
}

bool SchedulerRep::checkTimeSlice()
{
    if(mpRunningProcess != NULL){
        int val = 2;
        if(mpRunningProcess->getProcessType() == "B"){
            val = 4;
        }
        else if(mpRunningProcess->getProcessType() == "C"){
            val = 8;
        }
        if(timeSliceCount  == val){
            pushProcess(mpRunningProcess);
            mpRunningProcess = NULL;
            return true;
        }
        return false;   
    } 
    return true;
}
ProcessRep* SchedulerRep::sendProcessToCPU(ProcessRep* p){
    mpRunningProcess = pCpuObj->runCPU(p,totalTime);
    timeSliceCount++;
    if(mpRunningProcess == NULL){
        mpRunningProcess = popProcess();
    }
    return mpRunningProcess;    
}
void SchedulerRep::schedule(string type, int id, int arrivalTime, int processTime)
{   
    totalTime++;
    ProcessRep *p = new ProcessRep(type,id,arrivalTime,processTime);
    if((mpRunningProcess != NULL) && ((p->getProcessType() == "A" && mpRunningProcess->getProcessType() != "A") || (p->getProcessType() == "B" && mpRunningProcess->getProcessType() == "C"))){
        pushProcess(mpRunningProcess);
        timeSliceCount = 0;
        mpRunningProcess = p;
    }
    else{
        if(p->getProcessType() == "A"){
            mpProcessFIFO[0]->queue(p);
        }
        else if(p->getProcessType() == "B"){
            mpProcessFIFO[1]->queue(p);
        } 
        else if(p->getProcessType() == "C"){
            mpProcessFIFO[2]->queue(p);
        }
    }
    ProcessRep *temp = NULL;
    if(pCpuObj->getFinishedProcess()->getTail() != NULL && pCpuObj->getFinishedProcess()->getTail()->endTime + 1 == totalTime){
        temp = mpRunningProcess;
    }
    else{
        if(checkTimeSlice()){
            temp = popProcess();
        }
        else{
            temp = mpRunningProcess;
        }
    }
    mpRunningProcess = sendProcessToCPU(temp);
}


void SchedulerRep::schedule(ProcessRep* p)
{
    totalTime++;
    ProcessRep *temp = NULL;
    if(pCpuObj->getFinishedProcess()->getTail() != NULL && pCpuObj->getFinishedProcess()->getTail()->endTime + 1 == totalTime){
        temp = mpRunningProcess;
    }
    else{
        if(checkTimeSlice()){
            temp = popProcess();
        }
        else{
            temp = mpRunningProcess;
        }
    }
    mpRunningProcess = sendProcessToCPU(temp);
}
