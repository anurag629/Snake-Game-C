#include <stdio.h>
#include <stdlib.h>
#include <termios.h> //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>
#include "header.h"

void input(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int snakeSize)
{
    char key;

    static struct termios oldt, newt;

    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr(STDIN_FILENO, &oldt);
    /*now the settings will be copied*/
    newt = oldt;
    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON);

    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((key = getchar()))
    {

        switch (key)
        {
        case 'a':
            draw(height, width, border, snakePosition);
            position(height, width, border, food, '<', head, tail, snakePosition, snakeSize);
            printf("a Pressed\n");

            break;
        case 's':
            draw(height, width, border, snakePosition);
            position(height, width, border, food, 'v', head, tail, snakePosition, snakeSize);
            printf("s Pressed\n");

            break;
        case 'd':
            draw(height, width, border, snakePosition);
            position(height, width, border, food, '>', head, tail, snakePosition, snakeSize);
            printf("d Pressed\n");

            break;
        case 'w':
            draw(height, width, border, snakePosition);
            position(height, width, border, food, '^', head, tail, snakePosition, snakeSize);
            printf("w Pressed\n");

            break;
        default:
            draw(height, width, border, snakePosition);
            printf("Wrong Key Pressed. Press from (w : up | s : down | a : left | d : right)\n");

            break;
        }
    }

    /*restore the old settings*/
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
