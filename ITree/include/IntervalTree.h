#include "Node.h"

class IntervalTree{
    private:
        Node* root;
        void postorder_destruct(Node*);
        Node* add(Node*,Interval);
        bool doOverlap(Interval, Interval);
        Interval* overlapSearch(Node*, Interval);
        void inorder_traversal(Node*);
        
        Node* remove(Node*,Interval);
        Node* minlowinterval(Node*);
        int findmax(int,int,int);
    public:
        IntervalTree();
        ~IntervalTree();
        void add(Interval);
        Interval* overlapSearch(Interval);
        void inorder_traversal();
        Node* create_node(Interval);
        void remove(Interval);
};