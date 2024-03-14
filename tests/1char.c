#include "./../get_next_line.h"

void one_char()
{
    int fd = open("1char.txt",O_RDONLY);
    char *c = get_next_line(fd);
    printf("Exspected :[a] , got[%s]",c);
    free(c);
}