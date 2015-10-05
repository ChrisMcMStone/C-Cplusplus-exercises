//
//  main.cpp
//  treewalkerOO exercise
// 20.2.2015

#include <iostream>

// perform the work at each node, to be implemented by each worker
class worker {
public:
    virtual int workplus(int x, int y) = 0;
    virtual int worktimes(int x, int y) = 0;
    virtual int workminus(int x, int y) = 0;
    virtual int workconstant(int x) = 0;
};

// perform the work for evaluating a tree

class evalworker : public worker {
public:
    int workplus(int x, int y) { return x + y; }
    int worktimes(int x, int y) { return x * y; }
    int workminus(int x, int y) { return x - y; }
    int workconstant(int x) { return x; }
};

// abstract base class E
class E {
public:
    virtual int employ(worker*) = 0;
};

// TODO: implement classes plus, times, minus, and constant

// TODO: implement class countplusworker

// wrapper function for evaluation

int eval(class E *p)
{
    return p->employ(new evalworker());
}

int main(int argc, char *argv[])
{
    // build a tree for testing
    class E *p1 = new plus(new constant(2), new constant(3));
    class E *p2 = new times(p1, p1);
    class E *p = new minus(p2, p1);

    printf("Result = %d\n\n", eval(p)); // should print 20

    printf("Number of pluses = %d\n\n", p->employ(new countplusworker())); // should print 3

    return 0;
}


