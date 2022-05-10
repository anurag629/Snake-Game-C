#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "header_s.h"

void addSnake(int snakerow, int snakecol, char snakeicon, struct Node *start)
{
    if (start == NULL)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        // Node *newnode = make_node(snakerow, snakecol, *snakeicon, NULL);
        newnode->r = snakerow;
        newnode->c = snakecol;
        newnode->icon = snakeicon;
        newnode->next = NULL;
        start = newnode;

        // printf("%d", newnode->r);
        // printf("%d", newnode->c);
        // printf("%c", newnode->icon);
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        // Node *newnode = make_node(snakerow, snakecol, *snakeicon, start);
        newnode->r = snakerow;
        newnode->c = snakecol;
        newnode->icon = snakeicon;
        newnode->next = start;
        start = newnode;

        // printf("%d", newnode->r);
        // printf("%d", newnode->c);
        // printf("%c", newnode->icon);
    }
}