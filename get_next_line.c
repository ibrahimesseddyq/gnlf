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

int get_length_till_nl(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != NL)
		i++;
	return (i);
}
static char *process_buf_read(char **buf_read, int fd)
{
	char			*ln;
	unsigned int	i;
	char			*ret_buf;
	int				length_till_nl;
	int				complete_length;

	i = 0;
	ln = NULL;
	ret_buf = NULL;
	if (!buf_read[fd] || !(*buf_read[fd]))
		return (NULL);
	complete_length = ft_strlen((*(buf_read + fd)));
	length_till_nl = get_length_till_nl((*(buf_read + fd)));
    if (buf_read[fd][length_till_nl] == NL)
	{
        ln = ft_substr(buf_read[fd], 0, length_till_nl + 1);
    } else
	{
        ln = ft_strdup(buf_read[fd]);
    }
	// printf("\n[[ln] : %s]\n",ln);
	if (length_till_nl < complete_length)
	{
		ret_buf = ft_substr((*(buf_read + fd)), length_till_nl + 1, complete_length - length_till_nl - 1);
		free(buf_read[fd]);
		buf_read[fd] = ret_buf;
	}
	else
	{
		free(*(buf_read + fd));
		*(buf_read + fd) = NULL;
	}
	// printf("test");
	return (ln);
}
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			rd;
	int			has_line;
	char		*temp;
	if ((fd < 0 || fd >= OPEN_MAX) || (BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX) || read(fd, buf, 0) == -1)
		return (NULL);
	static char	*buf_read[OPEN_MAX];
	if (!buf_read[fd])
		buf_read[fd] = ft_strdup("");
	if(!buf_read[fd])
		return (NULL);
	rd = 1;
	has_line = 0;
	while (!has_line && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = 0;
		temp = ft_strjoin(*(buf_read + fd), buf);
		free(buf_read[fd]);
		buf_read[fd] = temp;
		if (ft_strchr(buf_read[fd], NL))
			has_line = 1;
	}
	if (rd < 0)
        return (free(buf_read[fd]), buf_read[fd] = NULL, NULL);
	return (process_buf_read(buf_read, fd));
}
