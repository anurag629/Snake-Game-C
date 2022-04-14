#include <stdio.h>
#include "header.h"

void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize)
{
    if (border[head[0]][head[1]] == '>')
    {
        if (border[head[0]][head[1] + 1] == '*')
        {
            printf("CAN NOT MOVE INSIDE WALL.....\n");
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
            snakePosition[snakeSize - 1] = head[0] * width + head[1] + 1;
            tailRemove(height, width, border, food, head, tail, snakePosition, snakeSize);
        }
    }
    if (border[head[0]][head[1]] == '<')
    {
        if (border[head[0]][head[1] - 1] == '*')
        {
            printf("CAN NOT MOVE INSIDE WALL.....\n");
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
            snakePosition[snakeSize - 1] = head[0] * width + head[1] - 1;
            tailRemove(height, width, border, food, head, tail, snakePosition, snakeSize);
        }
    }
    if (border[head[0]][head[1]] == '^')
    {
        if (border[head[0] - 1][head[1]] == '*')
        {
            printf("CAN NOT MOVE INSIDE WALL.....\n");
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
            snakePosition[snakeSize - 1] = (head[0] - 1) * width + head[1];
            tailRemove(height, width, border, food, head, tail, snakePosition, snakeSize);
        }
    }
    if (border[head[0]][head[1]] == 'v')
    {
        if (border[head[0] + 1][head[1]] == '*')
        {
            printf("CAN NOT MOVE INSIDE WALL.....\n");
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
            snakePosition[snakeSize - 1] = (head[0] + 1) * width + head[1];
            tailRemove(height, width, border, food, head, tail, snakePosition, snakeSize);
        }
    }
    for (int i = 0; i < snakeSize; i++)
    {
        printf("%d ", snakePosition[i]);
    }
}