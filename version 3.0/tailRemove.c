// int iterateSnakePosition(int *snakeSize, int *snakePosition, int check)
// {
//     for (int i = 0; i < *snakeSize; i++)
//     {
//         if (snakePosition[0] == check)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
// }

void tailRemove(int height, int width, char *border[], int food[], char input, int head[], int tail[], int *snakePosition, int *snakeSize)
{

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                border[i][j] = '*';
            }
            // if (iterateSnakePosition(snakeSize, snakePosition, i * width + j) == 0)
            // {
            //     border[i][j] == '0';
            // }
        }
    }
}
