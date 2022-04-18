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