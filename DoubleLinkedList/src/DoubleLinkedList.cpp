#include "DoubleLinkedList.h"
#include "DoubleNode.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

DoubleLinkedList::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList(){
    delete head;
}

DoubleNode* DoubleLinkedList::search_prev(int data){
    if(head == NULL || head->get_data() >= data){
        return NULL;
    }
    else if(head == tail){
        if(head->get_data() >= data){
            return NULL;
        }
        return head;
    }
    else{
        DoubleNode* temp = head;
        while(temp->get_next() != NULL){
            if(temp->get_next()->get_data() >= data){
                return temp;
            }
            temp = temp->get_next();
        }
        return temp;
    }
}

DoubleNode* DoubleLinkedList::contains(int data){
    if(head != NULL){
        DoubleNode* temp = head;
        while(temp->get_next() != NULL){
            if(temp->get_data() == data){
                return temp;
            }
            temp = temp->get_next();
        }
        if(temp->get_data() == data){
            return temp;
        }
    }
    return NULL;
}

void DoubleLinkedList::clear_list(){
    delete head;
    head = NULL;
    tail = NULL;
}

void DoubleLinkedList::add_node(int data){
    DoubleNode* prev = search_prev(data);
    DoubleNode* newNode = new DoubleNode(data);
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        if(prev == NULL){
            newNode->set_next(head);
            head->set_prev(newNode);
            head = head->get_prev();
        }
        else if(prev == tail){
            tail->set_next(newNode);
            newNode->set_prev(tail);
            tail = tail->get_next();
        }
        else{
            DoubleNode* temp = prev->get_next();
            prev->set_next(newNode);
            temp->set_prev(newNode);
            newNode->set_next(temp);
            newNode->set_prev(prev);
        }
    }
}

void DoubleLinkedList::remove_node(int data){
    DoubleNode* node = contains(data);
    if(node != NULL){
        DoubleNode* next = node->get_next();
        DoubleNode* prev = node->get_prev();
        prev->set_next(next);
        next->set_prev(prev);
        node->set_next(NULL);
        delete node;
    }
}

void DoubleLinkedList::print_list(){
    if(head != NULL){
        DoubleNode* temp = head;
        while(temp->get_next() != NULL){
            cout<<temp->get_data()<< " ";
            temp = temp->get_next();
        }
        cout<<temp->get_data()<< endl;
    }
}

void DoubleLinkedList::reverse_print_list(){
    if(head != NULL){
        DoubleNode* temp = tail;
        while(temp->get_prev() != NULL){
            cout<<temp->get_data()<< " ";
            temp = temp->get_prev();
        }
        cout<<temp->get_data()<< endl;
    }
}