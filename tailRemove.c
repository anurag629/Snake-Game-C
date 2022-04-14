void tailRemove(int height, int width, char *border[], int food[], int head[], int tail[], int *snakePosition, int snakeSize)
{
    int h = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (border[i][j] == '#')
            {
                border[i][j] = '0';
            }
            if (snakePosition[0] == i * width + j)
            {
                border[i][j] = '#';
            }
        }
    }
}