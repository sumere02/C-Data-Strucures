#include "BSTree.h"
#include <queue>
#include <iostream>

using namespace std;

BSTree::BSTree(){
    this->root = NULL;
}

void BSTree::inorder_construct(Node* n,list<int> &v){
    if(n != NULL){
        inorder_construct(n->get_left(),v);
        n->set_data(v.front());
        v.pop_front();
        inorder_construct(n->get_right(),v);
    }
}

BSTree::BSTree(list<int> v){
    if(v.empty()){
        this->root = NULL;
        return;
    }
    int num_of_nodes = 1;
    queue<Node*> q;
    this->root = new Node(0);
    q.push(this->root);

    while(num_of_nodes<v.size()){
        Node* n = q.front();
        q.pop();
        n->set_left(new Node(0));
        num_of_nodes++;
        q.push(n->get_left());
        if(num_of_nodes == v.size())
            break;
        n->set_right(new Node(0));
        num_of_nodes++;
        q.push(n->get_right());
    }
    v.sort();
    inorder_construct(this->root,v);
}

void BSTree::postorder_destruct(Node * n){
    if(n != NULL){
        postorder_destruct(n->get_left());
        postorder_destruct(n->get_right());
        delete n;
    }
}

BSTree::~BSTree(){
    postorder_destruct(this->root);
}

void BSTree::preorder_traverse(Node* n){
    if(n != NULL){
        cout << n->get_data() << " ";
        preorder_traverse(n->get_left());
        preorder_traverse(n->get_right());
    }
}

void BSTree::inorder_traverse(Node* n){
    if(n != NULL){
        inorder_traverse(n->get_left());
        cout << n->get_data() << " ";
        inorder_traverse(n->get_right());
    }
}

void BSTree::postorder_traverse(Node* n){
    if(n != NULL){
        postorder_traverse(n->get_left());
        postorder_traverse(n->get_right());
        cout << n->get_data() << " ";
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
    queue<Node*> q;
    q.push(this->root);
    Node* temp;
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

bool BSTree::contains(int data){
    if(this->root == NULL)
        return false;
    Node* temp = this->root;
    while(temp != NULL){
        if(data < temp->get_data()){
            temp = temp->get_left();
        }
        else if(data > temp->get_data()){
            temp = temp->get_right();
        }
        else{
            return true;
        }
    }
    return false;

}

void BSTree::add(int data){
    Node* n = new Node(data);
    if(this->root == NULL){
        this->root = n;
        return;
    }
    Node* temp = this->root;
    while(temp != NULL){
        if(data < temp->get_data()){
            if(temp->get_left() == NULL){
                temp->set_left(n);
                return;
            }   
            temp = temp->get_left();
        }
        else if(data > temp->get_data()){
            if(temp->get_right() == NULL){
                temp->set_right(n);
                return;
            }
            temp = temp->get_right();
        }
        else{
            delete n;
            return;
        }
    }
    
}

Node* BSTree::find_par(int data){
    Node* temp = this->root;
    if(temp->get_data() == data)
        return NULL;
    while(temp != NULL){
        if(temp->get_left() != NULL && temp->get_left()->get_data() == data)
            return temp;
        else if(temp->get_right() != NULL && temp->get_right()->get_data() == data)
            return temp;
        else{
            if(data < temp->get_data())
                temp = temp->get_left();
            else
                temp = temp->get_right();  
        }
    }
}

/*
void BSTree::remove(int data){
    //Exceptions Not Solved
    if(!contains(data))
        return;
    Node* par = find_par(data);
    Node* child = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
    if(par != NULL){
        if(par->get_left()->get_data() == data){
            child = par->get_left();
        }
        else{
            child = par->get_right();
        }
    }
    left_child = child->get_left();
    right_child = child->get_right();
    par->set_left(left_child);
    Node* temp = par->get_left();
    while(temp->get_right() != NULL){
        temp = temp->get_right();
    }
    temp->set_right(right_child);
    delete child;
}
*/

void BSTree::remove(int data){

    if(!this->contains(data))
        return;
    Node* par = find_par(data);
    Node* child = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
    if(par == NULL){
        child = this->root;
        left_child = child->get_left();
        right_child = child->get_right();
        if(left_child != NULL){
                this->root = left_child;
                Node* temp = this->root;
                while(temp->get_right() != NULL)
                    temp = temp->get_right();
                temp->set_right(right_child);
        }
        this->root = right_child;
    }
    else{
        if(par->get_left() != NULL && par->get_left()->get_data() == data){
            child = par->get_left();
            left_child = child->get_left();
            right_child = child->get_right();
            if(left_child != NULL){
                par->set_left(left_child);
                Node* temp = par->get_left();
                while(temp->get_right() != NULL)
                    temp = temp->get_right();
                temp->set_right(right_child);
            }
            else
                par->set_left(right_child);
        }
        else{
            child = par->get_right();
            left_child = child->get_left();
            right_child = child->get_right();
            if(left_child != NULL){
                par->set_right(left_child);
                Node* temp = par->get_right();
                while(temp->get_right() != NULL)
                    temp = temp->get_right();
                temp->set_right(right_child);
            }
            else
                par->set_right(right_child);
        }
    }
    delete child; 
}

void BSTree::euler_traverse(Node* n){
    if(n != NULL){
        cout<< n->get_data() << " ";
        euler_traverse(n->get_left());
        if(n->get_left() != NULL || n->get_right() != NULL)
            cout << n->get_data() << " ";
        euler_traverse(n->get_right());
        if(n->get_left() != NULL || n->get_right() != NULL)
            cout << n->get_data() << " ";
    }
}


void BSTree::printEuler(){
    if(this->root != NULL)
        euler_traverse(this->root);
    cout << endl;
}


void BSTree::leaf_count(){
    cout << leaf_count(this->root) << endl;
}

int BSTree::leaf_count(Node* n){
    if(n == NULL)
        return 0;
    else if(n->get_left() == NULL && n->get_right() == NULL)
        return 1;
    return leaf_count(n->get_left())+leaf_count(n->get_right());
}

void BSTree::depths(){
    depths(this->root,0);
}

void BSTree::depths(Node* n,int depth){
    if(n != NULL){
        cout << "Data: " << n->get_data() << "Depth: " << depth << endl;
        depths(n->get_left(),depth+1);
        depths(n->get_right(),depth+1);
    }
}

void BSTree::heights(){
    heights(this->root);
}

int BSTree::heights(Node* n){
    if(n == NULL)
        return 1;
    int l_height = heights(n->get_left());
    int r_height = heights(n->get_right());
    int h = max(l_height,r_height)+1;
    cout <<"Data: " <<  n->get_data() << "Height: " << h -2 << endl;
    return h;
}

Node* BSTree::build(int* arr,int lower,int upper){
    int size = upper-lower+1;
    if(upper < lower)
        return NULL;
    int mid = lower + size/2;
    Node* n = new Node(arr[mid]);
    n->set_left(build(arr,lower,mid-1));
    n->set_right(build(arr,mid+1,upper));
    return n;
}


void BSTree::make_balanced(int* arr,int size){
    this->root = build(arr,0,size-1);
}


