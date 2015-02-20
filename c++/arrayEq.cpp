#include <iostream>
using namespace std;

bool arrayEq(int a[], int b[], int size) {

    for(int i=0; i<size; i++) {
        if(a[i] != b[i]) return false;
    }

    return true;

}

int main() {

    return 0;
}

