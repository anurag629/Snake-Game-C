#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
int *getarray(int a[], int snakeSize)
{
    int xupper = a[0] - 2, yupper = a[1] - 2, xlower = 1, ylower = 1;
    int flag = 1;
    while (flag)
    {
        a[0] = (rand() % (xupper - xlower + 1)) + ylower;
        a[1] = (rand() % (yupper - ylower + 1)) + ylower;
        if (a[0] != 1 && a[0] != 0 && a[1] > snakeSize)
            flag = 0;
    }

    return a;
}
