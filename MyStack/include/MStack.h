const int MAX_STACK_SIZE=10;


class MStack{
    private:
        int arr[MAX_STACK_SIZE];
        int top;

    public:
        MStack();
        bool push(int);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
        void clear();

};