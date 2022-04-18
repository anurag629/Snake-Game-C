# checkPosition.c

## Code :

    #include <stdio.h>
    #include "header.h"

    void position(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize, int UNBEATABLE)
    {
        if (input == '>')
        {
            if (border[head[0]][head[1] + 1] == '-')
            {
                printf("CAN NOT MOVE BACKWORD.....\n");
            }
            else if (border[head[0]][head[1]] == input)
            {
                move(height, width, border, food, '>', head, tail, snakePosition, snakeSize, UNBEATABLE);
            }
            else
            {
                border[head[0]][head[1]] = input;
            }
        }
        else if (input == '<')
        {
            if (border[head[0]][head[1] - 1] == '-')
            {
                printf("CAN NOT MOVE BACKWORD.....\n");
            }
            else if (border[head[0]][head[1]] == input)
            {
                move(height, width, border, food, '<', head, tail, snakePosition, snakeSize, UNBEATABLE);
            }
            else
            {
                border[head[0]][head[1]] = input;
            }
        }
        else if (input == '^')
        {
            if (border[head[0] - 1][head[1]] == '|')
            {
                printf("CAN NOT MOVE BACKWORD.....\n");
            }
            else if (border[head[0]][head[1]] == input)
            {
                move(height, width, border, food, '^', head, tail, snakePosition, snakeSize, UNBEATABLE);
            }
            else
            {
                border[head[0]][head[1]] = input;
            }
        }
        else if (input == 'v')
        {
            if (border[head[0] + 1][head[1]] == '|')
            {
                printf("CAN NOT MOVE BACKWORD.....\n");
            }
            else if (border[head[0]][head[1]] == input)
            {
                move(height, width, border, food, 'v', head, tail, snakePosition, snakeSize, UNBEATABLE);
            }
            else
            {
                border[head[0]][head[1]] = input;
            }
        }
    }


* this file contains position function which checks current direction(mouth) of snake and accordengly changes the position of mouth of snake i.e., if current position of snake is '>' and we pressed 's' then its position changes to 'v'.
* and if current position of snake is '>' and we pressed 'd'('>') then it call the function move which moves the snake to one position forward.
