#include <stdio.h>

int main(int argc, char** argv)
{
    int i = 5;
    int* pi = &i;
    int** ppi = &pi;
    printf("%d\n", **ppi);

    return 0;
}
