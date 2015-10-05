#include <iostream>

template <typename T>
struct linkList {
    T data;
    struct linkList<T> *next;
    void apply_each(int (*func)(T)) {
        struct linkList<T> *temp = this;
        while(temp) {
            temp->data = func(temp->data);
            temp = temp->next;
        }
    }
};

int addOne(int x) {
    return x + 1;
}

int main() {

    linkList<int> *test3 = new struct linkList<int>;
    test3->data = 3;
    test3->next = NULL;
    linkList<int> *test2 = new struct linkList<int>;
    test2->data = 2;
    test2->next = test3;
    linkList<int> *test1 = new struct linkList<int>;
    test1->data = 1;
    test1->next = test2;

    test1->apply_each(&addOne);
    std::cout << test1->data << std::endl;
    std::cout << test2->data << std::endl;
    std::cout << test3->data << std::endl;


    return 0;

}
