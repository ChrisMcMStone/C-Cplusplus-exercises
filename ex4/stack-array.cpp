#include <iostream>

template<class T>
class stackArray {
    
    public:
        stackArray (int s) {size=s; top=-1; data = new T[size];}
        ~stackArray() {delete [] data;}
        void push (T x) {data[++top] = x;}
        T pop() {return data[top--];}
        int isEmpty() const { return top == -1;}
        int isFull() const { return top == size-1;}
        void applyToAll (T (*function)(T)){
            for(int i=0;i<=top;i++){ data[top-i] = function(data[top-i]); } }
    private:
        int size;
        int top;
        T* data;
};
