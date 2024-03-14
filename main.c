#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("res",O_RDONLY);
	printf("%s\n",
	get_next_line(fd)
	);
    return 0;
}	