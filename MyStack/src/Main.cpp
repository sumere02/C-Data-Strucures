#include <iostream>
#include <stdio.h>
#include "MStack.h"

using namespace std;

const int MAX_GRADES=10;
void stack_examples();


int main(){
    stack_examples();

    return EXIT_SUCCESS;
}


void stack_examples(){
    MStack s;
    for(int i=0;i<15;i++)
        s.push(i);
        
    for(int i=0;i<5;i++)
        if(!s.isEmpty())
            cout<<s.pop()<<" ";
    
    s.push(100);
    s.push(200);
    cout<<endl;
}
