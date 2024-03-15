/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibes-sed <ibes-sed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:04:21 by ibes-sed          #+#    #+#             */
/*   Updated: 2024/03/14 06:31:08 by ibes-sed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_length_till_nl(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != NL)
		i++;
	if (s[i] == NL)
		i++;
	return (i);
}
static char *get_line(char *str)
{
	char *ln;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if(!*str)
		return (free(str), NULL);
	i = get_length_till_nl(str);
	ln = (char *) malloc(sizeof(char) * i + 1);
	if (!ln)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != NL)
	{
		ln[i] = str[i];
		i++;
	}
	if (str[i] == NL)
	{
		ln[i] = str[i];
		i++;
	}
	ln[i] = 0;
	return (ln);
}
static char *process_line(char *s)
{
	char	*ln;
	size_t	i;
	size_t	j;
	size_t complete_len;

	i = 0;
	j = 0;
	if(!*s)
		return (free(s), NULL);
	complete_len = ft_strlen(s);

	i = get_length_till_nl(s);
	ln = (char *)malloc((complete_len - i) + 1);
	if(!ln)
		return(free(ln), NULL);
	while (str[i])
		ln[j++] = str[i++];
	ln[j] = 0;
	if (!*ln)
		return (free(s),free(ln), NULL);
	free(s);
	return (ln);
}
static char	*cleanup(char *buf, char *buf_read)
{
	free(buf);
	free(buf_read);
	buf_read = NULL;
	return (NULL);
}
char	*get_next_line(int fd)
{
	char		*buf;
	int			rd;
	static char	*buf_read[FD_MAX];

	rd = 1;
	if ((fd < 0 || fd >= FD_MAX) || (BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX) || read(fd, buf, 0) == -1)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buf)
		return (NULL);
	while (!ft_strchr(buf_read[fd], NL) && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (cleanup(buf, buf_read[fd]),NULL);
		buf[rd] = 0;
		buf_read[fd] = ft_strjoin(buf_read[fd], buf);// 6
	}
	free(buf);
	buf = get_line(buf_read[fd]);
	buf_read[fd] = process_line(buf_read[fd]);
	return (buf);
}
