#include "BinSTNode.h"
#include <stdlib.h>

BinSTNode::BinSTNode(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void BinSTNode::set_data(int data){
    this->data = data;
}

int BinSTNode::get_data(){
    return this->data;
}

void BinSTNode::set_left(BinSTNode* left){
    this->left = left;
}

BinSTNode* BinSTNode::get_left(){
    return this->left;
}

void BinSTNode::set_right(BinSTNode* right){
    this->right = right;
}

BinSTNode* BinSTNode::get_right(){
    return this->right;
}


bool BinSTNode::contains(int data){
    if(this == NULL)
        return false;
    if(data < this->data)
        if(this->left != NULL)
            this->left->contains(data);
        else
            return false;
    else if(data > this->data)
        if(this->right != NULL)
            this->right->contains(data);
        else
            return false;
    else
        return true;
}


void BinSTNode::add(int data){
    if(data < this->data)
        if(this->left != NULL)
            this->left->add(data);
        else
            this->left = new BinSTNode(data);
    else if(data > this->data)
        if(this->right != NULL)
            this->right->add(data);
        else
            this->right = new BinSTNode(data);
    else
        return;
}

void BinSTNode::remove(int data){
    if(data < this->data){
        if(this->left != NULL && this->left->data == data){
            BinSTNode* left_child = this->left->left;
            BinSTNode* right_child = this->left->right;
            delete this->left;
            if(left_child != NULL){
                this->left=left_child;
                BinSTNode* temp = this->left;
                while(temp->right != NULL)
                    temp = temp->right;
                temp->right = right_child;
            }
            else
                this->left = right_child;
        }
        else if(this->left != NULL)
            this->left->remove(data);
        else
            return;        
    }
    else if(data > this->data)
        if(this->right != NULL && this->right->data == data){
            BinSTNode* left_child = this->right->left;
            BinSTNode* right_child = this->right->right;
            delete this->right;
            if(left_child != NULL){
                this->right=left_child;
                BinSTNode* temp = this->right;
                while(temp->right != NULL)
                    temp = temp->right;
                temp->right = right_child;
            }
            else
                this->right = right_child;
        }
        else if(this->right != NULL)
            this->right->remove(data);
        else return;
}
