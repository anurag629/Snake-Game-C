# move.c

## Code :

    #include <stdio.h>
    #include <stdlib.h>
    #include "header.h"

    void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize, int UNBEATABLE)
    {
        if (border[head[0]][head[1]] == '>')
        {
            if (border[head[0]][head[1] + 1] == '*')
            {
                printf("CAN NOT MOVE INSIDE WALL.....\n");
            }
            else if ((border[head[0]][head[1] + 1] == '-' || border[head[0]][head[1] + 1] == '|' || border[head[0]][head[1] + 1] == '#') && UNBEATABLE == 0)
            {
                printf("You lose :(\n");
                exit(0);
            }
            else if (border[head[0]][head[1] + 1] == '@')
            {
                printf("You win! :)\n");
                exit(0);
            }
            else
            {
                border[head[0]][head[1] + 1] = '>';
                border[head[0]][head[1]] = '-';
                head[1] = head[1] + 1;
                for (int i = 0; i < snakeSize - 1; i++)
                {
                    snakePosition[i] = snakePosition[i + 1];
                }
                snakePosition[snakeSize - 1] = (head[0] * width) + head[1];
                tailRemove(height, width, border, food, input, head, tail, snakePosition, snakeSize);
            }
        }
        if (border[head[0]][head[1]] == '<')
        {
            if (border[head[0]][head[1] - 1] == '*')
            {
                printf("CAN NOT MOVE INSIDE WALL.....\n");
            }
            else if ((border[head[0]][head[1] - 1] == '-' || border[head[0]][head[1] - 1] == '|' || border[head[0]][head[1] - 1] == '#') && UNBEATABLE == 0)
            {
                printf("You lose :(\n");
                exit(0);
            }
            else if (border[head[0]][head[1] - 1] == '@')
            {
                printf("You win! :)\n");
                exit(0);
            }
            else
            {
                border[head[0]][head[1] - 1] = '<';
                border[head[0]][head[1]] = '-';
                head[1] = head[1] - 1;
                for (int i = 0; i < snakeSize - 1; i++)
                {
                    snakePosition[i] = snakePosition[i + 1];
                }
                snakePosition[snakeSize - 1] = head[0] * width + head[1];
                tailRemove(height, width, border, food, input, head, tail, snakePosition, snakeSize);
            }
        }
        if (border[head[0]][head[1]] == '^')
        {
            if (border[head[0] - 1][head[1]] == '*')
            {
                printf("CAN NOT MOVE INSIDE WALL.....\n");
            }
            else if ((border[head[0] - 1][head[1]] == '-' || border[head[0] - 1][head[1]] == '|' || border[head[0] - 1][head[1]] == '#') && UNBEATABLE == 0)
            {
                printf("You lose :(\n");
                exit(0);
            }
            else if (border[head[0] - 1][head[1]] == '@')
            {
                printf("You win! :)\n");
                exit(0);
            }
            else
            {
                border[head[0] - 1][head[1]] = '^';
                border[head[0]][head[1]] = '|';
                head[0] = head[0] - 1;
                for (int i = 0; i < snakeSize - 1; i++)
                {
                    snakePosition[i] = snakePosition[i + 1];
                }
                snakePosition[snakeSize - 1] = (head[0]) * width + head[1];
                tailRemove(height, width, border, food, input, head, tail, snakePosition, snakeSize);
            }
        }
        if (border[head[0]][head[1]] == 'v')
        {
            if (border[head[0] + 1][head[1]] == '*')
            {
                printf("CAN NOT MOVE INSIDE WALL.....\n");
            }
            else if ((border[head[0] + 1][head[1]] == '-' || border[head[0] + 1][head[1]] == '|' || border[head[0] + 1][head[1]] == '#') && UNBEATABLE == 0)
            {
                printf("You lose :(\n");
                exit(0);
            }
            else if (border[head[0] + 1][head[1]] == '@')
            {
                printf("You win! :)\n");
                exit(0);
            }
            else
            {
                border[head[0] + 1][head[1]] = 'v';
                border[head[0]][head[1]] = '|';
                head[0] = head[0] + 1;
                for (int i = 0; i < snakeSize - 1; i++)
                {
                    snakePosition[i] = snakePosition[i + 1];
                }
                snakePosition[snakeSize - 1] = (head[0]) * width + head[1];
                tailRemove(height, width, border, food, input, head, tail, snakePosition, snakeSize);
            }
        }
    }



* this file contains move function.
* it checks following things:
    
    * it cannont pass the border of 2D box
    * it cannot move backword
    * if snake eats food then game will be win
    * if checks contion of UNBEATABLE 
    * if conditions of UBEATABLE is not there then snake will not die.
    
* this function also corrects the correct position of snake in 2D box.
* this function calls the tailRemove() function to corrects the position of tail at its appropriate positon.
