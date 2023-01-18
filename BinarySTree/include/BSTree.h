#include "Node.h"
#include <list>

using namespace std;


class BSTree{
    private:
        Node* root;

        void inorder_construct(Node*,list<int>&);
        
        Node* find_par(int);
        
        void preorder_traverse(Node*);
        void inorder_traverse(Node*);
        void postorder_traverse(Node*);
        void postorder_destruct(Node*);
        void euler_traverse(Node*);
        Node* build(int*,int,int);

    public:
        BSTree();
        BSTree(list<int> v);
        ~BSTree();

        void add(int);
        bool contains(int);
        void remove(int);

        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void printBreadthFirst();
        void printEuler();

        void leaf_count();
        int leaf_count(Node *);

        void depths(Node* ,int);
        void depths();

        void heights();
        int heights(Node*);

        void make_balanced(int*,int);
};