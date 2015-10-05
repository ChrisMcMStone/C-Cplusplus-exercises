#include <stdlib.h>


int (*ptr)() {

    return (int*)malloc(sizeof(int) * 4);

}

int main() {

    int *(*ptr)()[4]; 
    return 0;
}
