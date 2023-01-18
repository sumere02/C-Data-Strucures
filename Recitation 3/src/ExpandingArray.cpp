#include "ExpandingArray.h"
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void ExpandingArray::expand(){
    int newcap = 0;
    switch(strat){
        case 0:
            newcap = capacity * 2;
            break;
        case 1:
            newcap = capacity + (int)log2(capacity);
            break;
        case 2:
            newcap = capacity + initcap;
            break;
        default:
            newcap = capacity;
            break;
    }
    int *newarr = new int[newcap];
    for(int i = 0;i<size;i++){
        newarr[i] = arr[i];
    }
    delete[] arr;
    arr = newarr;
    capacity = newcap;
}

void ExpandingArray::shrink(){
    int newcap;
    int nextcap = capacity;
    while(nextcap > size && nextcap > 0){
        newcap = nextcap;
        switch(strat){
            case 0:
                nextcap = (int)nextcap / 2;
                break;
            case 1:
                newcap = capacity - log2(capacity);
                break;
            case 2:
                newcap = capacity - initcap;
                break;
            default:
                newcap = capacity;
                break;
        }
    }
    if(newcap ==  this->capacity){
        return;
    }
    int *newarr = new int[newcap];
    for(int i = 0;i<size;i++){
        newarr[i] = arr[i];
    }
    delete[] arr;
    arr = newarr;
    capacity = newcap;
}

void ExpandingArray::shift(int i){
    for (int index=i;i<size-1;i++){
        this->arr[i]=this->arr[i+1];
    }
    this->size--;
}

ExpandingArray::ExpandingArray(){
    this->capacity = 100;
    this->initcap = capacity;
    this->strat = TWICE;
    this->size = 0;
    arr = new int[initcap];    
}

ExpandingArray::ExpandingArray(int capacity){
    this->capacity = capacity;
    this->initcap = capacity;
    this->size = 0;
    arr = new int[initcap];
    this->strat = TWICE;
}

ExpandingArray::~ExpandingArray(){
    delete arr;
}

int ExpandingArray::add(int element){
    if(size >= capacity){
        expand();
    }
    arr[size] = element;
    size++;
    return size;
}

int ExpandingArray::addAll(int* elements,int size){
    for(int i = 0;i<size;i++){
        add(elements[i]);
    }
    return this->size;
}

int ExpandingArray::remove(int element){
    int flag = contains(element);
    if(flag != -1){
        shift(flag);
    }
    shrink();
    return size;
}

int ExpandingArray::removeAll(int* elements,int size){
    for(int i = 0;i<size;i++){
        remove(elements[i]);
    }
    return this->size;
}

void ExpandingArray::clear(){
    size = 0;
    shrink();
}

int ExpandingArray::contains(int element){
    for(int i = 0;i<size;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int ExpandingArray::get_size(){
    return this->size;
}

int ExpandingArray::get_capacity(){
    return this->capacity;
}

void ExpandingArray::set_strategy(Strategy s){
    strat = s;    
}

Strategy ExpandingArray::get_strategy(){
    return this->strat;
}

void ExpandingArray::print(){
    for(int i =0;i<size;i++){
        cout << arr[i] << " ";
    }
}
