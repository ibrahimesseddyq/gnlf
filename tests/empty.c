#include "./../get_next_line.h"

void empty()
{
    int fd = open("empty.txt",O_RDONLY);
    char *c = get_next_line(fd);
    printf("Exspected :[] , got[%s]",c);
    free(c);
}