#include "./../get_next_line.h"

void oneline_nonl()
{
    int fd = open("oneline_nonl.txt",O_RDONLY);
    char *c = get_next_line(fd);
    printf("Exspected :[abcde] , got[%s]",c);
    free(c);
}