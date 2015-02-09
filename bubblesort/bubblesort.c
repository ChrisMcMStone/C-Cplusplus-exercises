#include <stdio.h>
#include <stdlib.h>

void sort(int *toSort, int arraySize) {

    int i, j, temp;
    for(i=0; i<arraySize; i++) {
        for(j=0; j<arraySize-i-1; j++) {
            if(toSort[j] > toSort[j+1]) {
                temp = toSort[j];
                toSort[j] = toSort[j+1];
                toSort[j+1] = temp;
            }
        }
    }
}

int main(int argc, char **argv) {

    if(argc==1) {
        return 0;
    }
    int i;
    int *toSort = (int *)malloc(sizeof(int) * (argc-1));
    for(i=0; i<argc-1; i++) {
        toSort[i] = *argv[i+1] - '0';
    }

    sort(toSort, argc-1);

    for(i=0; i<argc-1; i++) {
        printf("%d, ", toSort[i]);
    }
    printf("\n");
    free(toSort);

    return 0;

}
