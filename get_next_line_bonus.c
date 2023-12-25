/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:34:11 by het-taja          #+#    #+#             */
/*   Updated: 2023/12/25 23:58:07 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strnlen(const char *save)
{
	int	i;

	i = 0;
	while (save && save[i] && save[i] != '\n')
		i++;
	if (save && save[i] == '\n')
		i++;
	return (i);
}

char	*first_line(char *str, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!check_new(str) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*static_modify(char *s)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strnlen(s);
	if (!s[len])
	{
		free(s);
		return (NULL);
	}
	str = malloc(ft_strlen(s) - len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[len])
		str[i++] = s[len++];
	str[i] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*returned;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = first_line(line[fd], fd);
	if (!line[fd])
		returned = NULL;
	else
		returned = ft_strdup(line[fd]);
	line[fd] = static_modify(line[fd]);
	return (returned);
}

int main()
{
	int fd;
	char *line;


	fd = open("sss.txt",  O_RDONLY);
	line = get_next_line(fd);
	printf("get next :%s", line);
		free(line);
	line = get_next_line(fd);
	printf("get next2 :%s", line);
		free(line);
	line = get_next_line(fd);
	printf("get next3 :%s.", line);
	free(line);
	close(fd);
	return (0);
}