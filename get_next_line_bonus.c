#include "get_next_line_bonus.h"

char *get_line(int fd, char *save)
{
	int	str_count;
	char	*buffer;
	
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 2);
	if (!buffer)
		return (NULL);
	str_count = 1;
	buffer[0] = '\0';
	while (str_count != 0 && !ft_strchr(buffer, '\n'))
	{
		str_count = read(fd, buffer, BUFFER_SIZE);
		if (str_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[str_count] = '\0';
		save = ft_strjoin(save, buffer); 
	}
	free(buffer);
	return(save);
}

char *cut_line(char *save)
{
	char *line;
	int goodlen;
	int i;
	
	goodlen = 0;
	if (!save[goodlen])
		return (NULL);
	while (save[goodlen] && save[goodlen] != '\n')
		goodlen++;
	line = (char *)malloc(sizeof(char) * (goodlen + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++; 
	}
	line[i] = '\0';
	return (line);
}

char *rest(char *save)
{
	int goodlen;
	char *rest;
	int i;
	
	goodlen = 0;
	while (save[goodlen] && save[goodlen] != '\n')
		goodlen++;
	if (save[goodlen] == 0)
	{
		free (save);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(save) - goodlen) + 1);
	if (!rest)
		return (NULL);
	i = 0;
	goodlen++;
	while (save[goodlen])
		rest[i++] = save[goodlen++];
	rest[i] = '\0';
	free(save);
	return(rest);
}

char *get_next_line(int fd)
{
	char *line;
	static char *save[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	save[fd] = get_line(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = cut_line(save[fd]);
	save[fd] = rest(save[fd]);
	return(line);
}
