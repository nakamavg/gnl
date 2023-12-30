#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int main(void)
{
    int fd[3];
    char *line;
    char *files[3] = {"test.txt", "test2.txt", "test3.txt"};

    for (int i = 0; i < 3; i++)
    {
        fd[i] = open(files[i], O_RDONLY);
        if (fd[i] == -1)
        {
            printf("Error al abrir el archivo %s\n", files[i]);
            return (1);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Leyendo el archivo %s:\n", files[i]);
        while ((line = get_next_line(fd[i])) != NULL)
        {
            printf("%s\n", line);
            free(line);
        }
        close(fd[i]);
    }

    return (0);
}