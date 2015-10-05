#include <iostream>
#include <stdlib.h>
#include "stack-list.cpp"
#include "stack-array.cpp"

using namespace std;
int const STACK_SIZE = 100;

template<typename T>
T printItem(T item) {
    std::cout << item << " ";
    return item;
}

template<typename T>
T printItemFromTree(T item) {
    std::cout << item.data << " ";
    return item;
}

template<typename T>
T addTen(T item) {
    return item + 10;
}

struct bTree {
    bTree *left;
    int data;
    bTree *right;
};

typedef struct bTree binaryTree;

//Stack Array Tests
void stackArrayTests() {

    //Instantiate the stackArray
    //tested with ints, doubles, void pointers, binarytree struct
    stackArray<int> *aInt = new stackArray<int>(STACK_SIZE);
    stackArray<double> *aDouble = new stackArray<double>(STACK_SIZE);
    stackArray<void*> *aVoid = new stackArray<void*>(STACK_SIZE);
    stackArray<bTree> *aBTree = new stackArray<bTree>(STACK_SIZE);

    //Push ten values on each stack
    void *vp = malloc(sizeof(void*));
    for(int i=1; i<=10; i++) {
        aInt->push(i);
        aDouble->push(i+.123);
        aVoid->push(vp);
    }

    //Add 3 items to binary tree;
    binaryTree *b = new bTree;
    b->data = 1;
    b->left = NULL;
    b->right = NULL;
    binaryTree *b2 = new bTree;
    b2->data = 3;
    b2->left = NULL;
    b2->right = NULL;
    binaryTree *b3 = new bTree;
    b3->data = 2;
    b3->left = b;
    b3->right = b2;
    //Push binary tree onto stack
    aBTree->push(*b);
    aBTree->push(*b2);
    aBTree->push(*b3);

    //Print the contents of the stacks
    std::cout << "Contents of int array stack: ";
    aInt->applyToAll(&printItem);
    std::cout << endl;

    std::cout << "Contents of double array stack: ";
    aDouble->applyToAll(&printItem);
    std::cout << endl;

    std::cout << "Contents of void* array stack: ";
    aVoid->applyToAll(&printItem);
    std::cout << endl;

    std::cout << "Contents of btree array stack: ";
    aBTree->applyToAll(&printItemFromTree);
    std::cout << endl;

    aDouble->applyToAll(&addTen);
    std::cout << "Result of applying the add ten function to the double array stack: ";
    aDouble->applyToAll(&printItem);
    std::cout << endl;

    aInt->applyToAll(&addTen);
    std::cout << "Result of applying the add ten function to the int array stack: ";
    aInt->applyToAll(&printItem);
    std::cout << endl;
    std::cout << endl;

    //Call destructors
    //Note: This also tests the pop() functionality as it is used in the destructor
    delete aInt;
    delete aDouble;
    delete aVoid;
    delete aBTree;
    delete b; 
    delete b2; 
    delete b3; 
    free(vp);
}

void stackListTests() {

    //Instantiate the stackList
    stackList<int> *lInt = new stackList<int>();
    stackList<double> *lDouble = new stackList<double>();
    stackList<void*> *lVoid = new stackList<void*>();
    stackList<bTree> *lBTree = new stackList<bTree>();

    //Push ten values on each stack
    void *vp = malloc(sizeof(void*));
    for(int i=1; i<=10; i++) {
        lInt->push(i);
        lDouble->push(i+.123);
        lVoid->push(vp);
    }

    //Add 3 items to binary tree;
    struct bTree *b = new bTree;
    b->data = 1;
    b->left = NULL;
    b->right = NULL;
    struct bTree *b2 = new bTree;
    b2->data = 3;
    b2->left = NULL;
    b2->right = NULL;
    struct bTree *b3 = new bTree;
    b3->data = 2;
    b3->left = b;
    b3->right = b2;
    //Push binary tree onto stack
    lBTree->push(*b);
    lBTree->push(*b2);
    lBTree->push(*b3);

    //Print the contents of the stacks
    std::cout << "Contents of int list stack: ";
    lInt->applyToAll(&printItem);
    std::cout << endl;

    std::cout << "Contents of double list stack: ";
    lDouble->applyToAll(&printItem);
    std::cout << endl;

    std::cout << "Contents of void* list stack: ";
    lVoid->applyToAll(&printItem);
    std::cout << endl;

    std::cout << "Contents of btree list stack: ";
    lBTree->applyToAll(&printItemFromTree);
    std::cout << endl;
    
    //Apply add ten functions
    lDouble->applyToAll(&addTen);
    std::cout << "Result of applying the add ten function to the double list stack: ";
    lDouble->applyToAll(&printItem);
    std::cout << endl;

    lInt->applyToAll(&addTen);
    std::cout << "Result of applying the add ten function to the int list stack: ";
    lInt->applyToAll(&printItem);
    std::cout << endl;

    
    //Call destructors
    //Note: This also tests the pop() functionality as it is used in the destructor
    delete lInt;
    delete lDouble;
    delete lVoid;
    delete lBTree;
    delete(b);
    delete(b2);
    delete(b3);
    free(vp);
    
}

int main() {

    stackArrayTests();
    stackListTests();

    return 0;
}
