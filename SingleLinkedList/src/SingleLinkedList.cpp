#include "SingleLinkedList.h"
#include "Node.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

SingleLinkedList::SingleLinkedList(){
    head = NULL;
    tail = NULL;
}

SingleLinkedList::~SingleLinkedList(){
    if(head != NULL)
        delete head;
}

void SingleLinkedList::clear_list(){
    if(head != NULL){
        delete head;
    }
    head = NULL;
    tail = NULL;
}

Node* SingleLinkedList::search_prev(int data){
    if(head == NULL || data <= head->get_data()){
        return NULL;
    }
    else if(head == tail){
        if(data <= head->get_data())
            return NULL;
        else
            return tail;
    }
    else{
        Node* prev = head;
        while(prev->get_next() != NULL){
            if(prev->get_next()->get_data() >= data){
                return prev;
            }
            prev = prev->get_next();
        }
        return prev;
    }
}

void SingleLinkedList::add_node(int data){
    Node *newNode = new Node(data);
    Node *prev;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        prev = search_prev(data);
        if(prev == NULL){
            newNode->set_next(head);
            head=newNode;
        }
        else if(prev == tail){
            tail->set_next(newNode);
            tail = tail->get_next();
        }
        else{
            newNode->set_next(prev->get_next());
            prev->set_next(newNode);
        }
    }
}

bool SingleLinkedList::contains(int data){
    if(head != NULL){
            Node* temp = head;
        while(temp->get_next() != NULL){
            if(temp->get_data() == data)
                return true;
            temp = temp->get_next();
        }
        if(temp->get_data() == data)
            return true;
        return false;
    }
    return false;
}


void SingleLinkedList::remove_node(int data){
    if(contains(data)){
        if(head == tail){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else{
            Node* prev = search_prev(data);
            if(prev == NULL){
                Node* oldhead = head;
                head = head->get_next();
                oldhead->set_next(NULL);
                delete oldhead;
            }
            else if(prev->get_next() == tail){
                tail = prev;
                delete tail->get_next();
                tail->set_next(NULL);
            }
            else{
                Node *temp = prev->get_next();
                prev->set_next(temp->get_next());
                temp->set_next(NULL);
                delete temp;
            }
        }
             
    }
}

void SingleLinkedList::print_list(){
    Node *temp = head;
    if(head != NULL){
        while(temp->get_next() != NULL){
            cout << temp->get_data() << " ";
            temp = temp->get_next();
        }
        cout<<temp->get_data() << endl;
    }
}