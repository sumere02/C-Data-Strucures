#include "Node.h"
#include <stdlib.h>

Node::Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void Node::set_data(int data){
    this->data = data;
}

int Node::get_data(){
    return this->data;
}

void Node::set_left(Node* left){
    this->left = left;
}

Node* Node::get_left(){
    return this->left;
}

void Node::set_right(Node* right){
    this->right = right;
}

Node* Node::get_right(){
    return this->right;
}
