#include "MStack.h"

MStack::MStack(){
    top = -1;
}

bool MStack::push(int data){
    if(this->isFull()){
        return false;
    }
    arr[++top] = data;
    return true;
}

int MStack::pop(){
    return arr[top--];
}

int MStack::peek(){
    return arr[top];
}

bool MStack::isEmpty(){
    if(top == -1)
        return true;
    return false;
}

bool MStack::isFull(){
    if(top+1 == MAX_STACK_SIZE){
        return true;
    }
    return false;
}

void MStack::clear(){
    top = -1;
}