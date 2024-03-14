#include "./../get_next_line.h"

void multiple()
{
    int fd = open("multiple_nl.txt",O_RDONLY);
    char *c = get_next_line(fd);
    printf("Exspected :[\n] , got[%s]",c);
    free(c);
}