#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

void PrintList(ListNode *p) {

    cout << "In order: " << endl;
    while(p != NULL) {
        cout << p->data << endl;
        p=p->next;
    }
}

void PrintReverse(ListNode *p) {

    if(p == NULL) return;
    PrintReverse(p->next);
    cout << p->data <<endl;

}

int main() {

    ListNode *p4 = new ListNode;
    p4->data = 4;
    p4->next = NULL;

    ListNode *p3 = new ListNode;
    p3->data = 3;
    p3->next = p4;

    ListNode *p2 = new ListNode;
    p2->data = 2;
    p2->next = p3;

    ListNode *p1 = new ListNode;
    p1->data = 1;
    p1->next = p2;

    ListNode *p = new ListNode;
    p->data = 0;
    p->next = p1;

    PrintList(p);

    cout << endl << "In reverse: " << endl;
    PrintReverse(p);

    delete p4;
    delete p3;
    delete p2;
    delete p1;
    delete p;

    return 0;

}
