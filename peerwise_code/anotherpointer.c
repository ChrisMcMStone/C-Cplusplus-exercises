#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[3] = {5,7,9};

    int *p = a;

    // Missing Code Start
    p = (a+1);
    // Missing Code End
    printf("%d",*p);
    return 0;

}
