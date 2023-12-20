/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:34:11 by het-taja          #+#    #+#             */
/*   Updated: 2023/12/12 13:34:13 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strndup(char *s, int n)
{
    char *str;
    int i;

    if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
        return (NULL);
    i = 0;
    while (i < n)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *get_next_line(int fd)
{
    char *line;
    char *tmp;
    char *buf;
    static char *save;
    int ret;

    if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || fd > OPEN_MAX)
        return (NULL);
    if (!save)
        save = ft_strnew(0);
    while (!ft_strchr(save, '\n') && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        tmp = ft_strjoin(save, buf);
        free(save);
        save = tmp;
    }
    free(buf);
    if (ret < 0)
        return (NULL);
    line = ft_strchr(save, '\n');
    if (line)
        line = ft_strndup(save, line - save + 1);
    else
        line = ft_strndup(save, ft_strlen(save) + 1);
    tmp = ft_strdup(save + ft_strlen(line));
    free(save);
    save = tmp;
    return (line);
}

int main()
{
    int fd;
    char *line;

    fd = open("ss.txt", O_RDONLY);
    printf("%s",get_next_line(fd));


    close(fd);
    return (0);
}