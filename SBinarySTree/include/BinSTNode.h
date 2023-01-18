class BinSTNode{
    private:
        int data;
        BinSTNode* left;
        BinSTNode* right;
    public:
        BinSTNode(int);
        int get_data();
        void set_data(int);
        BinSTNode* get_left();
        void set_left(BinSTNode* left);
        BinSTNode* get_right();
        void set_right(BinSTNode* right);

        bool contains(int);
        void add(int);
        void remove(int);
};