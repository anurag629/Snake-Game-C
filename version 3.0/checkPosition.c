#include <stdio.h>
#include "header.h"

void position(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int *snakeSize, int *UNBEATABLE, int countFood)
{
    if (input == '>')
    {
        if (border[head[0]][head[1] + 1] == '-')
        {
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if (border[head[0]][head[1]] == input)
        {
            move(height, width, border, food, '>', head, tail, snakePosition, snakeSize, UNBEATABLE, countFood);
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
            move(height, width, border, food, '<', head, tail, snakePosition, snakeSize, UNBEATABLE, countFood);
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
            move(height, width, border, food, '^', head, tail, snakePosition, snakeSize, UNBEATABLE, countFood);
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
            move(height, width, border, food, 'v', head, tail, snakePosition, snakeSize, UNBEATABLE, countFood);
        }
        else
        {
            border[head[0]][head[1]] = input;
        }
    }
}