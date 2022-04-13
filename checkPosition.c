#include <stdio.h>
#include "header.h"

void position(int height, int width, char *border[], int food[], char input, int head[], int tail[])
{
    if (input == '>')
    {
        if (border[head[0]][head[1] + 1] == '-')
        {
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if (border[head[0]][head[1]] == input)
        {
            move(height, width, border, food, '>', head, tail);
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
            move(height, width, border, food, '<', head, tail);
        }
        else
        {
            border[head[0]][head[1]] = input;
        }
    }
    else if (input == '^')
    {
        if (border[head[0] + 1][head[1]] == '|')
        {
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if (border[head[0]][head[1]] == input)
        {
            move(height, width, border, food, '^', head, tail);
        }
        else
        {
            border[head[0]][head[1]] = input;
        }
    }
    else if (input == 'v')
    {
        if (border[head[0] - 1][head[1]] == '|')
        {
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if (border[head[0]][head[1]] == input)
        {
            move(height, width, border, food, 'v', head, tail);
        }
        else
        {
            border[head[0]][head[1]] = input;
        }
    }
}