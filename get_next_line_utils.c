#include "get_next_line.h"
char	*ft_strchr(const char *s, int c)
{
	while (s && *s != '\0')
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char    *ft_strcpy(char *s1, const char *s2)
  {
      int i;
 
      i = 0;
    if (s1 && s2) 	
	{ 
		while (s2[i])
    {
        s1[i] = s2[i]; // so this will make s1 = to whatever s2 is looping through the string
        i++;
    }
    s1[i] = s2[i];}  // now that we are finsihing looping though s1[i] will equal s2[i]
    return (s1);
  }
char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strjoin(char *dest, char *src)
{
	size_t dest_len;
	size_t src_len;
	char	*new_str;
	size_t		i;
	size_t		j;

	if (dest)
		dest_len = ft_strlen(dest);
	else
		dest_len = 0;
	if(src)
		src_len = ft_strlen(src);
	else
		src_len = 0;
	i = 0;
	j = 0;
	new_str = malloc(dest_len + src_len + 1);
	if(!new_str)
		return (NULL);
	while(i < dest_len)
	{
		new_str[i] = dest[i];
		i++;
	}
	while(j < src_len)
	{
		new_str[i + j] = src[j];
		j++;
	}
	new_str[i + j] = 0;
	return (new_str);
}
char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while ((i < start + len) && start <= ft_strlen(s) && s[i])
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while ( str && str[i])
		i++;
	return (i);
}



