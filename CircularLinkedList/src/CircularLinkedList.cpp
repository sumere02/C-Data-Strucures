
#include <iostream>
#include <stdio.h>
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList(){
    head = new DoubleNode(-1,true);
    head->set_next(head);
    head->set_prev(head);
}

CircularLinkedList::~CircularLinkedList(){
    DoubleNode* p = head->get_next();
    DoubleNode* n = head->get_next();
    while(!n->is_sentinel()){
        n=p->get_next();
        delete p;
        p = n;
    }
    delete head;
}

void CircularLinkedList::clear_list(){
    DoubleNode* p = head->get_next();
    DoubleNode* n = head->get_next();
    while(!n->is_sentinel()){
        n=p->get_next();
        delete p;
        p = n;
    }
    head->set_next(head);
    head->set_prev(head);
}

DoubleNode* CircularLinkedList::search_prev(int data){
    DoubleNode* temp = head->get_next();
    while(!temp->is_sentinel()){
        if(data <= temp->get_data())
        {
            return temp->get_prev();
        }
        temp = temp->get_next();
    }
    return temp->get_prev();
}

void CircularLinkedList::add_node(int data){
    DoubleNode* newNode = new DoubleNode(data,false);
    DoubleNode* prev = search_prev(data);
    newNode->set_next(prev->get_next());
    newNode->set_prev(prev);
    prev->set_next(newNode);
    newNode->get_next()->set_prev(newNode);
}

DoubleNode* CircularLinkedList::contains(int data){
    DoubleNode* temp = head->get_next();
    while(!temp->is_sentinel()){
        if(temp->get_data() == data){
            return temp;
        }
        temp = temp->get_next();
    }
    return NULL;
}

void CircularLinkedList::remove_node(int data){
    DoubleNode* temp = contains(data);
    if(!temp->is_sentinel()){
        DoubleNode* prev = search_prev(data);
        prev->set_next(temp->get_next());
        temp->get_next()->set_prev(prev);
        delete temp;
    }
}

void CircularLinkedList::print_list(){
    DoubleNode* temp = head->get_next();
    while(!temp->is_sentinel()){
        cout<<temp->get_data() << " ";
        temp = temp->get_next();
    }
    cout<<endl;
}

void CircularLinkedList::reverse_print_list(){
    DoubleNode* temp = head->get_prev();
    while(!temp->is_sentinel())
    {
        cout<<temp->get_data()<< " ";
        temp = temp->get_prev();
    }
    cout<<endl;
}