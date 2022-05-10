#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include "header.h"
#include "header_s.h"

void getSize(const char *filename, int countFood)
// void getSize(int r, int c, int snakeSiz)
{

    int head[2];
    int tail[2];
    int r, c, ssnakeSize = 0, snakeSiz = 0;

    int snakerow, snakecol; // variable to store snake position row and column
    char snakeicon;         // variable to store snake icon

    // Opening file

    FILE *in_file = fopen(filename, "r");

    if (!in_file)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(filename, &sb) == -1)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char *file_contents = malloc(sb.st_size);

    int flag = -1;
    while (fscanf(in_file, "%[^\n ] ", file_contents) != EOF)
    {
        // printf("> %s\n", file_contents);
        char *ll = file_contents;
        // printf("%s\n", ll);
        if (flag == -1)
        {
            r = atoi(ll);
            flag = flag + 1;
        }
        else if (flag == 0)
        {
            c = atoi(ll);
            flag = flag + 1;
        }
        else
        {
            if (flag % 3 == 1)
            {
                if (flag == 1)
                {
                    tail[0] = atoi(ll) + 1;
                }
                head[0] = atoi(ll) + 1;
                printf("head[0] is %d", head[0]);
                snakerow = atoi(ll);
                flag = flag + 1;
            }
            else if (flag % 3 == 2)
            {
                if (flag == 2)
                {
                    tail[1] = atoi(ll) + 1;
                }
                head[1] = atoi(ll) + 1;
                snakecol = atoi(ll);
                flag = flag + 1;
            }
            else if (flag % 3 == 0)
            {
                // printf("%c\n", *ll);
                snakeicon = *ll;

                flag = flag + 1;

                ssnakeSize = ssnakeSize + 1;
            }
        }
    }

    fclose(in_file);
    // Closing file

    // backword working
    int foodCount = 0;
    int *UNBEATABLE = &foodCount;
    int *snakeSize = &ssnakeSize;
    char *TwoDBox[r];
    int *snakePosition;
    snakePosition = (int *)malloc(*snakeSize * sizeof(int));

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

    // TwoDBox[1][1] = '#';
    // TwoDBox[1][*snakeSize] = '>';
    // snakePosition[0] = 1 * c + 1;
    // snakePosition[*snakeSize - 1] = 1 * c + *snakeSize;

    // for (int j = 2; j < *snakeSize; j++)
    // {
    //     TwoDBox[1][j] = '-';
    // }
    // for (int j = 1; j < *snakeSize - 1; j++)
    // {
    //     snakePosition[j] = 1 * c + j + 1;
    // }

    // another reading
    FILE *in_filee = fopen(filename, "r");

    if (!in_filee)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct stat sbb;
    if (stat(filename, &sbb) == -1)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char *file_contentss = malloc(sbb.st_size);

    int flagg = -1;
    while (fscanf(in_filee, "%[^\n ] ", file_contentss) != EOF)
    {
        // printf("> %s\n", file_contents);
        char *ll = file_contentss;
        // printf("%s\n", ll);
        if (flagg == -1)
        {
            r = atoi(ll);
            flagg = flagg + 1;
        }
        else if (flagg == 0)
        {
            c = atoi(ll);
            flagg = flagg + 1;
        }
        else
        {
            if (flagg % 3 == 1)
            {
                snakerow = atoi(ll);
                flagg = flagg + 1;
            }
            else if (flagg % 3 == 2)
            {
                snakecol = atoi(ll);
                flagg = flagg + 1;
            }
            else if (flagg % 3 == 0)
            {
                // printf("%c\n", *ll);
                snakeicon = *ll;

                flagg = flagg + 1;
                // printf("%c", snakeicon);
                TwoDBox[snakerow + 1][snakecol + 1] = snakeicon;
                // (head[0]) * width + head[1];
                snakePosition[snakeSiz] = ((snakerow + 1) * (r)) + snakecol + 1;
                printf("%d\n", snakePosition[snakeSiz]);
                snakeSiz = snakeSiz + 1;
            }
        }
    }

    fclose(in_filee);

    // ending another reading
    int rc[] = {r, c};
    srand(time(0));
    int *food = getarray(rc, *snakeSize);

    TwoDBox[food[0]][food[1]] = '@';

    draw(r, c, TwoDBox, snakePosition, UNBEATABLE);

    // int head[2] = {1, *snakeSize};
    // int tail[2] = {1, 1};

    input(r, c, TwoDBox, food, head, tail, snakePosition, snakeSize, UNBEATABLE, 5);
    /* Code for further processing and free the
      dynamically allocated memory */
    for (int i = 0; i < r; i++)
        free(TwoDBox[i]);

    free(snakePosition);
    free(food);
}