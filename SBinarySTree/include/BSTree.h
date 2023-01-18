#include "BinSTNode.h"
#include <vector>

using namespace std;

class BSTree{
    private:
        BinSTNode* root;

        void preorder_traverse(BinSTNode* n);
        void inorder_traverse(BinSTNode* n);
        void postorder_traverse(BinSTNode* n);
        void postorder_destruct(BinSTNode* n);
        BinSTNode* recursive_build(vector<int>);
        
    public:
        BSTree();
        BSTree(vector<int> v);
        ~BSTree();

        void add(int);
        bool contains(int);
        void remove(int);
        
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void printBreadthFirst();
};