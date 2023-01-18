#include "Node.h"
#include <stdlib.h>

Node::Node(int data){
    next = NULL;
    this->data = data;
}

Node::~Node(){
    if(this->next != NULL){
        delete this->next;
    }
}

void Node::set_data(int data){
    this->data = data;
}

int Node::get_data(){
    return this->data;
}

void Node::set_next(Node *next){
    this->next = next;
}

Node* Node::get_next(){
    return this->next;
}