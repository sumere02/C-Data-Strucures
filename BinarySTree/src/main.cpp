#include <iostream>
#include <stdio.h>
#include "BSTree.h"
using namespace std;

int main(int argc, char *argv[]){
/*
    list<int> v;
    v.assign({10,5,15,8,11,20,6,9,13,1,3,4});
    BSTree* t = new BSTree(v);
    BSTree* t = new BSTree();
    t->add(10);
    t->add(5);
    t->add(15);
    t->add(3);
    t->add(7);
    t->add(11);
    t->add(20);
    t->add(1);
    t->add(4);
    t->add(6);
    t->add(9);

//    t->remove(15);
//    t->printBreadthFirst();    
//    t->remove(5);
//    t->remove(6);
//    t->remove(8);
//    t->remove(11);
//    t->remove(10);

    if(t->contains(30))
        t->printInOrder();

    if(t->contains(6))
        t->printInOrder();

    t->printEuler();
    t->leaf_count();
    t->depths();
    cout << endl;
    t->heights();
*/
    int arr[8] = {10,11,17,19,30,31,37,38};
    BSTree* t = new BSTree();
    t->make_balanced(arr,8);
    t->printBreadthFirst();
    delete t;
    return EXIT_SUCCESS;
}