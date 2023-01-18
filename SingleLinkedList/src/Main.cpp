#include <iostream>
#include <stdio.h>
#include "SingleLinkedList.h"

using namespace std;

int main(){
    SingleLinkedList* list1 = new SingleLinkedList();
    list1->print_list();
    list1->add_node(5);
    list1->add_node(6);
    list1->add_node(1);
    list1->add_node(2);
    list1->print_list();
    list1->remove_node(2);
    list1->print_list();
    list1->remove_node(14);
    list1->print_list();
    //list1->clear_list();
    list1->print_list();
    delete list1;
    return EXIT_SUCCESS;
}

