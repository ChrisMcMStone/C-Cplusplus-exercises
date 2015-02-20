#include <iostream>
using namespace std;

struct Student {
    int id;
    bool isGrad;
};

int NumGrads(Student sArr[], int size) {
    int noOfGrads;
    for(int i=0; i<size; i++) {
        if(sArr[i].isGrad) noOfGrads++;
    }
    return noOfGrads;
}

int main() {

    return 0;
}
