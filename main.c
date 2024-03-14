#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("res",O_RDONLY);
	char *sol1 =get_next_line(fd);
	if(sol1)
	{
		printf("%s\n",sol1);
		free(sol1);
	}
	int fd2 = open("re",O_RDONLY);
	char *sol2 =get_next_line(fd2);
	if(sol2)
	{
		printf("%s\n",sol2);
		free(sol2);
	}
    return 0;
}	