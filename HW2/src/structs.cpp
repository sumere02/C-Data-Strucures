//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname:Emir Sümer
//---Student Number:150200112
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-------------Initialize Priority Queue-------------//
PriorityQueue::PriorityQueue(){
    //TODO
    head = NULL;                                            //Initializes with empty Queue
};

//-------------Insert New Node To Priority Queue-------------//
void PriorityQueue::enque(Node* newnode){
    //TODO
    //Inserting Empty queue
    if(head == NULL){                                       //Checks queue empty or not                        
        head = newnode;                     
        return;
    }
    //Traversing Through queue to find the insertion index
    //If founded insert
    //Not founded get next node
    Node* temp = head;
    //Exception for newnode is more priotrized than head
    if(newnode->token.val < temp->token.val){               
        newnode->next = head;
        head = newnode;
    }
    else{
        while(temp->next != NULL){
            if(newnode->token.val < temp->next->token.val){
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            temp = temp->next;
        }
        if(temp->next == NULL)
            temp->next = newnode;
    }

};

//-------------Remove Node From Priority Queue-------------//
Node* PriorityQueue::dequeue(){
    //TODO
         Node* temp = head;                         //Gets head node
         if(temp != NULL){                          //Checks Queue empty or not
            head = temp->next;                      //Sets new head of queue
            temp->next = NULL;
         }
         return temp;                               //returns head
};

//-------------Initialize Tree-------------//
Tree::Tree(){
    //TODO
    root = NULL;                                    //Initalizes with empty tree
};

//-------------Delete Tree Nodes From Memory-------------//
Tree::~Tree(){
    //TODO
    if(this->root != NULL){                         //Checks tree is empty or not
        deleteTree(this->root);                     //If not empty recursively delete tree
    }
    this->root = NULL;
};

//-------------Delete Tree From Memory-------------//
void Tree::deleteTree(Node* node){
    //-------------This Function Is Not Necessary-------------//
    //-----------------Use It At Your Own Will----------------//
    //Deleting tree with using recursive postorder destruct
    if(node != NULL){  
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    return;
}

//-------------Merges Two Node Into One-------------//
Node* Tree::mergeNodes(Node* temp1, Node* temp2){
    //TODO
    string newSymbol = temp1->token.symbol + temp2->token.symbol;       //Combines symbols
    int newVal = temp1->token.val + temp2->token.val;                   //add values
    Node* newRoot = new Node();                                         //creates new node
    //Initalizes new node
    newRoot->token.symbol = newSymbol;
    newRoot->token.val = newVal;
    newRoot->left = temp1;
    newRoot->right = temp2;
    return newRoot;
};

void Tree::printTree(Node* traverse, int level){
    cout << level << "\t";
    for (int i = 0; i < level; i++)
        cout << "\t"; 

    cout << traverse->token.symbol << "(" << traverse->token.val << ")" << endl;

    if(traverse->left)
        printTree(traverse->left, level + 1);  
    if(traverse->right)
        printTree(traverse->right, level + 1);
};