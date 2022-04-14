#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int agrc, char const *argv[])
{

    if (agrc != 4)
    { // then invalid number of parameters
        printf("Invalid number of argument\n");
    }
    else if (atoi(argv[3]) + 2 >= atoi(argv[2]))
    {
        printf("Enter valid argument\n");
    }
    else
    {
        getSize(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    }

    return 0;
}