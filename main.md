# main.c

## Code :

    #include <stdio.h>
    #include <stdlib.h>
    #include "header.h"

    int main(int agrc, char const *argv[])
    {
        if (atoi(argv[1]) == 1)
        {
            getSize(30, 60, 25, 1);
        }

        else if (agrc != 4)
        {                    // then invalid number of parameters
            system("clear"); /*clear output screen*/
            printf("incorrect amount of arguments. Program usage:\n./snake <row_map> <col_map> <snake_length>\n");
        }
        else if (atoi(argv[3]) + 2 >= atoi(argv[2]))
        {
            printf("Enter valid argument\n");
        }
        else
        {
            getSize(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), 0);
        }

        return 0;
    }

* this file contains main function which accepts two arguments argc and argv[]
* argc contains total number of argument passes in main file 
* argv[] contains all the arguments passed in the main file
* when we run command './snake 30 45 15' the value of argv is 4 and values in argc[] = {"./snake", "30", "45", "15"}
* also main function checks weather number of arguments passed are correct or not i.e., row, column and length of snake all are passed or not.
