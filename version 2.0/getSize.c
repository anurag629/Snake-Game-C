#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

// const char *filename = "check.txt";
#include "header.h"
#include "header_s.h"

void getSize(const char *filename, int foodcount)
{
    int r, c, snakeSize = 0, snakeSizee = 0;

    // Node *start = make_node(0, 0, '0', NULL);
    // struct Node *start = NULL;
    struct Node *start = (struct Node *)malloc(sizeof(struct Node));
    start = NULL;

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
                snakerow = atoi(ll);
                flag = flag + 1;
            }
            else if (flag % 3 == 2)
            {
                snakecol = atoi(ll);
                flag = flag + 1;
            }
            else if (flag % 3 == 0)
            {
                // printf("%c\n", *ll);
                snakeicon = *ll;

                flag = flag + 1;
                addSnake(snakerow, snakecol, snakeicon, start);
                snakeSize = snakeSize + 1;
            }
        }
    }

    fclose(in_file);
    // Closing file

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

    // TwoDBox[1][1] = '#';
    // TwoDBox[1][snakeSize] = '>';
    // snakePosition[0] = 1 * c + 1;
    // snakePosition[snakeSize - 1] = 1 * c + snakeSize;

    // for (int j = 1; j < snakeSize; j++)
    // {
    //     TwoDBox[1][j] = '-';
    // }
    // for (int j = 0; j < snakeSize; j++)
    // {
    //     snakePosition[j] = 1 * c + j + 1;
    // }

    // start reading
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
                addSnake(snakerow, snakecol, snakeicon, start);
                TwoDBox[snakerow + 1][snakecol + 1] = snakeicon;
                snakePosition[snakeSizee] = (snakerow + 1) * snakecol + snakeSizee + 1;
                snakeSizee = snakeSizee + 1;
            }
        }
    }

    fclose(in_filee);
    // End Reading file

    // struct Node *ptr = start;
    // struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // ptr = start;
    // int pp = 0;
    // while (ptr != NULL)
    // {
    //     TwoDBox[ptr->r + 1][ptr->c + 1] = ptr->icon;
    //     printf("%c", TwoDBox[ptr->r + 1][ptr->c + 1]);
    //     snakePosition[pp] = (ptr->r + 1) * c + pp;
    //     ptr = ptr->next;
    //     pp = pp + 1;

    // }

    int rc[] = {r, c};
    srand(time(0));
    int *food = getarray(rc, snakeSize);

    TwoDBox[food[0]][food[1]] = '@';

    draw(r, c, TwoDBox, snakePosition);

    int head[2] = {1, snakeSize};
    int tail[2] = {1, 1};

    input(r, c, TwoDBox, food, head, tail, snakePosition, snakeSize);
    /* Code for further processing and free the
      dynamically allocated memory */
    for (int i = 0; i < r; i++)
        free(TwoDBox[i]);

    free(snakePosition);
    free(food);
}