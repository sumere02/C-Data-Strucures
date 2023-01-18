/* @Author
Student Name: Emir Sümer
Student ID : 150200112
Date: 14.19.2022
*/
#ifndef _PROCESSREP
#define _PROCESSREP

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class ProcessRep
{
    /*
        Node of a linked list data structues
    */
private:
    ProcessRep *mpNext;
    string mProcessType;
    int mProcessID;
    int mDeliverTime;
    int mProcessTime;

public:
    int remainingTime;
    int startTime;
    int endTime;

    ProcessRep(string, int, int, int);
    ~ProcessRep();

    ProcessRep* getNext();
    void setNext(ProcessRep*);

    string getProcessType();
    void setProcessType(string);

    int getDeliverTime();
    void setDeliverTime(int);

    int getProcessID();
    void setProcessID(int);

    int getProcessTime();
    void setProcessTime(int);
};

#endif
