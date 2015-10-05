#include <iostream>

using namespace std;

template <typename T>
void sort(T &toSort, int arraySize) {
    int i, j;
    T temp;
    for(i=0; i<arraySize; i++) {
        for(j=0; j<arraySize-i-1; j++) {
            if(toSort[j] > toSort[j+1]) {
                *temp = toSort[j];
                toSort[j] = toSort[j+1];
                toSort[j+1] = *temp;
            }
        }
    }
}


int main() {

    int* toSort = new int[5];
    for(int i=4; i>=0; i--) {
        toSort[i] = i;
    }

    sort(toSort, 5);

    for(int i = 0; i<5; i++) {
        cout << toSort[i] << endl;
    }

    double* toSort2 = new double[5];
    for(int i=4; i>=0; i--) {
        toSort2[i] = i+0.5;
    }

    sort(toSort2, 5);

    for(int i = 0; i<5; i++) {
        cout << toSort2[i] << endl;
    }

    return 0;
}
