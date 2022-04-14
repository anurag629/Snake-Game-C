#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"

void getSize(int r, int c, int snakeSize)
{
    char *TwoDBox[r];
    int *snakePosition;
    snakePosition = (int *)malloc(snakeSize * sizeof(int));

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
    snakePosition[0] = 1 * c + 2;
    snakePosition[snakeSize - 1] = 1 * c + snakeSize + 1;

    for (int j = 2; j < snakeSize; j++)
    {
        TwoDBox[1][j] = '-';
    }
    for (int j = 1; j < snakeSize - 1; j++)
    {
        snakePosition[j] = 1 * c + j + 2;
    }

    int rc[] = {r, c};
    srand(time(0));
    int *food = getarray(rc, snakeSize);

    printf("%d ", food[0]);
    printf("%d\n", food[1]);
    TwoDBox[food[0]][food[1]] = '@';

    draw(r, c, TwoDBox, snakePosition);

    int head[2] = {1, snakeSize};
    int tail[2] = {1, 1};

    input(r, c, TwoDBox, food, head, tail, snakePosition);
    /* Code for further processing and free the
      dynamically allocated memory */
    for (int i = 0; i < r; i++)
        free(TwoDBox[i]);

    free(snakePosition);
    free(food);
}