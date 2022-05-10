#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int agrc, char const *argv[])
{
    // if (atoi(argv[1]) == 1)
    // {
    //     getSize(30, 60, 25);
    // }

    // else if (agrc != 4)
    // {                    // then invalid number of parameters
    //     system("clear"); /*clear output screen*/
    //     printf("incorrect amount of arguments. Program usage:\n./snake <row_map> <col_map> <snake_length>\n");
    // }
    // else if (atoi(argv[3]) + 2 >= atoi(argv[2]))
    // {
    //     printf("Enter valid argument\n");
    // }
    // else
    // {
    //     getSize(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    // }

    if (agrc != 3)
    {                    // then invalid number of parameters
        system("clear"); /*clear output screen*/
        printf("incorrect amount of arguments. Program usage:\n./snake <snake_file_name> <food_amount_to_win>\n");
    }
    else
    {
        getSize(argv[1], atoi(argv[2]));
    }

    return 0;
}