#include "./../get_next_line.h"

void onenl()
{
    int fd = open("only_nl.txt",O_RDONLY);
    char *c = get_next_line(fd);
    printf("Exspected :[\n] , got[%s]",c);
    free(c);
}