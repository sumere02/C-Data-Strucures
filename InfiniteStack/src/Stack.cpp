#include "MStack.h"
#include <stdlib.h>

MStack::MStack(){
    top = NULL;
}

MStack::~MStack(){
    if(top != NULL)
        delete top;
}

bool MStack::push(int data){
    Node* newNode = new Node(data);
    if(!this->isEmpty()){
        newNode->set_next(top);
    }
    top = newNode;
}

int MStack::pop(){
    if(!this->isEmpty()){
        Node* temp = top;
        int data = temp->get_data();
        top = top->get_next();
        temp->set_next(NULL);
        delete temp;
        return data;
    }
}

int MStack::peek(){
    if(!this->isEmpty()){
        int data = top->get_data();
        return data;
    }
}

bool MStack::isEmpty(){
    return top == NULL;
}

void MStack::clear(){
    delete top;
    top = NULL;
}

void MStack::remove_duplicates(){
    
}