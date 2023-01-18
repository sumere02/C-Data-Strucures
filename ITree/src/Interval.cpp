#include "Interval.h"

Interval::Interval(int low,int high){
    this->low = low;
    this->high = high;
}

void Interval::set_low(int low){
    this->low = low;
}

void Interval::set_high(int high){
    this->high = high;
}

int Interval::get_low(){
    return this->low;
}

int Interval::get_high(){
    return this->high;
}