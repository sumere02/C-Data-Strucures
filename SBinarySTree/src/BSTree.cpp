#include "BSTree.h"
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

BSTree::BSTree(){
    this->root = NULL;
}

BinSTNode* BSTree::recursive_build(vector<int> v){
    if(v.size() == 0)
        return NULL;
    else if(v.size() == 1)
        return new BinSTNode(v.front());
    int mid = v.size()/2;
    vector<int> left(v.begin(),v.begin()+mid);
    vector<int> right(v.begin()+mid+1,v.end());

    BinSTNode* n = new BinSTNode(v[mid]);
    n->set_left(recursive_build(left));
    n->set_right(recursive_build(right));
    return n;
}

BSTree::BSTree(vector<int> v){
    sort(v.begin(),v.end());
    this->root = recursive_build(v);
}

void BSTree::postorder_destruct(BinSTNode* n){
    if(n != NULL){
        postorder_destruct(n->get_left());
        postorder_destruct(n->get_right());
        delete n;
    }
}

BSTree::~BSTree(){
    if(this->root != NULL)
        postorder_destruct(this->root);
    this->root = NULL;
}

void BSTree::preorder_traverse(BinSTNode* n){
    if(n != NULL){
        cout<< n->get_data() << " ";
        preorder_traverse(n->get_left());
        preorder_traverse(n->get_right());
    }
}
void BSTree::postorder_traverse(BinSTNode* n){
    if(n != NULL){
        postorder_traverse(n->get_left());
        postorder_traverse(n->get_right());
        cout<< n->get_data() << " ";
    }
}
void BSTree::inorder_traverse(BinSTNode* n){
    if(n != NULL){
        inorder_traverse(n->get_left());
        cout<< n->get_data() << " ";
        inorder_traverse(n->get_right());
        
    }
}

void BSTree::printPreOrder(){
    preorder_traverse(this->root);
    cout << endl;
}

void BSTree::printInOrder(){
    inorder_traverse(this->root);
    cout << endl;
}

void BSTree::printPostOrder(){
    postorder_traverse(this->root);
    cout << endl;
}

void BSTree::printBreadthFirst(){
    if(this->root == NULL)
        return;
    queue<BinSTNode*> q;
    q.push(this->root);
    BinSTNode* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->get_data() << " ";
        if(temp->get_left() != NULL)
            q.push(temp->get_left());
        if(temp->get_right() != NULL)
            q.push(temp->get_right());
    }
    cout << endl;
}

void BSTree::add(int data){
    if(this->root == NULL)
        this->root = new BinSTNode(data);
    else
        this->root->add(data);
}

bool BSTree::contains(int data){
    if(this->root != NULL)
        return this->root->contains(data);
}

void BSTree::remove(int data){
    if(this->root->get_data() == data){
        if(this->root->get_left() != NULL){
            BinSTNode* t = this->root;
            this->root = this->root->get_left();
            BinSTNode* p = this->root;
            while(p->get_right() != NULL)
                p = p->get_right();
            p->set_right(t->get_right());
            delete t;
        }
        else{
            BinSTNode* t = this->root;
            this->root = this->root->get_right();
            delete t;
        }
    }
    else
        if(this->root != NULL)
            this->root->remove(data);
}