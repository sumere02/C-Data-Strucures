#include "IntervalTree.h"
#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

IntervalTree::IntervalTree(){
    this->root = NULL;
}

void IntervalTree::postorder_destruct(Node* n){
    if(n != NULL){
        postorder_destruct(n->get_left());
        postorder_destruct(n->get_right());
        delete n;
    }
}

IntervalTree::~IntervalTree(){
    if(this->root != NULL)
        postorder_destruct(this->root);
    this->root = NULL;
}

Node* IntervalTree::create_node(Interval i){
    return new Node(i,i.get_high());
}

Node* IntervalTree::add(Node* n,Interval i){
    if(n == NULL){
        return create_node(i);
    }
    if(i.get_low() < n->get_i()->get_low())
        n->set_left(add(n->get_left(),i));
    else
        n->set_right(add(n->get_right(),i));
    if(n->get_max() < i.get_high())
        n->set_max(i.get_high());
    return n;
}

void IntervalTree::add(Interval i){
    if(this->root == NULL){
        this->root = create_node(i);
        return;
    }
    Node* created_node = add(this->root,i);
}

bool IntervalTree::doOverlap(Interval i1,Interval i2){
    if(i1.get_low() <= i2.get_high() && i2.get_low() <= i1.get_high())
        return true;
    return false;
}

Interval* IntervalTree::overlapSearch(Node* n,Interval i){
    if(n == NULL)
        return NULL;
    if(doOverlap(*(n->get_i()), i)) //if given interval overlap with r
        return n->get_i();
    if(n->get_left() != NULL && n->get_left()->get_max() >= i.get_low())
        return overlapSearch(n->get_left(),i);
    else
        return overlapSearch(n->get_right(),i);
}

Interval* IntervalTree::overlapSearch(Interval i){
    return overlapSearch(this->root,i);
}

void IntervalTree::inorder_traversal(Node* n){
    if(n == NULL)
        return;
    inorder_traversal(n->get_left());
    cout << "[" << n->get_i()->get_low() << ", " << n->get_i()->get_high() << "]" << " max = " << n->get_max() << endl;
    inorder_traversal(n->get_right());

}

void IntervalTree::inorder_traversal(){
    inorder_traversal(this->root);
}

Node* IntervalTree::minlowinterval(Node* n)
{
	while(n->get_left())
	    n = n->get_left();
	
	return n;
}

int IntervalTree::findmax(int a,int b,int c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}

Node* IntervalTree::remove(Node* n,Interval i){
    if(n == NULL)
        return NULL;
    Node* temp = NULL;
    if(i.get_low() < n->get_i()->get_low())
        n->set_left(remove(n->get_left(),i));
    else if(i.get_low() > n->get_i()->get_low())
        n->set_right(remove(n->get_right(),i));
    else if(i.get_low() == n->get_i()->get_low()){
        if(i.get_high() == n->get_i()->get_high()){
            if(n->get_left() == NULL){
                temp = n->get_right();
                delete n;
                return temp;
            }
            if(n->get_right() == NULL){
                temp = n->get_right();
                delete n;
                return temp;
            }
            temp = minlowinterval(n->get_right());
            n->set_i(temp->get_i()->get_low(),temp->get_i()->get_high());
            n->set_right(remove(n->get_right(),*(temp->get_i())));
        }
        else
            n->set_right(remove(n->get_right(),i));
    }
    n->set_max(findmax(n->get_i()->get_high(),((n->get_left())?n->get_left()->get_max():INT_MIN),
    ((n->get_right())?n->get_right()->get_max():INT_MIN)));
    return n;
}


void IntervalTree::remove(Interval i){
    Node* n_root = remove(this->root,i);
}