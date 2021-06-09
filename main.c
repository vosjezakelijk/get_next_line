#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int k;
    char *line;
    int fd;

    k = 1;
    fd = open("text.txt", O_RDONLY);
    //fd = 0; //for manual input
    while (k == 1)
    {
        k = get_next_line(fd, &line);
        printf("'%d\n", k);
        printf("'%s\n", line);
    }
    free(line);
    return (0);
}