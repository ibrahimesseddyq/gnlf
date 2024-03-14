#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define NL '\n'
//#define BUFFER_SIZE 5

#include <limits.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char		*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *dest, char *src);
char		*ft_strcpy(char *dest, const char *src);
size_t	ft_strlen(const char *str);
char		*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *src);
#endif