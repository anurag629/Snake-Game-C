#include <stdio.h>

void move(int height, int width, char *border[], int food[], char input, int head[], int tail[])
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
        }
    }
}