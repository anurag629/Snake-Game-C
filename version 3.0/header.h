#ifndef MY_HEADER
#define MY_HEADER

// void addSnake(int snakerow, int snakecol, char snakeicon, struct Node *start);
void getSize(const char *filename, int countFood);
// void getSize(int r, int c, int snakeSiz);
void draw(int height, int width, char *border[], int *snakePosition, int *UNBEATABLE);
void input(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int *snakeSize, int *UNBEATABLE, int countFood);
int *getarray(int a[], int snakeSize);
void position(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int *snakeSize, int *UNBEATABLE, int countFood);
void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int *snakeSize, int *UNBEATABLE, int countFood);
void tailRemove(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int *snakeSize);

// extra

#endif
