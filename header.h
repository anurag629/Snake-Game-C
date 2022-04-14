#ifndef MY_HEADER
#define MY_HEADER

void getSize(int r, int c, int snakeSize);
void draw(int height, int width, char *border[], int *snakePosition);
void input(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int snakeSize);
int *getarray(int a[], int snakeSize);
void position(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize);
void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize);
void tailRemove(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int snakeSize);

#endif
