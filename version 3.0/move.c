#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int *snakeSize, int *UNBEATABLE, int countFood)
{
    if (border[head[0]][head[1]] == '>')
    {
        if (border[head[0]][head[1] + 1] == '*')
        {
            printf("CAN NOT MOVE INSIDE WALL.....\n");
        }
        else if ((border[head[0]][head[1] + 1] == '-' || border[head[0]][head[1] + 1] == '|' || border[head[0]][head[1] + 1] == '#'))
        {
            printf("\nYou lose :(\n");
            exit(0);
        }
        else if (*UNBEATABLE == countFood)
        {
            printf("\nYou win :)\n");
            exit(0);
        }
        else if (border[head[0]][head[1] + 1] == '@')
        {
            *UNBEATABLE = *UNBEATABLE + 1;
            border[head[0]][head[1] + 1] = '0';
            int rc[] = {height, width};
            srand(time(0));
            int *food = getarray(rc, *snakeSize);

            border[food[0]][food[1]] = '@';
            *snakeSize = *snakeSize + 1;
            snakePosition[*snakeSize] = snakePosition[*snakeSize - 1] + 1;
        }
        else
        {
            border[head[0]][head[1] + 1] = '>';
            border[head[0]][head[1]] = '-';
            head[1] = head[1] + 1;
            for (int i = 0; i < *snakeSize - 1; i++)
            {
                snakePosition[i] = snakePosition[i + 1];
                printf("%d\n", snakePosition[i]);
            }
            snakePosition[*snakeSize - 1] = (head[0] * width) + head[1];
            printf("%d\n", snakePosition[*snakeSize - 1]);
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
            printf("\nYou lose :(\n");
            exit(0);
        }
        else if (*UNBEATABLE == countFood)
        {
            printf("\nYou win :)\n");
            exit(0);
        }
        else if (border[head[0]][head[1] - 1] == '@')
        {
            *UNBEATABLE = *UNBEATABLE + 1;
            border[head[0]][head[1] - 1] = '0';
            int rc[] = {height, width};
            srand(time(0));
            int *food = getarray(rc, *snakeSize);

            border[food[0]][food[1]] = '@';
            *snakeSize = *snakeSize + 1;
        }
        else
        {
            border[head[0]][head[1] - 1] = '<';
            border[head[0]][head[1]] = '-';
            head[1] = head[1] - 1;
            for (int i = 0; i < *snakeSize - 1; i++)
            {
                snakePosition[i] = snakePosition[i + 1];
            }
            snakePosition[*snakeSize - 1] = head[0] * width + head[1];
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
            printf("\nYou lose :(\n");
            exit(0);
        }
        else if (*UNBEATABLE == countFood)
        {
            printf("\nYou win :)\n");
            exit(0);
        }
        else if (border[head[0] - 1][head[1]] == '@')
        {
            *UNBEATABLE = *UNBEATABLE + 1;
            border[head[0] - 1][head[1]] = '0';
            int rc[] = {height, width};
            srand(time(0));
            int *food = getarray(rc, *snakeSize);

            border[food[0]][food[1]] = '@';
            *snakeSize = *snakeSize + 1;
        }
        else
        {
            border[head[0] - 1][head[1]] = '^';
            border[head[0]][head[1]] = '|';
            head[0] = head[0] - 1;
            for (int i = 0; i < *snakeSize - 1; i++)
            {
                snakePosition[i] = snakePosition[i + 1];
            }
            snakePosition[*snakeSize - 1] = (head[0]) * width + head[1];
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
            printf("\nYou lose :(\n");
            exit(0);
        }
        else if (*UNBEATABLE == countFood)
        {
            printf("\nYou win :)\n");
            exit(0);
        }
        else if (border[head[0] + 1][head[1]] == '@')
        {
            *UNBEATABLE = *UNBEATABLE + 1;
            border[head[0] + 1][head[1]] = '0';
            int rc[] = {height, width};
            srand(time(0));
            int *food = getarray(rc, *snakeSize);

            border[food[0]][food[1]] = '@';
            *snakeSize = *snakeSize + 1;
        }
        else
        {
            border[head[0] + 1][head[1]] = 'v';
            border[head[0]][head[1]] = '|';
            head[0] = head[0] + 1;
            for (int i = 0; i < *snakeSize - 1; i++)
            {
                snakePosition[i] = snakePosition[i + 1];
            }
            snakePosition[*snakeSize - 1] = (head[0]) * width + head[1];
            tailRemove(height, width, border, food, input, head, tail, snakePosition, snakeSize);
        }
    }
}