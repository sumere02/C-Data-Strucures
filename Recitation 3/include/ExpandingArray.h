enum Strategy { TWICE, LOG, CAP_BY_CAP};

class ExpandingArray{

    private:
        int* arr;
        int size;
        int capacity;
        int initcap;
        Strategy strat;
        void expand();
        void shrink();
        void shift(int i);

    public:
        ExpandingArray(int capacity);
        ExpandingArray();
        ~ExpandingArray();

        int add(int element);
        int addAll(int* elements, int size);

        int remove(int element);
        int removeAll(int* elements, int size);

        void clear();
        int contains(int element);

        int get_size();
        int get_capacity();
        void set_strategy(Strategy s);
        Strategy get_strategy();

        void print();
};