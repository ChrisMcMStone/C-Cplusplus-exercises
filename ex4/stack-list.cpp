#include <iostream>

template<typename T>
struct linkedList {
    T data;
    linkedList<T> *prev;
};

template<class T>
class stackList {

    public:
        stackList () { 
            this->top = new linkedList<T>;
            top->prev = NULL; 
        }
        ~stackList() { 
            while(top != NULL) {
                this->pop();
            }
        }
        void push(T x) {
            struct linkedList<T> *oldTop = top;
            top = new linkedList<T>;
            top->data = x;
            top->prev = oldTop;
        }
        T pop() {
            struct linkedList<T> *oldTop = top;
            T x = top->data;
            top = top->prev;
            delete(oldTop);
            return x;
        }
        int isEmpty() const { return top->prev == NULL; }
        void applyToAll (T (*function)(T)){
            struct linkedList<T> *oldTop = top;
            while(top->prev) {
                top->data = function(top->data);
                top = top->prev; }
            top = oldTop;
        }
    private:
        struct linkedList<T> *top;
};
