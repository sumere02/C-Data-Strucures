#include <iostream>
#include <stdio.h>
#include "MStack.h"

using namespace std;



int main(){
    MStack* s = new MStack();
    for(int i=0;i<1;i++)
        s->push(i);
        
    for(int i=0;i<5;i++)
        if(!s->isEmpty())
            cout<<s->pop()<<" ";
    
    s->push(100);
    s->push(200);
    cout<<endl;
    delete s;
    return EXIT_SUCCESS;
}
