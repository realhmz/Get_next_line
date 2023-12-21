/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:34:11 by het-taja          #+#    #+#             */
/*   Updated: 2023/12/21 17:20:54 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strndup(char *s)
{
	char *str;
	int i;
	
	if (!s)
		return (NULL);
	
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	
	str[i] = '\0';
	return (str);
}

int	ft_strnlen(char *save)
{
	int	i;

	i = 0;
	while (save && save[i] && save[i] != '\n')
		i++;
	if (save && save[i] == '\n')
		i++;
	return (i);
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

char *get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		buff[BUFFER_SIZE];
	int 		readed;

	readed = 1;
	if (fd < 0)
	{
		return (NULL);
	}
	
		while (!check_new(save) && readed)
		{
			readed = read(fd,buff,BUFFER_SIZE);
			printf("1 ---->%s\n",buff);
			if (readed == -1)
				return (NULL);
			save = ft_strjoin(save,buff);
			printf("save :%s\n",save);
		}
	line = ft_strndup(save);
	save = static_modify(save);
	return(line);
}

int main()
{
	int fd;
	char *line;

	fd = open("sss.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("get next :%s", line);
	line = get_next_line(fd);
	printf("get next2 :%s", line);
	line = get_next_line(fd);
	printf("get next3 :%s.", line);
	free(line);
	close(fd);
	return (0);
}