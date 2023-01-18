class Node{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int);
        void set_data(int);
        int get_data();

        void set_left(Node*);
        Node* get_left();
        
        void set_right(Node*);
        Node* get_right();
        
};