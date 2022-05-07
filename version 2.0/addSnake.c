#include <stdio.h>
#include "header.h"

void addSnake(int snakerow, int snakecol, char *snakeicon, Node *start)
{
    if (start->next == NULL)
    {
        Node *newnode = make_node(snakerow, snakecol, *snakeicon, NULL);
        start->next = newnode;
    }
    else
    {
        Node *newnode = make_node(snakerow, snakecol, *snakeicon, start);
        start->next = newnode;
    }
}