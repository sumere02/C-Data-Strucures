#include <iostream>
#include <stdio.h>
#include "MQueue.h"

using namespace std;

const int MAX_GRADES=10;

void queue_examples();

int main(){

    queue_examples();

    return EXIT_SUCCESS;
}
void queue_examples(){
    MQueue q;
    for(int i=0;i<15;i++){
        q.enqueue(i);
        q.enqueue(i*2);
        cout<<q.dequeue()<<" ";
    }
        
    cout<<endl;
}

