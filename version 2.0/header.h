#include <stdlib.h>
#include <stdio.h>
#ifndef MY_HEADER
#define MY_HEADER

typedef struct Node
{
    int r;
    int c;
    char icon;
    struct Node *next;
} Node;

Node *make_node(int r, int c, char icon, Node *next);

Node *findNode(int snakerow, int snakecol, char *snakeicon, Node *start);
void addSnake(int snakerow, int snakecol, char *snakeicon, Node *start);

void getSize(const char *filename, int c);
void draw(int height, int width, char *border[], int *snakePosition);
void input(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int snakeSize);
int *getarray(int a[], int snakeSize);
void position(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize);
void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize);
void tailRemove(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize);

#endif
