#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int is1;
	int is2;
	int total_len;
	char *total_str;
	
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) + 1);
		s1[0] = '\0';
	}
	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	total_len = is1 + is2;
	total_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (total_str == NULL)
		return (NULL);
	i = 0;
	while (i <= is1)
	{
		total_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= is2 && i <= (int)ft_strlen(s2))
		total_str[is1++] = s2[i++];
	free(s1);
	return (total_str);
}

char	*ft_strchr(char *str, int c)
{
	int i;
	char ch;

	i = 0;
	ch = c;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
