#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *sol1 =get_next_line(0);
	if(sol1)
	{
		printf("%s",sol1);
		free(sol1);
	}
	// int fd2 = open("re",O_RDONLY);
	// char *sol2 =get_next_line(fd2);
	// if(sol2)
	// {
	// 	printf("%s",sol2);
	// 	free(sol2);
	// }
	// char *sol3 =get_next_line(fd);
	// if(sol1)
	// {
	// 	printf("%s",sol3);
	// 	free(sol3);
	// }
    return 0;
}	