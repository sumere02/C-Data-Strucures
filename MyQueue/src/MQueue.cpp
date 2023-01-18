#include "MQueue.h"

MQueue::MQueue(){
    front = 0;
    back = -1;
    num_of_items = 0;
}

int MQueue::dequeue(){
    if(!this->isEmpty()){
            num_of_items--;
        int temp = front;
        front = (front+1) % MAX_QUEUE_SIZE;
        return arr[temp];
    }
}

bool MQueue::enqueue(int val){
    if(!this->isFull()){
        num_of_items++;
        back = (back+1) % MAX_QUEUE_SIZE;
        arr[back] = val;
        return true;
    }
    return false;

}

int MQueue::peek_front(){
    return arr[front];
}

int MQueue::peek_back(){
    return arr[back];
}

bool MQueue::isEmpty(){
    if(back == -1)
        return true;
    return false;
}

bool MQueue::isFull(){
    if(num_of_items == MAX_QUEUE_SIZE)
        return true;
    return false;
}

void MQueue::clear(){
    num_of_items == 0;
    back = -1;
    front = 0;
}


