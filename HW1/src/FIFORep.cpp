/* @Author
Student Name: Emir Sümer
Student ID : 150200112
Date: 14.19.2022
*/
#include <iostream> 
#include <stdio.h>
#include <string.h>

#include "ProcessRep.h"
#include "FIFORep.h"

using namespace std;

FIFORep::FIFORep()
{
    
    mpHead = NULL;
    mpTail = NULL;
}

FIFORep::FIFORep(ProcessRep* head)
{
    mpHead = head;
    mpTail = head;
}


FIFORep::~FIFORep()
{
    if(mpHead != NULL){
        delete mpHead;
    }
}

void FIFORep::setHead(ProcessRep* head)
{
    mpHead = head;
}

ProcessRep* FIFORep::getHead()
{
    return mpHead;
}

void FIFORep::setTail(ProcessRep* tail)
{
    mpTail = tail;
}

ProcessRep* FIFORep::getTail()
{
    return mpTail;
}

void FIFORep::queue(ProcessRep* p)
{
    if(mpHead == NULL){
        mpHead = p;
        mpTail = p;
    }
    else{
        mpTail->setNext(p);
        mpTail = mpTail->getNext();
    }
}

ProcessRep* FIFORep::dequeue()
{
    ProcessRep* temp = NULL;
    if(mpHead != NULL){
        temp = mpHead;
        mpHead = mpHead->getNext();
        if(temp == mpTail){
            mpTail = NULL;
        }
        temp->setNext(NULL);
    }
    return temp;      
}

ProcessRep* FIFORep::searchID(int id)
{   
   ProcessRep* temp = mpHead;
   if(temp != NULL){
        while(temp->getNext() != NULL){
            if(temp->getProcessID() == id){
                return temp;
            }
            temp = temp->getNext();
        }
        if(temp->getProcessID() == id){
            return temp;
        } 
   }
   return NULL;
}

void FIFORep::printFIFO()
{
    ProcessRep* temp = mpHead;
    if(temp != NULL){
        while(temp->getNext() != NULL){
            cout << temp->getProcessType() << temp->getProcessID() << " " << temp->startTime << " " << temp->endTime << " ";
            temp = temp->getNext();
        }
        cout << temp->getProcessType() << temp->getProcessID() << " " << temp->startTime << " " << temp->endTime << " ";
    }
}