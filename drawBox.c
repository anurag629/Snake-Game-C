#include <stdlib.h>
#include <stdio.h>

void draw(int height, int width, char *border[], int *snakePosition)
{
    printf("\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (border[i][j] == '*')
            {
                printf("*");
            }

            else if (border[i][j] != '0')
            {
                if (border[i][j] == '#')
                {
                    printf("#");
                }
                else if (border[i][j] == '>' || border[i][j] == '^' || border[i][j] == '<' || border[i][j] == 'v')
                {
                    if (border[i][j] == '>')
                        printf(">");
                    else if (border[i][j] == '^')
                        printf("^");
                    else if (border[i][j] == '<')
                        printf("<");
                    else
                        printf("v");
                }
                else if (border[i][j] == '@')
                {
                    printf("@");
                }
                else if (border[i][j] == '-')
                {
                    printf("-");
                }
                else if (border[i][j] == '|')
                {
                    printf("|");
                }
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// int main()
// {
//     int arr[2] = {4, 3};
//     int border[13][14];
//     for (int i = 0; i < 13; i++)
//         for (int j = 0; j < 14; j++)
//             border[i][j] = 0;

//     border[1][1] = 2;
//     border[1][6] = 3;

//     for (int j = 2; j < 6; j++)
//         border[1][j] = 1;
//     draw(13, 14, border, arr);
// }