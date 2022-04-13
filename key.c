#include <stdio.h>
#include <stdlib.h>
#include <termios.h> //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>
#include "header.h"

void input(int height, int width, char *border[], int food[], int head[], int tail[])
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
        system("clear"); /*clear output screen*/
        switch (key)
        {
        case 'a':
            position(height, width, border, food, '<', head, tail);
            draw(height, width, border);
            printf("a pressed");
            break;
        case 's':
            position(height, width, border, food, 'v', head, tail);
            draw(height, width, border);
            printf("s pressed");
            break;
        case 'd':
            position(height, width, border, food, '>', head, tail);
            draw(height, width, border);
            printf("d pressed");
            break;
        case 'w':
            position(height, width, border, food, '^', head, tail);
            draw(height, width, border);
            printf("w pressed");
            break;
        default:
            draw(height, width, border);
            printf("wrong key");
            break;
        }
    }

    /*restore the old settings*/
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

