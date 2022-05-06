#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

const char *filename = "check.txt";

int main(int argc, char *argv[])
{
    FILE *in_file = fopen(filename, "r");
    if (!in_file)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(filename, &sb) == -1)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char *file_contents = malloc(sb.st_size);

    while (fscanf(in_file, "%[^\n ] ", file_contents) != EOF)
    {
        // printf("> %s\n", file_contents);
        char *ll = file_contents;
        printf("%s\n", ll);
    }

    fclose(in_file);
    exit(EXIT_SUCCESS);
}