const int MAX_QUEUE_SIZE=10;

class MQueue{
    private:
        int arr[MAX_QUEUE_SIZE];
        int front,back,num_of_items;

    public:
        MQueue();
        int dequeue();
        bool enqueue(int);
        int peek_front();
        int peek_back();
        bool isEmpty();
        bool isFull();
        void clear();

};