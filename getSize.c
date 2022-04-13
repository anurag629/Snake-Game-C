#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"

void getSize(int r, int c, int snakeSize)
{
    char *TwoDBox[r];
    for (int i = 0; i < r; i++)
        TwoDBox[i] = (char *)malloc(c * sizeof(char));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
            {
                TwoDBox[i][j] = '*';
            }
            else
            {
                TwoDBox[i][j] = '0';
            }
        }
    }

    TwoDBox[1][1] = '#';
    TwoDBox[1][snakeSize] = '>';

    for (int j = 2; j < snakeSize; j++)
        TwoDBox[1][j] = '-';

    int rc[] = {r, c};
    srand(time(0));
    int *food = getarray(rc, snakeSize);

    printf("%d ", food[0]);
    printf("%d\n", food[1]);
    TwoDBox[food[0]][food[1]] = '@';

    draw(r, c, TwoDBox);

    int head[2] = {1, snakeSize};
    int tail[2] = {1, 1};

    input(r, c, TwoDBox, food, head, tail);
    /* Code for further processing and free the
      dynamically allocated memory */
    for (int i = 0; i < r; i++)
        free(TwoDBox[i]);

    free(food);
}