#include "./../get_next_line.h"

void giant()
{
    int fd = open("gianine_nl.txt",O_RDONLY);
    char *c = get_next_line(fd);
    printf("Exspected :[a...] , got[%s]",c);
    free(c);
}