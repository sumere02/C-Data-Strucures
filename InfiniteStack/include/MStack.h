#include "Node.h"

class MStack{
    private:
        Node* top;
    public:
        MStack();
        ~MStack();
        bool push(int);
        int pop();
        int peek();
        bool isEmpty();
        void clear();
        void remove_duplicates();

};