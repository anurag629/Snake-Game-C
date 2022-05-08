#include <stdio.h>
#include "header.h"

Node *findNode(int snakerow, int snakecol, char *snakeicon, Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->r == snakerow && ptr->c == snakecol && ptr->icon == snakeicon)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
}