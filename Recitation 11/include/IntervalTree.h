#include "Node.h"
#include "Interval.h"
#include <stdlib.h>

class IntervalTree{
    private:
        Node* root;
        void postorder_destruct(Node*);
        Node* add(Node*,Interval);
        bool doOverlap(Interval, Interval);
        Interval* overlapSearch(Node*, Interval);
        Node* minlowinterval(Node*);
        void inorder_traversal(Node*);
        int findmax(int,int,int);
        Node* remove(Node*,Interval);
    public:
        IntervalTree();
        ~IntervalTree();
        Node* createNode(Interval);
        void add(Interval);
        Interval* overlapSearch(Interval);
        void inorder_traversal();
        void remove(Interval);
};