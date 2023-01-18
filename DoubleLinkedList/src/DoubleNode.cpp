#include "DoubleNode.h"

#include <stdlib.h>

DoubleNode::DoubleNode(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

DoubleNode::~DoubleNode(){
    if(this->next != NULL){
        delete this->next;
    }
}

void DoubleNode::set_data(int data){
    this->data = data;
}

int DoubleNode::get_data(){
    return this->data;
}

void DoubleNode::set_next(DoubleNode* next){
    this->next = next;
}

DoubleNode* DoubleNode::get_next(){
    return this->next;
}

void DoubleNode::set_prev(DoubleNode* prev){
    this->prev = prev;
}

DoubleNode* DoubleNode::get_prev(){
    return this->prev;
}
