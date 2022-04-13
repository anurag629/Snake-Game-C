#ifndef MY_HEADER
#define MY_HEADER

void getSize(int r, int c, int snakeSize);
void draw(int height, int width, char *border[]);
void input(int height, int width, char *border[], int food[], int head[], int tail[]);
int *getarray(int a[], int snakeSize);
void position(int height, int width, char *border[], int food[], char input, int head[], int tail[]);

#endif
