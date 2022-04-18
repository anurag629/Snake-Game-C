# header.h

## Code :

    #ifndef MY_HEADER
    #define MY_HEADER

    void getSize(int r, int c, int snakeSize, int UNBEATABLE);
    void draw(int height, int width, char *border[], int *snakePosition);
    void input(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int snakeSize, int UNBEATABLE);
    int *getarray(int a[], int snakeSize);
    void position(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize, int UNBEATABLE);
    void move(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize, int UNBEATABLE);
    void tailRemove(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int snakeSize);

    #endif


* this file contains defination of all the function creted for this assignment.

