#include <stdlib.h>
#include <stdio.h>

void draw(int height, int width, char *border[], int *snakePosition)
{

    system("clear"); /*clear output screen*/
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
