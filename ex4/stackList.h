template<class T>
class stackList {

    public:
        stackList ();
        ~stackList();
        void push(T x);
        T pop() {};
        int isEmpty();
        void applyToAll (T (*function)(T));
    private:
        struct linkedList<T> *top;
};

